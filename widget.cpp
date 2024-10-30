#include "widget.h"
#include "ui_widget.h"
#include<QProcess>
#include<QFileInfo>
#include<QFileDialog>
#include<QSettings>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{    QWidget::setWindowOpacity(0.7);         //直接设置全局透明算了
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)            //设置程序背景
{   QPixmap pixmap(":/back/image/back.jpg");
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(pixmap));


}





void Widget::on_x64dbug_clicked()
{
    QSettings setting("./Settingx.ini",QSettings::IniFormat);
    QString lastPath=setting.value("LastFilePath").toString();
    QFileInfo checker(lastPath);                               //直接检测
    if (!checker.exists()) {                                            //这里是判断没有这个文件时输出
        QString curPath=QCoreApplication::applicationDirPath();
        QString str=QFileDialog::getOpenFileName(nullptr,"打开文件",curPath,"程序文件(*.exe *.ExE *.EXE)");
        setting.setValue("LastFilePath",str);
    } else {
        QProcess process;
        process.execute(checker.absoluteFilePath());
    }


}


void Widget::on_sublime_clicked()
{
    QSettings setting("./Setting.ini",QSettings::IniFormat);
    QString lastPath=setting.value("LastFilePath").toString();
    QFileInfo checker(lastPath);                               //直接检测
    if (!checker.exists()) {                                            //这里是判断没有这个文件时输出
        QString curPath=QCoreApplication::applicationDirPath();
        QString str=QFileDialog::getOpenFileName(nullptr,"打开文件",curPath,"程序文件(*.exe *.ExE *.EXE)");
        setting.setValue("LastFilePath",str);
    } else {
        QProcess process;
        process.execute(checker.absoluteFilePath());
    }

}

