#pragma once

#include <QtCore/QObject>

#include <pqxx/pqxx>

#include <db/pgconn/config.hxx>
#include <db/pgconn/connectiondata.hxx>

PRAM_NS_BEGIN
PGCONN_NAMESPACE_BEGIN

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = 0);
    virtual ~Connection();

    enum class ConnectionStates {
        Undefined,
        Connecting,
        Connected,
        Disconnecting,
        Disconnected,
        Failed
    };

signals:
    void statusChanged(const ConnectionStates& newState, const QString& msg);

public slots:
    void connectToDatabase(const ConnectionData& cd);
    void disconnectFromDatabase();

private:
    pqxx::connection* m_conn { nullptr };
};

PRAM_NS_END
PGCONN_NAMESPACE_END
