#include "actionforavailabledatabase.hxx"

#include <apps/app/app.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

ActionForAvailableDatabase::ActionForAvailableDatabase(const QString &text, QObject *p, const QKeySequence &seq)
    : DatabaseAction(text, p)
{
    if (!seq.isEmpty()) {
        setShortcut(seq);
    }

    connect(App::get(), &App::databaseIsAvailable, this, &ActionForAvailableDatabase::onDatabaseAvailable);
    connect(App::get(), &App::databaseIsUnavailable, this, &ActionForAvailableDatabase::onDatabaseUnavailable);

    onDatabaseUnavailable();
}

void ActionForAvailableDatabase::onDatabaseAvailable()
{
    setEnabled(true);
}

void ActionForAvailableDatabase::onDatabaseUnavailable()
{
    setEnabled(false);
}

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
