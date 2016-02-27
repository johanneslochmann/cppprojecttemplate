#include <apps/app/app.hxx>
#include <ui/widgets/mainwindow.hxx>

#include "config.hxx"

int main(int argc, char** argv) {
    QCoreApplication::setApplicationName(QString::fromStdString(PRAM_NS::applicationName));
    QCoreApplication::setApplicationVersion(QString::fromStdString(PRAM_NS::applicationVersion));
    QCoreApplication::setOrganizationName(QString::fromStdString(PRAM_NS::organizationName));
    QCoreApplication::setOrganizationDomain(QString::fromStdString(PRAM_NS::organizationDomain));
    QApplication::setApplicationDisplayName(QObject::tr("%1 V. %2 by %3")
                                            .arg(QCoreApplication::applicationName())
                                            .arg(QCoreApplication::applicationVersion())
                                            .arg(QCoreApplication::organizationName()));

    PRAM_NS::APP_NAMESPACE::App a(argc, argv);
    PRAM_NS::WIDGETS_NAMESPACE::MainWindow w;

    w.show();

    return a.exec();
}
