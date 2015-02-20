#include "customtoolbar.h"

CustomToolBar::CustomToolBar(QWidget *parent = 0)
    :QWidget(parent)
{
    tabBar = new QTabBar(this);
    tabBar->addTab("CPU Profiling");
    tabBar->addTab("Memory Profiling");
}

CustomToolBar::~CustomToolBar()
{

}

