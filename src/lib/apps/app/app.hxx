#pragma once

#include <apps/app/config.hxx>

#include <QtWidgets/QApplication>

#include <db/pgconn/connectiondata.hxx>
#include <db/pgconn/connection.hxx>

class QAction;

PRAM_NS_BEGIN
APP_NAMESPACE_BEGIN

class App : public QApplication
{
    Q_OBJECT
public:
    explicit App(int& argc, char** argv);

    static App* get();

    QAction* quitAction() const { return m_quit; }
    QAction* connectToDatabaseAction() const { return m_connectToDatabase; }
    QAction* disconnectFromDatabaseAction() const { return m_disconnectFromDatabase; }
    QAction* aboutProgramAction() const { return m_aboutProgram; }
    QAction* aboutQtAction() const { return m_aboutQt; }

public slots:
    void connectToDatabase();
    void connectToDatabaseUsingConnectionData(const PGCONN_NAMESPACE::ConnectionData& cd);

    void onDatabaseConnectionStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates& newStatus, const QString& msg);
    virtual void aboutProgram();

signals:
    void privateConnectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);
    void databaseIsAvailable(const QString& msg);
    void databaseIsUnavailable(const QString& msg);
    void databaseStatusChanged(PGCONN_NAMESPACE::Connection::ConnectionStates newStatus, const QString& msg);

    void requestDatabaseConnectionData();

protected:
    void initActions();

    virtual void initCustomActions() {}

private:
    PGCONN_NAMESPACE::Connection* m_conn;

    QAction* m_quit;
    QAction* m_connectToDatabase;
    QAction* m_disconnectFromDatabase;
    QAction* m_aboutQt;
    QAction* m_aboutProgram;
};

APP_NAMESPACE_END
PRAM_NS_END
