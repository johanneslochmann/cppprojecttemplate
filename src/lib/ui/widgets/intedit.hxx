#pragma once

#include <ui/widgets/lineedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class IntEdit: public LineEdit {
    Q_OBJECT
public:
    explicit IntEdit(int val, QWidget* p = nullptr);

    int value() const;

public slots:
    void setValue(int val);

signals:
    void valueChanged(int val);
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END

