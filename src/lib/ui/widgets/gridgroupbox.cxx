#include "gridgroupbox.hxx"

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

GridGroupBox::GridGroupBox(QWidget *p)
    : GroupBox(p)
{
    m_layout = new QGridLayout(this);
}

WIDGETS_NAMESPACE_END
PRAM_NS_END
