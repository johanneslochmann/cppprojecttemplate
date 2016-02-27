#pragma once

#include <ui/widgets/lineedit.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class DatabaseNameEdit : public LineEdit
{
    Q_OBJECT
public:
    using LineEdit::LineEdit;
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
