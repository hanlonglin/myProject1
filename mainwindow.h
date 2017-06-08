#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QCoreApplication>
#include <QDir>
#include "homewindow.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //公共变量
    QString userIniPath=QCoreApplication::applicationDirPath()+"/user.ini";

private:
    Ui::MainWindow *ui;

    HomeWindow *homeWindow=new HomeWindow;

private slots:

    //重置
    void resetSlot();

    //登陆
    void loginSlot();

    //显示界面,保存的用户名和密码
    void showUserAndPasswd();

};

#endif // MAINWINDOW_H
