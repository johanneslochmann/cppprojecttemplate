#pragma once

#include <infrastructure/core/types.hxx>

#include <db/pgconn/config.hxx>

PRAM_NS_BEGIN
PGCONN_NAMESPACE_BEGIN

class ConnectionData
{
public:
    ConnectionData();
    virtual ~ConnectionData();

    const String connectionString() const;

    String password() const;
    String userName() const;
    String databaseName() const;
    int port() const;
    String hostName() const;

    void setPassword(const String &password);
    void setUserName(const String &userName);
    void setDatabaseName(const String &databaseName);
    void setPort(int port);
    void setHostName(const String &hostName);

private:
    String m_hostName { defaultHostName };
    int m_port { defaultPort };
    String m_databaseName { defaultDatabaseName };
    String m_userName { defaultUserName };
    String m_password { defaultPassword };

    const String makePair(const String& field, const String& value) const;
    const String makePair(const String& field, int value) const;
};

PGCONN_NAMESPACE_END
PRAM_NS_END
