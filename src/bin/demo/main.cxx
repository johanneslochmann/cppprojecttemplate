#include <apps/app/app.hxx>
#include <ui/widgets/mainwindow.hxx>

#include "config.hxx"

int main(int argc, char** argv) {
    QCoreApplication::setApplicationName(QString::fromStdString(PROJECT_NAMESPACE::applicationName));
    QCoreApplication::setApplicationVersion(QString::fromStdString(PROJECT_NAMESPACE::applicationVersion));
    QCoreApplication::setOrganizationName(QString::fromStdString(PROJECT_NAMESPACE::organizationName));
    QCoreApplication::setOrganizationDomain(QString::fromStdString(PROJECT_NAMESPACE::organizationDomain));
    QApplication::setApplicationDisplayName(QObject::tr("%1 V. %2")
                                            .arg(QCoreApplication::applicationName())
                                            .arg(QCoreApplication::applicationVersion()));

    PROJECT_NAMESPACE::APP_NAMESPACE::App a(argc, argv);
    PROJECT_NAMESPACE::WIDGETS_NAMESPACE::MainWindow w;

    w.show();

    return a.exec();
}
