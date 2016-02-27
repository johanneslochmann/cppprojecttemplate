#include "verticaldialog.hxx"

#include <QtWidgets/QVBoxLayout>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

VerticalDialog::VerticalDialog(const QString &title, QWidget *p)
    : Dialog(p)
{
    setLayout(new QVBoxLayout(this));
    setWindowTitle(title);
}

WIDGETS_NAMESPACE_END
PRAM_NS_END
