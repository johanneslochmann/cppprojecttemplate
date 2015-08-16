#pragma once

#include <QLabel>

class Label: public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget* p = nullptr);
};
