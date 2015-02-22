#ifndef RIBBONTOOLBAR_H
#define RIBBONTOOLBAR_H

#include <QWidget>
#include <QString>

class QIcon;
class QHBoxLayout;
class QVBoxLayout;
class QTabBar;

class RibbonToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit RibbonToolBar(QWidget *parent = 0);
    ~RibbonToolBar();
    void loadStyleSheet(QString &fileName);
    void addRibbonAction(const QString &actionName, const QString &actionIdentifier, const QIcon &icon);
    void addRibbonTab(const QString &tabName, const QString &tabIdentifier);
    void addRibbonAction(const QString &actionName, const QString &actionIdentifier,
                         const QString &tabIdentifier, const QIcon &icon);
signals:

public slots:
};

#endif // RIBBONTOOLBAR_H
