#include "ribbontoolbar.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>


RibbonToolBar::RibbonToolBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("ribbon_toolbar");
    setMaximumHeight(43);

    layout0 = new QHBoxLayout(this);

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
void RibbonToolBar::addRibbonAction(const QString &actionName, const QString &actionIdentifier, const QIcon &icon)
{

}

void RibbonToolBar::addRibbonTab(const QString &tabName, const QString &tabIdentifier)
{

}

// this adds an action to one of the bas
void RibbonToolBar::addRibbonAction(const QString &actionName, const QString &actionIdentifier, const QString &tabIdentifier, const QIcon &icon)
{

}

void makeMarginSpacingZero(QBoxLayout *layout) {
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);
}
