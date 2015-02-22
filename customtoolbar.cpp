#include "customtoolbar.h"
#include <QPushButton>
#include <QAction>
#include <QApplication>
#include <QFile>
#include <QSpacerItem>
#include <QToolButton>

CustomToolBar::CustomToolBar(QWidget *parent)
    :QWidget(parent)
{
    setObjectName("ribbon_toolbar");
    loadStyleSheet();
    setMaximumHeight(48);
    layout0 = new QHBoxLayout(this);
    QToolButton *connectButton = new QToolButton(this);
    connectButton->setObjectName("tool_button");
    connectButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    connectButton->setIcon(*icons.at(2).data());
    connectButton->setText("Connect");
    connectButton->setMinimumHeight(48);
    layout0->addWidget(connectButton, 0, Qt::AlignLeft | Qt::AlignTop);

    subTabHolder = new QWidget(this);
    subTabHolder->setMinimumWidth(600);
    subTabHolder->setObjectName("subtab_holder");
    subTabHolder->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout0->addWidget(subTabHolder, 0, 0);

    layout1 = new QVBoxLayout(this);
    tabBar = new QTabBar(this);
    tabBar->setObjectName("action_toolbar");
    tabBar->addTab("CPU Profiling");
    tabBar->addTab("Memory Profiling");
    tabBar->setMaximumHeight(20);
    tabBar->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(customTabChanged(int)));
    layout1->addWidget(tabBar, 0, Qt::AlignTop);

    actionHolder = new QWidget(this);
    actionHolder->setMinimumHeight(32);
    actionHolder->setObjectName("actionHolder");
    layout1->addWidget(actionHolder);
    populateActions();
    layout1->setMargin(0);
    layout1->setSpacing(0);
    layout1->setContentsMargins(0,0,0,0);
    subTabHolder->setLayout(layout1);

    layout0->setMargin(0);
    layout0->setSpacing(0);
    layout0->setContentsMargins(0, 0, 0, 0);
    setLayout(layout0);
}

CustomToolBar::~CustomToolBar()
{

}

void CustomToolBar::populateActions()
{
    actionLayout = new QHBoxLayout();
    QPushButton *button1 = new QPushButton(*icons.at(0).data(), "Start GC", this);
    QPushButton *button2 = new QPushButton(*icons.at(1).data(), "Take snapshot", this);
    QSpacerItem *spacer = new QSpacerItem(100, 32, QSizePolicy::MinimumExpanding);
    actionLayout->addWidget(button1);
    actionLayout->addWidget(button2);
    actionLayout->addSpacerItem(spacer);
    actionLayout->setMargin(0);
    actionLayout->setContentsMargins(0,0,0,0);
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
