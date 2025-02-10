#include "regi.h"
#include "ui_regi.h"
#include "logi.h"

regi::regi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::regi)
{
    ui->setupUi(this);
    //设置标题框
    this->setWindowTitle("注册");

    db=QSqlDatabase::database();
}

regi::~regi()
{
    delete ui;
}

void regi::on_registerButton_clicked()
{

    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();
    if (password != confirmPassword) {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QMessageBox::warning(this, "注册失败", "用户名已存在");
        ui->usernameLineEdit->clear();
        ui->usernameLineEdit->setFocus();
        return;
    }
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec()) {
        QMessageBox::information(this, "注册成功", "注册成功，请登录");
        logi *l=new logi;
        l->show();
        this->close();
    } else {
        QMessageBox::critical(this, "注册失败", query.lastError().text());
    }
}



void regi::on_backButton_clicked()
{

    emit registerSuccess();
    logi *l=new logi;
    l->show();
    this->close();
}

