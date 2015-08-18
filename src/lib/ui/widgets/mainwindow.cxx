#include "mainwindow.hxx"

#include <QtWidgets/QMenuBar>

#include <ui/widgets/menu.hxx>

#include <apps/app/app.hxx>
#include <apps/app/action.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    initMenues();
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
