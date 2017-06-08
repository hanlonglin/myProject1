#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButtonReset,SIGNAL(clicked(bool)),this,SLOT(resetSlot()));//重置
    connect(ui->pushButtonLogin,SIGNAL(clicked(bool)),this,SLOT(loginSlot()));//登陆
    //显示用户名和密码
    showUserAndPasswd();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//*****************************************************slots

//重置
void MainWindow::resetSlot()
{
    ui->LineEditUserName->clear();
    ui->LineEditPasswd->clear();
    ui->checkBoxRememberPasswd->setCheckState(Qt::Checked);
}
//登陆
void MainWindow::loginSlot()
{
    QString userName=ui->LineEditUserName->text();
    QString passwd=ui->LineEditPasswd->text();
    if(userName.isEmpty()||passwd.isEmpty())
    {
        QMessageBox::information(this,"Waring","user name or password can't be null!!");
        return;
    }
    //写入user.ini文件
    QSettings *setting=new QSettings(userIniPath,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    setting->setValue("user/userName",userName);
    if((userName=="hanlonglin")&&(passwd=="longlin1234"))
    {
        QMessageBox::information(this,"","login success");
        if(ui->checkBoxRememberPasswd->checkState()==Qt::Checked)
        {
            setting->setValue("user/passwd",passwd);
        }
    }
    else
    {
        QMessageBox::information(this,"Wairing","user name or password wrong!");
    }
    delete setting;
}
//显示保存的用户名和密码
void MainWindow::showUserAndPasswd()
{
    QSettings *setting=new QSettings(userIniPath,QSettings::IniFormat);
    setting->setIniCodec("UTF8");
    //取出user.ini内容
    QString userName=setting->value("user/userName").toString();
    QString passwd=setting->value("user/passwd").toString();

    ui->LineEditUserName->setText(userName);
    ui->LineEditPasswd->setText(passwd);
    ui->checkBoxRememberPasswd->setCheckState(Qt::Checked);
}
