#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <qdebug.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    getScene();

protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_selectionChanged();


};

class Box{
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
