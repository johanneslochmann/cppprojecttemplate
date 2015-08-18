#include "databaseconnectiondatadialog.hxx"

#include <apps/app/app.hxx>
#include <apps/app/settings.hxx>

#include <ui/widgets/gridgroupbox.hxx>
#include <ui/widgets/databaseconnectionstatuslabel.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionDataDialog::DatabaseConnectionDataDialog(QWidget *p)
    : VerticalDialog(QObject::tr("Database Connection"), p)
{
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
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
