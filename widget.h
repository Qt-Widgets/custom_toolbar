#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTabBar>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void addTabStuff();
    ~Widget();

private:
    Ui::Widget *ui;
    QVBoxLayout *layout1;
    QLabel *textStuff;
    QTabBar *toolBarTab;
};

#endif // WIDGET_H
