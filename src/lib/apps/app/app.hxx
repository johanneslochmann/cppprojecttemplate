#pragma once

#include <apps/app/config.hxx>

#include <QApplication>

#include <db/pgconn/connectiondata.hxx>
#include <db/pgconn/connection.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class App : public QApplication
{
    Q_OBJECT
public:
    explicit App(int& argc, char** argv);

    static App* get();

public slots:
    void connectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);

    void onDatabaseConnectionStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates& newStatus, const QString& msg);

signals:
    void privateConnectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);
    void databaseIsAvailable(const QString& msg);
    void databaseIsUnavailable(const QString& msg);

private:
    PGCONN_NAMESPACE::Connection* m_conn;
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
