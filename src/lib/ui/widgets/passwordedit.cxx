#include "passwordedit.hxx"

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

PasswordEdit::PasswordEdit(const QString &password, QWidget *p)
    : LineEdit(password, p)
{
    setEchoMode(QLineEdit::Password);
}

WIDGETS_NAMESPACE_END
PRAM_NS_END
