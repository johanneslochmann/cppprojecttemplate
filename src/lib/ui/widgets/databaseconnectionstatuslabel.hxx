#pragma once

#include <ui/widgets/statuslabel.hxx>

#include <db/pgconn/connection.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class DatabaseConnectionStatusLabel : public StatusLabel
{
    Q_OBJECT
public:
    explicit DatabaseConnectionStatusLabel(QWidget* p = nullptr);

public slots:
    void onDatabaseStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates& newStatus, const QString& msg);
};

WIDGETS_NAMESPACE_END
PRAM_NS_END
