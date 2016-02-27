#pragma once

#include <ui/widgets/lineedit.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class HostNameEdit: public LineEdit {
    Q_OBJECT
public:
    explicit HostNameEdit(const QString& host, QWidget* p = nullptr);
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
