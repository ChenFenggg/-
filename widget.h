#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>              //背景函数？
#include<QProcess>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent * event);

private slots:

    void on_x64dbug_clicked();


    void on_sublime_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

