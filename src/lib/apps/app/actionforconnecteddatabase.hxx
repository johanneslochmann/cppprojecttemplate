#pragma once

#include <apps/app/databaseaction.hxx>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class ActionForConnectedDatabase : public DatabaseAction
{
public:
    explicit ActionForConnectedDatabase(const QString& text, QWidget* p = nullptr, const QKeySequence& seq = {});

public slots:
    void onDatabaseAvailable();
    void onDatabaseUnavailable();
};

PROJECT_NAMESPACE_END
APP_NAMESPACE_END
