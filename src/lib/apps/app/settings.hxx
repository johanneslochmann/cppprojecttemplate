#pragma once

#include <db/pgconn/connectiondata.hxx>

#include <apps/app/config.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class Settings
{
public:
    Settings();
    virtual ~Settings();

    void saveConnectionData(PGCONN_NAMESPACE::ConnectionData& cd);

    PGCONN_NAMESPACE::ConnectionData loadConnectionData();
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
