#pragma once

#include <QtWidgets/QLineEdit>

#include <ui/widgets/config.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    using QLineEdit::QLineEdit;
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
