#include "hostnameedit.hxx"

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

HostNameEdit::HostNameEdit(const QString &host, QWidget *p)
    : LineEdit(p)
{
    setText(host);
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
