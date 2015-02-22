#include "ribbontoolbar.h"

#include <QApplication>

RibbonToolBar::RibbonToolBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("ribbon_toolbar");
    setMaximumHeight(43);
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

