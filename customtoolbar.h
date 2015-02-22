#ifndef CUSTOMTOOLBAR_H
#define CUSTOMTOOLBAR_H


#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabBar>
#include <QLabel>
#include <QDebug>
#include <QVector>
#include <QSharedPointer>
#include <QIcon>

typedef QSharedPointer<QWidget> WidgetPtr;
typedef QSharedPointer<QIcon> IconPtr;

class CustomToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit CustomToolBar(QWidget *parent = 0);
    ~CustomToolBar();
    void populateActions();
    void loadStyleSheet();
private:
    QTabBar *tabBar;
    QVBoxLayout *layout1;
    QHBoxLayout *layout0;
    QWidget *actionHolder;
    QHBoxLayout *actionLayout;
    QVector<WidgetPtr> actionList;
    QVector<IconPtr> icons;
    QWidget *subTabHolder;
public slots:
    void customTabChanged(int tabIndex);
};

#endif // CUSTOMTOOLBAR_H
