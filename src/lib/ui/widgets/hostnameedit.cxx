#include "hostnameedit.hxx"

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

HostNameEdit::HostNameEdit(const QString &host, QWidget *p)
    : LineEdit(p)
{
    setText(host);
}

WIDGETS_NAMESPACE_END
PRAM_NS_END
