#pragma once

#include <ui/widgets/lineedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class HostNameEdit: public LineEdit {
    Q_OBJECT
public:
    explicit HostNameEdit(const QString& host, QWidget* p = nullptr);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
