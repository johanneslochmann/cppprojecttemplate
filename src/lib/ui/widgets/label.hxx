#pragma once

#include <ui/widgets/config.hxx>

#include <QLabel>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Label: public QLabel
{
    Q_OBJECT
public:
    using QLabel::QLabel;
};

PRAM_NS_END
WIDGETS_NAMESPACE_END
