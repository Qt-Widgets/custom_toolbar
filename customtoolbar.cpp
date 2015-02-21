#include "customtoolbar.h"
#include <QPushButton>
#include <QAction>
#include <QApplication>
#include <QFile>
#include <QSpacerItem>

CustomToolBar::CustomToolBar(QWidget *parent)
    :QWidget(parent)
{
    Q_INIT_RESOURCE(icons);
    IconPtr icon = QSharedPointer<QIcon>(new QIcon(":/startgc-32.png"));
    icons.push_back(icon);
    icons.push_back(QSharedPointer<QIcon>(new QIcon(":/snapshot-32.png")));

    loadStyleSheet();
    setMaximumHeight(60);
    layout1 = new QVBoxLayout(this);
    tabBar = new QTabBar(this);
    tabBar->addTab("CPU Profiling");
    tabBar->addTab("Memory Profiling");
    tabBar->setMaximumHeight(30);
    connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(customTabChanged(int)));
    layout1->addWidget(tabBar, 0, Qt::AlignTop);

    actionHolder = new QWidget(this);
    actionHolder->setMinimumHeight(30);
    actionHolder->setObjectName("actionHolder");
    layout1->addWidget(actionHolder, 0, Qt::AlignTop);
    populateActions();
    layout1->setMargin(0);
    layout1->setSpacing(0);
    layout1->setContentsMargins(0,0,0,0);
    setLayout(layout1);
}

CustomToolBar::~CustomToolBar()
{

}

void CustomToolBar::populateActions()
{
    actionLayout = new QHBoxLayout();
    QPushButton *button1 = new QPushButton(*icons.at(0).data(), "Start GC", this);
    QPushButton *button2 = new QPushButton(*icons.at(1).data(), "Take snapshot", this);
    QSpacerItem *spacer = new QSpacerItem(100, 30, QSizePolicy::MinimumExpanding);
    actionLayout->addWidget(button1,0, Qt::AlignTop);
    actionLayout->addWidget(button2,0, Qt::AlignTop);
    actionLayout->addSpacerItem(spacer);
    actionLayout->setMargin(0);
    actionLayout->setContentsMargins(0,-10,0,0);
    actionHolder->setLayout(actionLayout);
}

void CustomToolBar::loadStyleSheet()
{
    QFile file(":/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    qApp->setStyleSheet(styleSheet);
}

void CustomToolBar::customTabChanged(int tabIndex)
{
    qDebug() << "Selected index is : " << tabIndex;
}
