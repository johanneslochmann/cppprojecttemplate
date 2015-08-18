#include "connection.hxx"

PROJECT_NAMESPACE_BEGIN
PGCONN_NAMESPACE_BEGIN

Connection::Connection(QObject *parent)
    : QObject(parent)
{
}

Connection::~Connection()
{
    if (m_conn) {
        delete m_conn;
    }
}

void Connection::connectToDatabase(const ConnectionData &cd)
{
    try {
        emit statusChanged(ConnectionStates::Connecting, tr("Connecting..."));

        if (m_conn) {
            delete m_conn;
        }

        m_conn = new pqxx::connection(cd.connectionString());

        emit statusChanged(ConnectionStates::Connected, tr("Connected"));
    }
    catch(std::runtime_error& e) {
        emit statusChanged(ConnectionStates::Failed, tr("Connection Failed: %1").arg(e.what()));
    }
}

PROJECT_NAMESPACE_END
PGCONN_NAMESPACE_END
