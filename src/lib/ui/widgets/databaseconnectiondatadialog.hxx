#pragma once

#include <ui/widgets/verticaldialog.hxx>

#include <db/pgconn/connectiondata.hxx>

class QLineEdit;

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

class GridGroupBox;
class PortEdit;

class DatabaseConnectionDataDialog : public VerticalDialog
{
    Q_OBJECT
public:
    explicit DatabaseConnectionDataDialog(QWidget* p = nullptr);

    PGCONN_NAMESPACE::ConnectionData connectionData() const { return m_cd; }

public slots:
    void accept();

protected:
    void createWidgets();

private:
    GridGroupBox* m_box;
    QLineEdit* m_host;
    PortEdit* m_port;
    QLineEdit* m_databaseName;

    PGCONN_NAMESPACE::ConnectionData m_cd;
};

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
