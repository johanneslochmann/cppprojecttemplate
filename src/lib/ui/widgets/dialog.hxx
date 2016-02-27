#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

#include <ui/widgets/config.hxx>

PRAM_NS_BEGIN
WIDGETS_NAMESPACE_BEGIN

class Dialog : public QDialog
{
    Q_OBJECT
public:
    using QDialog::QDialog;

protected:
    template<typename T=QWidget>
    T* contentWidget() const {
        return qobject_cast<T*>(m_contentWidget);
    }

    template<typename T>
    T* createContentWidget() {
        m_contentWidget = new T(this);
        appendToMainLayout(m_contentWidget);
        return contentWidget<T>();
    }

    template<typename T>
    T* createStatusWidget() {
        m_statusWidget = new T(this);
        appendToMainLayout(m_statusWidget);
        return qobject_cast<T*>(m_statusWidget);
    }

    QDialogButtonBox* createButtons(QDialogButtonBox::StandardButtons b = QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    virtual void appendToMainLayout(QWidget* w);

private:
    QWidget* m_statusWidget { nullptr };
    QWidget* m_contentWidget { nullptr };
    QDialogButtonBox* m_buttons { nullptr };
};

PRAM_NS_END
WIDGETS_NAMESPACE_END
