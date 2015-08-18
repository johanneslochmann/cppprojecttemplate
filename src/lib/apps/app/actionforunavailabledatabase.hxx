#pragma once

#include <apps/app/databaseaction.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class ActionForUnavailableDatabase : public DatabaseAction
{
public:
    explicit ActionForUnavailableDatabase(const QString& text, QObject* p = nullptr, const QKeySequence& seq = {});

public slots:
    void onDatabaseAvailable();
    void onDatabaseUnavailable();
};

PROJECT_NAMESPACE_END
APP_NAMESPACE_END
