#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>



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




class Box : public MainWindow {

};
class BoxPlus : public Box {
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
public:
    BoxPlus();
    ~BoxPlus();
    QPair<QString, double> getData(QString opt);
    void calculate(QPair<QString, double> opt1, QPair<QString, double> opt2);

};

#endif // MAINWINDOW_H
