#pragma once

#include <ui/widgets/statuslabel.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class DatabaseConnectionStatusLabel : public StatusLabel
{
public:
    explicit DatabaseConnectionStatusLabel(QWidget* p = nullptr);

public slots:
    void onDatabaseAvailable(const QString& msg);
    void onDatabaseUnavailable(const QString& msg);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
