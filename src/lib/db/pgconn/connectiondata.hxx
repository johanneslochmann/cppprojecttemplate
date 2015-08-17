#pragma once

#include <infrastructure/core/types.hxx>

#include <db/pgconn/config.hxx>

PROJECT_NAMESPACE_BEGIN
PGCONN_NAMESPACE_BEGIN

class ConnectionData
{
public:
    ConnectionData();
    virtual ~ConnectionData();
};

PGCONN_NAMESPACE_END
PROJECT_NAMESPACE_END
