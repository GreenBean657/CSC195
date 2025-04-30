#include <ui_mainwindow.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    Ui::MainWindow ui;
    ui.setupUi(&window);
    ui.dbView->widget = ui.editorWidget;
    window.show();
    return app.exec();
}