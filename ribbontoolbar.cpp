#include "ribbontoolbar.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabBar>
#include <QToolButton>
#include <QIcon>
#include <QSpacerItem>
#include <QFile>

void RibbonToolBar::insertRibbonWidget()
{
    ribbonUiWidget = new QWidget(this);
    ribbonUiWidget->setMinimumWidth(600);
    ribbonUiWidget->setObjectName("ribbon_toolbar");
    ribbonUiWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    layout0->addWidget(ribbonUiWidget, 0, 0);

    layout1 = new QVBoxLayout(this);
    tabBar = new QTabBar(this);
    // give a name to the TabBar to be used from CSS
    tabBar->setObjectName("action_tabbar");
    tabBar->setMaximumHeight(20);
    tabBar->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    connect(tabBar, &QTabBar::currentChanged, this, &RibbonToolBar::tabSelectionChanged);
    layout1->addWidget(tabBar, 0, Qt::AlignTop);

    makeMarginSpacingZero(layout1);
    ribbonUiWidget->setLayout(layout1);
}

RibbonToolBar::RibbonToolBar(QWidget *parent) : QWidget(parent)
{
    // give a name to the entire widget to be used from css
    setObjectName("ribbon_toolbar");
    setMaximumHeight(48);

    layout0 = new QHBoxLayout(this);
    insertRibbonWidget();
    makeMarginSpacingZero(layout0);
    setLayout(layout0);
}

RibbonToolBar::~RibbonToolBar()
{

}

void RibbonToolBar::loadStyleSheet(QString &fileName)
{
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(file.readAll());

    qApp->setStyleSheet(styleSheet);
}


// this adds a action to main toolbar
void RibbonToolBar::addRibbonAction(const QString &actionName,
                                    const QString &actionIdentifier,
                                    const QIcon &icon)
{
    QToolButton *actionButton = new QToolButton(this);
    actionButton->setObjectName(actionIdentifier);
    actionButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    actionButton->setIcon(icon);
    actionButton->setText(actionName);
    actionButton->setMinimumHeight(48);
    toolBarButtons[actionIdentifier] = actionButton;
    layout0->insertWidget(0, actionButton, 0, Qt::AlignLeft | Qt::AlignTop);
}

void RibbonToolBar::addRibbonTab(const QString &tabName,
                                 const QString &tabIdentifier)
{
    tabBar->addTab(tabName);
    QWidget *actionHolder = new QWidget(this);
    actionHolder->setObjectName(tabIdentifier);
    QHBoxLayout *actionLayout = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(100, 32, QSizePolicy::MinimumExpanding);
    actionLayout->addSpacerItem(spacer);
    makeMarginSpacingZero(actionLayout);
    actionHolder->setLayout(actionLayout);

    containerWidgets[tabIdentifier] = actionHolder;
}

// this adds an action to one of the tabs
void RibbonToolBar::addRibbonAction(const QString &actionName,
                                    const QString &actionIdentifier,
                                    const QString &tabIdentifier,
                                    const QIcon &icon)
{
    QWidget *actionHolder = containerWidgets[tabIdentifier];
    QToolButton *actionButton = new QToolButton(this);
    actionButton->setObjectName(actionIdentifier);
    actionButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    actionButton->setIcon(icon);
    actionButton->setText(actionName);
    actionHolder->layout()->addWidget(actionButton);
    toolBarButtons[actionIdentifier] = actionButton;
}

void RibbonToolBar::tabSelectionChanged(int index)
{

}

void makeMarginSpacingZero(QBoxLayout *layout) {
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);
}
