#include "dialog.hxx"

#include <QtWidgets/QLayout>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

QDialogButtonBox *Dialog::createButtons(QDialogButtonBox::StandardButtons b)
{
    m_buttons = new QDialogButtonBox(b, Qt::Horizontal, this);

    connect(m_buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);

    appendToMainLayout(m_buttons);

    return m_buttons;
}

void Dialog::appendToMainLayout(QWidget *w)
{
    layout()->addWidget(w);
}

PRAM_NS_END
WIDGETS_NAMESPACE_END
