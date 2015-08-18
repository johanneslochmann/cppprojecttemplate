#include "databaseconnectiondatadialog.hxx"

#include <apps/app/app.hxx>

#include <ui/widgets/gridgroupbox.hxx>
#include <ui/widgets/databaseconnectionstatuslabel.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionDataDialog::DatabaseConnectionDataDialog(QWidget *p)
    : VerticalDialog(QObject::tr("Database Connection"), p)
{
    auto status = createStatusWidget<DatabaseConnectionStatusLabel>();
    status->onDatabaseStatusChanged(PGCONN_NAMESPACE::Connection::ConnectionStates::Disconnected, tr("Not connected."));

    auto box = createContentWidget<GridGroupBox>();
    box->setTitle(tr("&Database Connection Database"));

    createButtons();
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
