#pragma once

#include <QtWidgets/QGroupBox>

#include <ui/widgets/config.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class GroupBox : public QGroupBox
{
    Q_OBJECT
public:
    using QGroupBox::QGroupBox;
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
