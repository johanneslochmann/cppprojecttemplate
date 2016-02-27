#include "actionforunavailabledatabase.hxx"

#include <apps/app/app.hxx>

PRAM_NS_BEGIN
APP_NAMESPACE_BEGIN

ActionForUnavailableDatabase::ActionForUnavailableDatabase(const QString &text, QObject *p, const QKeySequence &seq)
    : DatabaseAction(text, p)
{
    if (!seq.isEmpty()) {
        setShortcut(seq);
    }

    connect(App::get(), &App::databaseIsAvailable, this, &ActionForUnavailableDatabase::onDatabaseAvailable);
    connect(App::get(), &App::databaseIsUnavailable, this, &ActionForUnavailableDatabase::onDatabaseUnavailable);

    onDatabaseUnavailable();
}

void ActionForUnavailableDatabase::onDatabaseAvailable()
{
    setEnabled(false);
}

void ActionForUnavailableDatabase::onDatabaseUnavailable()
{
    setEnabled(true);
}

APP_NAMESPACE_END
PRAM_NS_END
