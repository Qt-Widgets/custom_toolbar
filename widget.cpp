#include "widget.h"
#include "ui_widget.h"
#include <QTabWidget>
#include <QTabBar>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    layout1 = new QVBoxLayout();
    customToolBar = new CustomToolBar(this);
    customToolBar->setObjectName("customToolBar");
    layout1->setMenuBar(customToolBar);

    QTabBar *tabBar = new QTabBar(this);
    tabBar->addTab("Object Graph");
    tabBar->addTab("Snapshot #1");
    tabBar->setObjectName("another_tab");
    tabBar->setMinimumHeight(300);
    layout1->addWidget(tabBar, 0, Qt::AlignTop);
//    textStuff = new QLabel(this);
//    textStuff->setText("This really rocks");
//    layout1->addWidget(textStuff);
    layout1->setMargin(0);
    layout1->setContentsMargins(0, 0,0,0);
    layout1->setSpacing(0);
    setLayout(layout1);
}

Widget::~Widget()
{
    delete ui;
}
