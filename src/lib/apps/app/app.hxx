#pragma once

#include <apps/app/config.hxx>

#include <QtWidgets/QApplication>

#include <db/pgconn/connectiondata.hxx>
#include <db/pgconn/connection.hxx>

class QAction;

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class App : public QApplication
{
    Q_OBJECT
public:
    explicit App(int& argc, char** argv);

    static App* get();

    QAction* quitAction() const { return m_quit; }

public slots:
    void connectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);

    void onDatabaseConnectionStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates& newStatus, const QString& msg);

signals:
    void privateConnectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);
    void databaseIsAvailable(const QString& msg);
    void databaseIsUnavailable(const QString& msg);

protected:
    void initActions();

    virtual void initCustomActions() {}

private:
    PGCONN_NAMESPACE::Connection* m_conn;

    QAction* m_quit;
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
