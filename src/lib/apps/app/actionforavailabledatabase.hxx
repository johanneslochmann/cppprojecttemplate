#pragma once

#include <apps/app/databaseaction.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class ActionForAvailableDatabase : public DatabaseAction
{
public:
    explicit ActionForAvailableDatabase(const QString& text, QObject* p = nullptr, const QKeySequence& seq = {});

public slots:
    void onDatabaseAvailable();
    void onDatabaseUnavailable();
};

PROJECT_NAMESPACE_END
APP_NAMESPACE_END
