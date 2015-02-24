#include "custommainwindow.h"

CustomMainWindow::CustomMainWindow(QWidget *parent) : QMainWindow(parent)
{
    Q_INIT_RESOURCE(icons);
    widget = new Widget(this);
    setCentralWidget(widget);

    customStatusBar = new QStatusBar(this);
    setStatusBar(customStatusBar);

    customStatusBar->showMessage("This is loaded");
}

CustomMainWindow::~CustomMainWindow()
{

}

