#include "widget.h"
#include "ui_widget.h"
#include <QTabWidget>
#include <QTabBar>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    Q_INIT_RESOURCE(icons);
    ui->setupUi(this);

    layout1 = new QVBoxLayout();
    ribbonToolBar = new RibbonToolBar(this);
    ribbonToolBar->addRibbonAction("Connect", "connect_action", QIcon(":/connect-32.png"));
    ribbonToolBar->addRibbonTab("CPU Profiling", "cpu_profiling");
    ribbonToolBar->addRibbonTab("Memory Profiling", "memory_profiling");

    ribbonToolBar->addRibbonAction("Start GC", "start_gc", QIcon(":/startgc-32.png"), "memory_profiling");
    ribbonToolBar->addRibbonAction("Take Snapshot", "take_snapshot", QIcon(":/snapshot-32.png"), "memory_profiling");

    ribbonToolBar->addRibbonAction("Start CPU Profiling", "start_cpu_profile", QIcon(":/disconnect-32.png"), "cpu_profiling");
    ribbonToolBar->addRibbonAction("Stop Profiling", "stop_cpu_profiling", QIcon(":/Compare-32.png"), "cpu_profiling");

    layout1->setMenuBar(ribbonToolBar);

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

void Widget::oldLayoutCode()
{
    layout1 = new QVBoxLayout();
    customToolBar = new CustomToolBar(this);
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
