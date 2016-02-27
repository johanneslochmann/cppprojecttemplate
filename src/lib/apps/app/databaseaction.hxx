#pragma once

#include <apps/app/action.hxx>

PRAM_NS_BEGIN
APP_NAMESPACE_BEGIN

class DatabaseAction : public Action
{
    Q_OBJECT
public:
    using Action::Action;
};

APP_NAMESPACE_END
PRAM_NS_END
