#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::changeMoney(int n)
{
    if ((money + n) < 0) return;
    money += n;

    ui->lcdNumber->display(money);
    changeButtonState();
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pushButton_clicked()
{
    QMessageBox msg;

    int coin[] = {0, 0, 0, 0}; // [ (500), (100), (50), (10) ]
    int index = 0;
    QString str = "";

    while (money != 0){
        if (money >= 500)        index = 0;
        else if (money >= 100)   index = 1;
        else if (money >= 50)    index = 2;
        else                     index = 3;

        switch (index) {
            case 0:
                money -= 500;
                break;
            case 1:
                money -= 100;
                break;
            case 2:
                money -= 50;
                break;
            case 3:
                money -= 10;
                break;
        }
        coin[index] += 1;
    }


    str = "500: " + QString::number(coin[0]) +
          "  100: " + QString::number(coin[1]) +
          " 50: " + QString::number(coin[2]) +
          " 10:" + QString::number(coin[3]);

    msg.information(nullptr, "Return Coins", str);
    ui->lcdNumber->display(money);
}

void Widget::changeButtonState()
{
    if (money < 200 && money >= 150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(false);
    } else if (money < 150 && money >= 100){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    } else if (money < 100) {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }
}
