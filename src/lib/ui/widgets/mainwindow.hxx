#pragma once

#include <QtWidgets/QMainWindow>

#include <ui/widgets/config.hxx>

#include <db/pgconn/connectiondata.hxx>
#include <db/pgconn/connection.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Menu;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:
    void connectToDatabase(const PGCONN_NAMESPACE::ConnectionData& cd);

public slots:
    void onGetDatabaseConnectionDataFromUser();
    void onDatabaseConnectionStatusChanged(const Pg::Connection::ConnectionStates &newStatus, const QString& msg);

protected:
    void initMenues();
    void initStatusBars();

    virtual void initCustomMenues() {}
    virtual void initCustomStatusBars() {}

private:
    Menu* m_file;
    Menu* m_db;
    Menu* m_help;
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
