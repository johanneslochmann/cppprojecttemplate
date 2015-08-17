#include <apps/app/app.hxx>
#include <ui/widgets/mainwindow.hxx>

int main(int argc, char** argv) {
    PROJECT_NAMESPACE::APP_NAMESPACE::App a(argc, argv);
    PROJECT_NAMESPACE::WIDGETS_NAMESPACE::MainWindow w;

    w.show();

    return a.exec();
}
