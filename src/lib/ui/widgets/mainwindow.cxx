#include "mainwindow.hxx"

#include <QtCore/QTimer>

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMessageBox>

#include <apps/app/app.hxx>
#include <apps/app/action.hxx>

#include <ui/widgets/menu.hxx>
#include <ui/widgets/databaseconnectiondatadialog.hxx>
#include <ui/widgets/databaseconnectionstatuslabel.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initStatusBars();
    initMenues();

    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::requestDatabaseConnectionData, this, &MainWindow::onGetDatabaseConnectionDataFromUser);
    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::databaseStatusChanged, this, &MainWindow::onDatabaseConnectionStatusChanged);

    connect(this, &MainWindow::connectToDatabase, APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::connectToDatabaseUsingConnectionData);
}

void MainWindow::onGetDatabaseConnectionDataFromUser()
{
    auto dlg = new DatabaseConnectionDataDialog(this);

    if (QDialog::Accepted != dlg->exec()) {
        return;
    }

    emit connectToDatabase(dlg->connectionData());
}

void MainWindow::onDatabaseConnectionStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates &newStatus, const QString &msg)
{
    using C = PGCONN_NAMESPACE::Connection::ConnectionStates;

    switch(newStatus) {
    case(C::Failed): {
        QMessageBox::critical(this, tr("Database Connection Failed"), QString("<p><b>%1</b></p><p>%2</p>")
                              .arg(tr("Database Connection Failed:"))
                              .arg(msg));
        QTimer::singleShot(0, &MainWindow::onGetDatabaseConnectionDataFromUser);
        break;
    }
    case(C::Undefined): // fall through
    case(C::Connecting): // fall through
    case(C::Connected): // fall through
    case(C::Disconnecting): // fall through
    case(C::Disconnected): // fall through
    default: {
        // do nothing
        break;
    }
    };
}

void MainWindow::initMenues()
{
    m_file = new Menu(tr("&File"), this);
    m_file->addAction(APP_NAMESPACE::App::get()->quitAction());

    m_db = new Menu(tr("&Database"), this);
    m_db->addAction(APP_NAMESPACE::App::get()->connectToDatabaseAction());
    m_db->addSeparator();
    m_db->addAction(APP_NAMESPACE::App::get()->disconnectFromDatabaseAction());

    menuBar()->addMenu(m_file);
    menuBar()->addMenu(m_db);

    initCustomMenues();
}

void MainWindow::initStatusBars()
{
    statusBar()->addPermanentWidget(new DatabaseConnectionStatusLabel(statusBar()));
    initCustomStatusBars();
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
