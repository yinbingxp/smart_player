#ifndef LOGI_H
#define LOGI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "regi.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class logi;
}
QT_END_NAMESPACE

class logi : public QWidget
{
    Q_OBJECT

public:
     logi(QWidget *parent = nullptr);
    ~logi();

 signals:
     void loginSuccess();  // 确保信号声明在这里

private slots:
    void on_registerButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::logi *ui;
    regi*registerPage;
    QSqlDatabase db;
};

#endif // LOGI_H
