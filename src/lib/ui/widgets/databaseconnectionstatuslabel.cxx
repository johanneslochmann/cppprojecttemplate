#include "databaseconnectionstatuslabel.hxx"

#include <apps/app/app.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionStatusLabel::DatabaseConnectionStatusLabel(QWidget* p)
    : StatusLabel(p)
{
    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::databaseStatusChanged, this, &DatabaseConnectionStatusLabel::onDatabaseStatusChanged);

    setText(tr("Starting up..."));
}

void DatabaseConnectionStatusLabel::onDatabaseStatusChanged(const PGCONN_NAMESPACE::Connection::ConnectionStates &newStatus, const QString &msg)
{
    using C = PGCONN_NAMESPACE::Connection::ConnectionStates;

    switch (newStatus) {
    case(C::Undefined): {
        setText(tr("Undefined Connection Status"));
        setToolTip("");
        break;
    }
    case(C::Connecting): {
        setText(tr("Connecting..."));
        setToolTip(tr("Connecting to database: %1").arg(msg));
        break;
    }
    case(C::Connected): {
        setText(tr("Connected: %1").arg(msg));
        setToolTip(tr("Connected to database: %1").arg(msg));
        break;
    }
    case(C::Disconnecting): {
        setText(tr("Disconnecting..."));
        setToolTip(tr("Disconnected from database: %1").arg(msg));
        break;
    }
    case(C::Disconnected): {
        setText(tr("Disconnected"));
        setToolTip(tr("Disconnected from database"));
        break;
    }
    case(C::Failed): {
        setText(tr("Failed"));
        setToolTip(tr("Database connection failed: %1").arg(msg));
        break;
    }
    default: {
        setText(tr("Failed"));
        setToolTip(tr("Database connection failed: %1").arg(msg));
    }
    }
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
