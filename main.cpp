#include <QApplication>
#include "custommainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CustomMainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
