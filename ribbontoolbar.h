#ifndef RIBBONTOOLBAR_H
#define RIBBONTOOLBAR_H

#include <QWidget>
#include <QString>
#include <QVector>
#include <QSharedPointer>
#include <QAbstractButton>

class QIcon;
class QHBoxLayout;
class QVBoxLayout;
class QTabBar;
class QToolButton;
class QPushButton;

typedef QSharedPointer<QAbstractButton> Btnptr;

class RibbonToolBar : public QWidget
{
    Q_OBJECT

    QHBoxLayout *layout0;
    QVBoxLayout *layout1;
    QVector<Btnptr> actionList;
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


void makeMarginSpacingZero(QBoxLayout *layout);
#endif // RIBBONTOOLBAR_H
