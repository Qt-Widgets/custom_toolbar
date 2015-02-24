#ifndef CUSTOMMAINWINDOW_H
#define CUSTOMMAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QBoxLayout>
#include <QStatusBar>

#include "ribbontoolbar.h"
#include "widget.h"

class QHBoxLayout;
class QVBoxLayout;

class CustomMainWindow : public QMainWindow
{
    Q_OBJECT
    Widget *widget;
    QStatusBar *customStatusBar;
public:
    explicit CustomMainWindow(QWidget *parent = 0);
    ~CustomMainWindow();

signals:

public slots:
};

#endif // CUSTOMMAINWINDOW_H
