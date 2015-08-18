#pragma once

#include <ui/widgets/lineedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class DatabaseNameEdit : public LineEdit
{
    Q_OBJECT
public:
    using LineEdit::LineEdit;
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
