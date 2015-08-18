#include "dialog.hxx"

#include <QtWidgets/QLayout>

PROJECT_NAMESPACE_BEGIN
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

PROJECT_NAMESPACE_END
WIDGETS_NAMESPACE_END
