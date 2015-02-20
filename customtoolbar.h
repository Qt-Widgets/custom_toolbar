#ifndef CUSTOMTOOLBAR_H
#define CUSTOMTOOLBAR_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabBar>
#include <QLabel>
#include <QDebug>

class CustomToolBar : public QWidget
{
public:
    CustomToolBar(QWidget *parent = 0);
    ~CustomToolBar();
private:
    QTabBar *tabBar;
};

#endif // CUSTOMTOOLBAR_H
