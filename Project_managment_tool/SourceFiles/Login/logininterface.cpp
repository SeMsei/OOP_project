#include "logininterface.h"
#include "ui_logininterface.h"

#include <QDebug>

LoginInterface::LoginInterface(QMainWindow *parent) :
    parent(dynamic_cast<MainWindow*>(parent)),
    ui(new Ui::LoginInterface)
{
    ui->setupUi(this);
    ui->label_7->setText("<a href=\"https://github.com/SeMsei/OOP_project\" style=\"color: white; font-size:16px\">SeMsei</a>");
    ui->label_7->setTextFormat(Qt::RichText);
    ui->label_7->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->label_7->setOpenExternalLinks(true);

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->pushButton_4->setIcon(QIcon(":/images/icons/eye.png"));
}

LoginInterface::~LoginInterface()
{
    delete ui;
}

void LoginInterface::on_pushButton_4_clicked()
{
    if (ui->lineEdit->echoMode() == QLineEdit::Password) {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
        ui->pushButton_4->setIcon(QIcon(":/images/icons/hide.png"));
    } else {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
        ui->pushButton_4->setIcon(QIcon(":/images/icons/eye.png"));
    }


}


void LoginInterface::on_checkBox_clicked()
{
    qDebug() << ui->checkBox->isChecked();


}

