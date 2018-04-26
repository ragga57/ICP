#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <qdebug.h>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QGraphicsProxyWidget>
#include <QList>





class OutputBox{
protected:

    //QGraphicsRectItem *MainItem;
    QPair<QString, double> outputPort;


public:
    int id;
    QGraphicsRectItem *MainItem;
    //OutputBox(auto *scene,auto *ui);
    //~OutputBox();
};
class DoubleInputBox: public OutputBox{
protected:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
};

class OperationBox: public DoubleInputBox{
private:
    QString Type;
public:
    OperationBox(auto *scene,auto *ui);
    ~OperationBox();
    void calculate();
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

protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QList<OperationBox> list;
    int id=0;
private slots:
    void on_pushButton_clicked();
    void on_selectionChanged();

};
#endif // MAINWINDOW_H
