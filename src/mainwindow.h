#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QComboBox>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QPushButton>
#include <QtGlobal>
#include <QList>



class Box: public QObject{
/*
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
public:
*/

};
class BoxPlus : public Box{
    Q_OBJECT

protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
    QGraphicsRectItem *MainItem;
    QList<BoxPlus *> * boxesListTemp;
public:
    BoxPlus(auto *scene, auto *ui, QList<BoxPlus *> &boxesList);
    ~BoxPlus();
    void calculate(QPair<QString, double> opt1, QPair<QString, double> opt2);

public slots:
    void on_deleteButton_clicked();
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QList<BoxPlus*> getList();

protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QList<BoxPlus *> boxesList;
private slots:
    void on_pushButton_clicked();
    void on_selectionChanged();
    void on_deleteButton_clicked(BoxPlus *toDelete);


};
#endif // MAINWINDOW_H
