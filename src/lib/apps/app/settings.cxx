#include "settings.hxx"

#include <QtCore/QSettings>

#include <db/pgconn/config.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

Settings::Settings()
{
}

Settings::~Settings()
{
}

void Settings::saveConnectionData(Pg::ConnectionData &cd)
{
    QSettings s;
    s.beginGroup("DefaultDatabaseConnectionData");
    s.setValue("HostName", QString::fromStdString(cd.hostName()));
    s.setValue("Port", cd.port());
    s.setValue("DatabaseName", QString::fromStdString(cd.databaseName()));
    s.setValue("UserName", QString::fromStdString(cd.userName()));
    s.endGroup();
}

PGCONN_NAMESPACE::ConnectionData Settings::loadConnectionData() {
    PGCONN_NAMESPACE::ConnectionData cd;

    QSettings s;
    s.beginGroup("DefaultDatabaseConnectionData");
    cd.setHostName(s.value("HostName", PGCONN_NAMESPACE::defaultHostName.c_str()).toString().toStdString());
    cd.setPort(s.value("Port", PGCONN_NAMESPACE::defaultPort).toInt());
    cd.setDatabaseName(s.value("DatabaseName", PGCONN_NAMESPACE::defaultDatabaseName.c_str()).toString().toStdString());
    cd.setUserName(s.value("UserName", PGCONN_NAMESPACE::defaultUserName.c_str()).toString().toStdString());
    s.endGroup();

    return cd;
}

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
