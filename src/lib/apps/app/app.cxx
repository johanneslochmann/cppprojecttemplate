#include "app.hxx"

#include <apps/app/action.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
{
    m_conn = new PGCONN_NAMESPACE::Connection(this);

    connect(this, &App::privateConnectToDatabase, m_conn, &PGCONN_NAMESPACE::Connection::connectToDatabase);

    connect(m_conn, &PGCONN_NAMESPACE::Connection::statusChanged, this, &App::onDatabaseConnectionStatusChanged);

    initActions();
}

App *App::get()
{
    return qobject_cast<App*>(qApp);
}

void App::connectToDatabase(const Pg::ConnectionData &cd)
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

void App::initActions()
{
    m_quit = new Action(tr("&Quit"), this);
    m_quit->setShortcut(QKeySequence::Quit);
    connect(m_quit, &QAction::triggered, this, &App::quit);

    initCustomActions();
}

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
