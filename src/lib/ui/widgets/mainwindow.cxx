#include "mainwindow.hxx"

#include <QtWidgets/QMenuBar>

#include <apps/app/app.hxx>
#include <apps/app/action.hxx>

#include <ui/widgets/menu.hxx>
#include <ui/widgets/databaseconnectiondatadialog.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initMenues();

    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::requestDatabaseConnectionData, this, &MainWindow::onGetDatabaseConnectionDataFromUser);
    connect(this, &MainWindow::connectToDatabase, APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::connectToDatabaseUsingConnectionData);
}

void MainWindow::onGetDatabaseConnectionDataFromUser()
{
    PGCONN_NAMESPACE::ConnectionData cd;

    auto dlg = new DatabaseConnectionDataDialog(this);

    if (QDialog::Accepted != dlg->exec()) {
        return;
    }

    emit connectToDatabase(cd);
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

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
