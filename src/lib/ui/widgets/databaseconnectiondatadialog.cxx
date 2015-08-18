#include "databaseconnectiondatadialog.hxx"

#include <apps/app/app.hxx>
#include <apps/app/settings.hxx>

#include <ui/widgets/gridgroupbox.hxx>
#include <ui/widgets/databaseconnectionstatuslabel.hxx>
#include <ui/widgets/fieldlabel.hxx>
#include <ui/widgets/hostnameedit.hxx>
#include <ui/widgets/portedit.hxx>
#include <ui/widgets/databasenameedit.hxx>
#include <ui/widgets/databaseusernameedit.hxx>
#include <ui/widgets/passwordedit.hxx>

PROJECT_NAMESPACE_BEGIN
WIDGETS_NAMESPACE_BEGIN

DatabaseConnectionDataDialog::DatabaseConnectionDataDialog(QWidget *p)
    : VerticalDialog(QObject::tr("Database Connection"), p)
{
    m_cd = APP_NAMESPACE::Settings().loadConnectionData();

    auto status = createStatusWidget<DatabaseConnectionStatusLabel>();
    status->onDatabaseStatusChanged(PGCONN_NAMESPACE::Connection::ConnectionStates::Disconnected, tr("Not connected."));

    createWidgets();
    createButtons();
}

void DatabaseConnectionDataDialog::accept()
{
    APP_NAMESPACE::Settings s;
    s.saveConnectionData(m_cd);

    done(QDialog::Accepted);
}

void DatabaseConnectionDataDialog::createWidgets()
{
    m_box = createContentWidget<GridGroupBox>();
    m_box->setTitle(tr("&Database Connection Database"));

    m_host = m_box->createLabelledSingleRowWidget<HostNameEdit>(tr("&Host"), QString::fromStdString(m_cd.hostName()));
    m_port = m_box->createLabelledSingleRowWidget<PortEdit>(tr("P&ort"), m_cd.port());
    m_databaseName = m_box->createLabelledSingleRowWidget<DatabaseNameEdit>(tr("&Database"), QString::fromStdString(m_cd.databaseName()));
    m_userName = m_box->createLabelledSingleRowWidget<DatabaseUserNameEdit>(tr("&User"), QString::fromStdString(m_cd.userName()));
    m_password = m_box->createLabelledSingleRowWidget<PasswordEdit>(tr("&Password"), QString::fromStdString(m_cd.password()));

    connect(m_host, &QLineEdit::textChanged, [=](const QString& val) { m_cd.setHostName(val.toStdString()); });
    connect(m_port, &PortEdit::valueChanged, [=](int val) { m_cd.setPort(val); });
    connect(m_databaseName, &QLineEdit::textChanged, [=](const QString& h) { m_cd.setDatabaseName(h.toStdString()); });
    connect(m_userName, &QLineEdit::textChanged, [=](const QString& u) { m_cd.setUserName(u.toStdString()); });
    connect(m_password, &QLineEdit::textChanged, [=](const QString& p) { m_cd.setPassword(p.toStdString()); });

    m_password->setFocus();
}

WIDGETS_NAMESPACE_END
PROJECT_NAMESPACE_END
