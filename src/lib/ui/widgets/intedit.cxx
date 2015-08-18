#include "intedit.hxx"

#include <QtGui/QIntValidator>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

IntEdit::IntEdit(int val, QWidget *p)
    : LineEdit(p)
{
    setValidator(new QIntValidator(this));
    setValue(val);

    connect(this, &QLineEdit::textChanged, [=](const QString& val){ emit valueChanged(val.toInt()); });
}

int IntEdit::value() const
{
    return text().toInt();
}

void IntEdit::setValue(int val)
{
    setText(QString("%1").arg(val));
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
