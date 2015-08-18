#include "verticaldialog.hxx"

#include <QtWidgets/QVBoxLayout>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

VerticalDialog::VerticalDialog(const QString &title, QWidget *p)
    : Dialog(p)
{
    setLayout(new QVBoxLayout(this));
    setWindowTitle(title);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
