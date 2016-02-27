#include "connectiondata.hxx"

#include <infrastructure/core/tools.hxx>

PRAM_NS_BEGIN
PGCONN_NAMESPACE_BEGIN

ConnectionData::ConnectionData()
{
}

ConnectionData::~ConnectionData()
{
}

const String ConnectionData::connectionString() const
{
    StringVector buf;

    buf.push_back(makePair("host", hostName()));
    buf.push_back(makePair("port", port()));
    buf.push_back(makePair("dbname", databaseName()));
    buf.push_back(makePair("user", userName()));
    buf.push_back(makePair("password", password()));
    return join(buf, " ");
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

const String ConnectionData::makePair(const String &field, const String &value) const
{
    StringStream s;

    s << field << "=" << value;

    return s.str();
}

const String ConnectionData::makePair(const String &field, int value) const
{
    StringStream s;
    s << value;

    return makePair(field, s.str());
}

PGCONN_NAMESPACE_END
PRAM_NS_END
