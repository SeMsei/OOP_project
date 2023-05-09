#pragma once

#include <QWidget>
#include <QMainWindow>
#include "../mainwindow.h"

namespace Ui {
class LoginInterface;
}

class MainWindow;

class LoginInterface : public QWidget
{
    Q_OBJECT

public:
    explicit LoginInterface(QMainWindow *parent = nullptr);
    ~LoginInterface();

private slots:
    void on_pushButton_4_clicked();

    void on_checkBox_clicked();

private:
    MainWindow *parent;
    Ui::LoginInterface *ui;

};
