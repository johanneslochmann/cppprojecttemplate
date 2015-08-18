#include "gridgroupbox.hxx"

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

GridGroupBox::GridGroupBox(const QString &title, QWidget *p)
    : GroupBox(title, p)
{
    m_layout = new QGridLayout(this);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
