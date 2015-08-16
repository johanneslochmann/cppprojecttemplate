#pragma once

#include <apps/app/config.hxx>

#include <QApplication>

PROJECT_NAMESPACE_BEGIN
APP_NAMESPACE_BEGIN

class App : public QApplication
{
    Q_OBJECT
public:
    explicit App(int& argc, char** argv);
};

APP_NAMESPACE_END
PROJECT_NAMESPACE_END
