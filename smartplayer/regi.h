#ifndef REGI_H
#define REGI_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class regi;
}
QT_END_NAMESPACE

class regi : public QWidget
{
    Q_OBJECT

public:
     regi(QWidget *parent = nullptr);
    ~regi();

 signals:
     void registerSuccess();  // 确保信号声明在这里

private slots:
    void on_registerButton_clicked();

    void on_backButton_clicked();

private:
    Ui::regi *ui;
    QSqlDatabase db;
};

#endif // REGI_H
