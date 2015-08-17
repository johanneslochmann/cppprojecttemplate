#pragma once

#include <apps/app/action.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class DatabaseAction : public Action
{
    Q_OBJECT
public:
    using Action::Action;
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
