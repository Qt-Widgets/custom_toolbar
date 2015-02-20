#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    layout1 = new QVBoxLayout();

    toolBarTab = new QTabBar(this);
    layout1->addWidget(toolBarTab);
    addTabStuff();

    textStuff = new QLabel(this);
    textStuff->setText("This really rocks");
    layout1->addWidget(textStuff);
    setLayout(layout1);
}

void Widget::addTabStuff()
{
    toolBarTab->addTab("CPU Profiling");
    toolBarTab->addTab("Memory Profiling");
    connect(toolBarTab, SIGNAL(currentChanged(int)), this, SLOT(tabChange(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::tabChange(int index)
{
    qDebug() << "Tab index changed to : " << index;
}
