#include "actionforconnecteddatabase.hxx"

#include <apps/app/app.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

ActionForConnectedDatabase::ActionForConnectedDatabase(const QString &text, QWidget *p, const QKeySequence &seq)
    : DatabaseAction(text, p)
{
    if (!seq.isEmpty()) {
        setShortcut(seq);
    }

    connect(App::get(), &App::databaseIsAvailable, this, &ActionForConnectedDatabase::onDatabaseAvailable);
    connect(App::get(), &App::databaseIsUnavailable, this, &ActionForConnectedDatabase::onDatabaseUnavailable);

    onDatabaseUnavailable();
}

void ActionForConnectedDatabase::onDatabaseAvailable()
{
    setEnabled(true);
}

void ActionForConnectedDatabase::onDatabaseUnavailable()
{
    setEnabled(false);
}

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
