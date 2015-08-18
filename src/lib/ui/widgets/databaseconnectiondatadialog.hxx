#pragma once

#include <ui/widgets/verticaldialog.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class DatabaseConnectionDataDialog : public VerticalDialog
{
    Q_OBJECT
public:
    explicit DatabaseConnectionDataDialog(QWidget* p = nullptr);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
