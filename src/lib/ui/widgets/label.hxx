#pragma once

#include <ui/widgets/config.hxx>

#include <QLabel>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Label: public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget* p = nullptr);
};

PROJECT_NAMESPACE_END
WIDGETS_NAMESPACE_END
