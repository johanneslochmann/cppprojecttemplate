#include "app.hxx"

#include <apps/app/action.hxx>
#include <apps/app/actionforavailabledatabase.hxx>
#include <apps/app/actionforunavailabledatabase.hxx>

#include <QtWidgets/QMessageBox>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    m_conn = new PGCONN_NAMESPACE::Connection(this);

    connect(this, &App::privateConnectToDatabase, m_conn, &PGCONN_NAMESPACE::Connection::connectToDatabase);

    connect(m_conn, &PGCONN_NAMESPACE::Connection::statusChanged, this, &App::onDatabaseConnectionStatusChanged);
    connect(m_conn, &PGCONN_NAMESPACE::Connection::statusChanged, this, &App::databaseStatusChanged);

    initActions();
}

App *App::get()
{
    return qobject_cast<App*>(qApp);
}

void App::connectToDatabase()
{
    emit requestDatabaseConnectionData();
}

void App::connectToDatabaseUsingConnectionData(const Pg::ConnectionData &cd)
{
    emit privateConnectToDatabase(cd);
}

void App::onDatabaseConnectionStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates &newStatus, const QString &msg)
{
    using C = PGCONN_NAMESPACE::Connection::ConnectionStates;

    switch(newStatus) {
    case(C::Connected): { emit databaseIsAvailable(msg); break; }
    case(C::Connecting): // fall through
    case(C::Disconnecting): // fall through
    case(C::Failed): // fall through
    case(C::Disconnected): // fall through
    default: { emit databaseIsUnavailable(msg); break; }
    }
}

void App::aboutProgram()
{
    QMessageBox::information(activeWindow(), tr("About %1").arg(applicationDisplayName()), tr("Not implemented"));
}

void App::initActions()
{
    m_quit = new Action(tr("&Quit"), this);
    m_quit->setShortcut(QKeySequence::Quit);
    connect(m_quit, &QAction::triggered, this, &App::quit);

    m_connectToDatabase = new ActionForUnavailableDatabase(tr("&Connect to database..."), this, QKeySequence::Open);
    connect(m_connectToDatabase, &QAction::triggered, this, &App::connectToDatabase);

    m_disconnectFromDatabase = new ActionForAvailableDatabase(tr("&Disconnect from database"), this);
    connect(m_disconnectFromDatabase, &QAction::triggered, m_conn, &PGCONN_NAMESPACE::Connection::disconnectFromDatabase);

    m_aboutProgram = new Action(tr("About program..."), this);
    connect(m_aboutProgram, &QAction::triggered, this, &App::aboutProgram);

    m_aboutQt = new Action(tr("About Qt..."), this);
    connect(m_aboutQt, &QAction::triggered, this, &App::aboutQt);

    initCustomActions();
}

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
