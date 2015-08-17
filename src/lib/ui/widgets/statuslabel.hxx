#pragma once

#include <ui/widgets/label.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class StatusLabel : public Label
{
public:
    explicit StatusLabel(QWidget* p = nullptr);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
