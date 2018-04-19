#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "boxes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

protected:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};


class Box : public MainWindow
{
/*
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
public:
*/

};
class BoxPlus : public Box {
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
public:
    BoxPlus(auto *scene,auto *ui);
    ~BoxPlus();
    void calculate(QPair<QString, double> opt1, QPair<QString, double> opt2);
};
#endif // MAINWINDOW_H
