#include "databaseconnectionstatuslabel.hxx"

#include <apps/app/app.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionStatusLabel::DatabaseConnectionStatusLabel(QWidget* p)
    : StatusLabel(p)
{
    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::databaseIsAvailable, this, &DatabaseConnectionStatusLabel::onDatabaseAvailable);
    connect(APP_NAMESPACE::App::get(), &APP_NAMESPACE::App::databaseIsUnavailable, this, &DatabaseConnectionStatusLabel::onDatabaseUnavailable);
}

void DatabaseConnectionStatusLabel::onDatabaseAvailable(const QString &msg)
{
    setText(msg);
}

void DatabaseConnectionStatusLabel::onDatabaseUnavailable(const QString &msg)
{
    setText(msg);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
