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

    textStuff = new QLabel(this);
    textStuff->setText("This really rocks");
    layout1->addWidget(textStuff);
    setLayout(layout1);
}

Widget::~Widget()
{
    delete ui;
}