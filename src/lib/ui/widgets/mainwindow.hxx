#pragma once

#include <QtWidgets/QMainWindow>

#include <ui/widgets/config.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Menu;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

protected:
    void initMenues();
    virtual void initCustomMenues() {}

private:
    Menu* m_file;
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
