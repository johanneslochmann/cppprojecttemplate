#pragma once

#include <QObject>

#include <db/pgconn/config.hxx>
#include <db/pgconn/connectiondata.hxx>

PROJECT_NAMESPACE_BEGIN
PGCONN_NAMESPACE_BEGIN

class Connection : public QObject
{
    Q_OBJECT
public:
    explicit Connection(QObject *parent = 0);
};

PROJECT_NAMESPACE_END
PGCONN_NAMESPACE_END
