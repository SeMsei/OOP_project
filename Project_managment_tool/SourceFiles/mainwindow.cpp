
#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setLoginInterface();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setLoginInterface() {
    setCentralWidget(new LoginInterface(this));
}


