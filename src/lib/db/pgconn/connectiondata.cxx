#include "connectiondata.hxx"

PROJECT_NAMESPACE_BEGIN
PGCONN_NAMESPACE_BEGIN

ConnectionData::ConnectionData()
{

}

ConnectionData::~ConnectionData()
{

}

const String ConnectionData::connectionString() const
{
    return "not implemented";
}

String ConnectionData::password() const
{
    return m_password;
}

void ConnectionData::setPassword(const String &password)
{
    m_password = password;
}

String ConnectionData::userName() const
{
    return m_userName;
}

void ConnectionData::setUserName(const String &userName)
{
    m_userName = userName;
}

String ConnectionData::databaseName() const
{
    return m_databaseName;
}

void ConnectionData::setDatabaseName(const String &databaseName)
{
    m_databaseName = databaseName;
}

int ConnectionData::port() const
{
    return m_port;
}

void ConnectionData::setPort(int port)
{
    m_port = port;
}

String ConnectionData::hostName() const
{
    return m_hostName;
}

void ConnectionData::setHostName(const String &hostName)
{
    m_hostName = hostName;
}

PGCONN_NAMESPACE_END
PROJECT_NAMESPACE_END
