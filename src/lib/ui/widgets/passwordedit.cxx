#include "passwordedit.hxx"

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

PasswordEdit::PasswordEdit(const QString &password, QWidget *p)
    : LineEdit(password, p)
{
    setEchoMode(QLineEdit::Password);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
