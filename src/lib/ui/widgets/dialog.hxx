#pragma once

#include <QtWidgets/QDialog>

#include <ui/widgets/config.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Dialog : public QDialog
{
    Q_OBJECT
public:
    using QDialog::QDialog;
};

PROJECT_NAMESPACE_END
WIDGETS_NAMESPACE_END
