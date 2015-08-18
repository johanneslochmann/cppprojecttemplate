#include "databaseconnectiondatadialog.hxx"

#include <ui/widgets/gridgroupbox.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionDataDialog::DatabaseConnectionDataDialog(QWidget *p)
    : VerticalDialog(QObject::tr("Database Connection"), p)
{
    auto box = createContentWidget<GridGroupBox>();
    box->setTitle(tr("&Database Connection Database"));

    createButtons();
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
