#pragma once

#include <ui/widgets/dialog.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class VerticalDialog : public Dialog
{
    Q_OBJECT
public:
    explicit VerticalDialog(const QString& title, QWidget* p=nullptr);
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
