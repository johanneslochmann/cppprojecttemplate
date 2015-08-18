#include "databaseconnectiondatadialog.hxx"

#include <apps/app/app.hxx>
#include <apps/app/settings.hxx>

#include <ui/widgets/gridgroupbox.hxx>
#include <ui/widgets/databaseconnectionstatuslabel.hxx>
#include <ui/widgets/fieldlabel.hxx>
#include <ui/widgets/hostnameedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionDataDialog::DatabaseConnectionDataDialog(QWidget *p)
    : VerticalDialog(QObject::tr("Database Connection"), p)
{
    m_cd = APP_NAMESPACE::Settings().loadConnectionData();

    auto status = createStatusWidget<DatabaseConnectionStatusLabel>();
    status->onDatabaseStatusChanged(PGCONN_NAMESPACE::Connection::ConnectionStates::Disconnected, tr("Not connected."));

    createWidgets();
    createButtons();
}

void DatabaseConnectionDataDialog::accept()
{
    APP_NAMESPACE::Settings s;
    s.saveConnectionData(m_cd);

    done(QDialog::Accepted);
}

void DatabaseConnectionDataDialog::createWidgets()
{
    m_box = createContentWidget<GridGroupBox>();
    m_box->setTitle(tr("&Database Connection Database"));

    m_host = m_box->createLabelledSingleRowWidget<HostNameEdit>(tr("&Host"), QString::fromStdString(m_cd.hostName()));
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
