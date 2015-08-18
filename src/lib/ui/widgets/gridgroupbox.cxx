#include "gridgroupbox.hxx"

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

GridGroupBox::GridGroupBox(QWidget *p)
    : GroupBox(p)
{
    m_layout = new QGridLayout(this);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
