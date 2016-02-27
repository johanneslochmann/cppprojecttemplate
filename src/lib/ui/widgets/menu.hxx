#pragma once

#include <QtWidgets/QMenu>

#include <ui/widgets/config.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Menu: public QMenu
{
    Q_OBJECT
public:
    using QMenu::QMenu;
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
