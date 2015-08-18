#pragma once

#include <ui/widgets/groupbox.hxx>

#include <QtWidgets/QGridLayout>

class Label;

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class GridGroupBox : public GroupBox
{
    Q_OBJECT
public:
    explicit GridGroupBox(QWidget* p = nullptr);

    template<typename WidgetT, typename ValueT, typename LabelT=Label>
    WidgetT* createLabelledSingleRowWidget(const QString& label, const ValueT& value) {
        auto lbl = new LabelT(label, this);
        auto w = new WidgetT(value, this);

        lbl->setBuddy(w);

        lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

        m_layout->addWidget(lbl, ++m_lastRow, m_labelCol);
        m_layout->addWidget(w, m_lastRow, m_widgetCol);

        return w;
    }

private:
    QGridLayout* m_layout { nullptr };

    int m_lastRow { 0 };
    int m_labelCol { 0 };
    int m_widgetCol { m_labelCol + 1 };
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
