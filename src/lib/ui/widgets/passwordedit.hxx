#pragma once

#include <ui/widgets/lineedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class PasswordEdit : public LineEdit
{
    Q_OBJECT
public:
    explicit PasswordEdit(const QString& password, QWidget* p = nullptr);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
