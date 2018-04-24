#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
<<<<<<< HEAD
#include <QDebug>
#include <QBoxLayout>
#include <QLabel>
=======
#include <qdebug.h>
#include <QComboBox>
#include <QGraphicsProxyWidget>
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

<<<<<<< HEAD
private slots:
    void on_pushButton_clicked();

=======
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_selectionChanged();

<<<<<<< HEAD
class Box
{
=======

};

class Box{
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
/*
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
public:
*/

};
class BoxPlus : public Box{
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
public:
    BoxPlus(auto *scene,auto *ui);
    ~BoxPlus();
    void calculate(QPair<QString, double> opt1, QPair<QString, double> opt2);
<<<<<<< HEAD
    QPair<QString, double> getData(QString opt);
=======
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
};
#endif // MAINWINDOW_H
