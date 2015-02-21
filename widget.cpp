#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    layout1 = new QVBoxLayout();
    customToolBar = new CustomToolBar(this);
    customToolBar->setObjectName("customToolBar");
    layout1->addWidget(customToolBar);

    textStuff = new QLabel(this);
    textStuff->setText("This really rocks");
    layout1->addWidget(textStuff);
    layout1->setMargin(0);
    setLayout(layout1);
}

Widget::~Widget()
{
    delete ui;
}
