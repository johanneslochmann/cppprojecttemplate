#pragma once

#include <QtWidgets/QAction>

#include <apps/app/config.hxx>

PRAM_NS_BEGIN
APP_NAMESPACE_BEGIN

class Action : public QAction
{
public:
    using QAction::QAction;
};

APP_NAMESPACE_END
PRAM_NS_END
