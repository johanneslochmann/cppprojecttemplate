#pragma once

#include <QtWidgets/QLineEdit>

#include <ui/widgets/config.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    using QLineEdit::QLineEdit;
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
