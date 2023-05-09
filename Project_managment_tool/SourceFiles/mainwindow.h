#pragma once

#include <QMainWindow>
#include "Login/logininterface.h"


class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setLoginInterface();
    void setSettingsInterface();
    void setMainInterface();
};
