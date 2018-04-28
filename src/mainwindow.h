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
#include <QRegExp>
#include <QDoubleSpinBox>



class AbstractBox: public QObject{
public:
    int id;
    QLabel* labelName;

};
class OperationBox : public AbstractBox{
    Q_OBJECT

protected:

    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
    QGraphicsRectItem *mainItem;
    QList<OperationBox *> *boxesListTemp;

public:
    QString type;
    QLabel* labelType;
    QComboBox* comboBoxInput1;
    QComboBox* comboBoxInput2;
    QComboBox* comboBoxOutput;
    OperationBox(auto *scene, auto *ui, QList<OperationBox *> &boxesList);
    ~OperationBox();
    bool calculate();
signals:
    void sigOnChangeIn1(QString in_port, QString out_port);
public slots:
    void onChangeIn1(QString port_name);
    void on_deleteButton_clicked();

};

class InputBox: public AbstractBox{
public:
    QComboBox* comboBoxOutput;
    QDoubleSpinBox* inputSpinBox;
};

class OutputBox: public AbstractBox{
    QComboBox* comboBoxInput1;
    QLabel* resultLabel;
    QLineEdit* result;


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
    QList<OperationBox *> getList();


protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QList<OperationBox *> operationBoxesList;
    int id;
    QString defaultPort = "-------";
    QList<QString> availablePorts;
    QList<QString> usedPorts;
private:
    void updateSinglePort(auto &i, QString port);
private slots:
    void on_selectionChanged();
    void on_deleteButton_clicked(OperationBox *toDelete);
    void updatePorts();
    void onChangeIn1Main(QString in_port, QString out_port);
    void on_plusBoxButton_clicked();
};
#endif // MAINWINDOW_H
