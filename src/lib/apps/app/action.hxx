#pragma once

#include <QtWidgets/QAction>

#include <apps/app/config.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class Action : public QAction
{
public:
    using QAction::QAction;
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
