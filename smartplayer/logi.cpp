#include "logi.h"
#include "ui_logi.h"
#include "widget.h"
#include "regi.h"

logi::logi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::logi)
{
    ui->setupUi(this);

//设置标题框
this->setWindowTitle("登录");

    // 连接数据库
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("smartplayer");
    db.setUserName("root");
    db.setPassword("zz71186237");

    if(!db.open()){
        QMessageBox::critical(this,"数据库连接失败",db.lastError().text());
    }
}

logi::~logi()
{
    delete ui;
}

void logi::on_registerButton_clicked()
{    this->close();
    regi *r=new regi;
    r->show();

}


void logi::on_loginButton_clicked()
{
    QString username =ui->usernameLineEdit->text();
    QString password =ui->passwordLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        emit loginSuccess();
        this->close();
        Widget w;
        w.show();

    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误");
        ui->usernameLineEdit->clear();
        ui->passwordLineEdit->clear();
        ui->usernameLineEdit->setFocus();
    }
}

