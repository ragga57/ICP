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
#include <QLineEdit>
#include <QGraphicsLineItem>

#include <unistd.h>

//class customRectItem: public QGraphicsRectItem{
//signals:
//    void posChanged();
//public:
//    customRectItem(int x, int y, int w, int h): QGraphicsRectItem(x,y,w,h){
//        setFlags(
//            QGraphicsItem::ItemIsSelectable
//            | QGraphicsItem::ItemIsMovable
//            | QGraphicsItem::ItemSendsGeometryChanges);

//    }

//    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override
//    {
//        if(change == ItemPositionHasChanged && scene()){
//            emit posChanged();
//        }
//        return QGraphicsItem::itemChange(change, value);
//    }
//};

#include <QGraphicsSceneHoverEvent>
#include <QEvent>


class AbstractBox: public QObject{
public:
    int id;
    double resultValue;
    QLabel* labelName;
    QGraphicsRectItem* mainItem;
    QPushButton* deleteButton;

};
class OperationBox : public AbstractBox{
    Q_OBJECT

protected:
    QList<OperationBox *> *boxesListTemp;
    //virtual void hoverMoveEvent(QGraphicsSceneHoverEvent * event);

public:
    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;
    QString type;
    QLabel* labelType;
    QComboBox* comboBoxInput1;
    QComboBox* comboBoxInput2;
    QComboBox* comboBoxOutput;
    OperationBox(auto *scene, QList<OperationBox *> &boxesList);
    ~OperationBox();
    bool calculate(auto operationBoxesList, auto outputBoxesList);
signals:
    void sigOnChangeIn1(QString in_port, QString out_port);
    void sigOnChangeOut(QString in_port, QString out_port);
public slots:
    void onChangeIn1(QString port_name);
    void onChangeIn2(QString port_name);
    void onChangeOut(QString port_name);
    void on_deleteButton_clicked();
};

class InputBox: public AbstractBox{
    Q_OBJECT
protected:
    QList<InputBox *> *boxesListTemp;
public:
    QPair<QString, double> outputPort;
    QComboBox* comboBoxOutput;
    QDoubleSpinBox* inputSpinBox;
    InputBox(auto *scene, QList<InputBox *> &boxesList);
    ~InputBox();
    void calculate(auto operationBoxesList, auto outputBoxesList);
public slots:
    void on_deleteButton_clicked();

};

class OutputBox: public AbstractBox{
    Q_OBJECT
protected:
    QList<OutputBox *> *boxesListTemp;
public:
    QPair<QString, double> inputPort1;
    QComboBox* comboBoxInput1;
    QLabel* resultLabel;
    QLineEdit* result;
    OutputBox(auto *scene, QList<OutputBox *> &boxesList);
    ~OutputBox();
    void calculate();
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
    QList<OperationBox *> getList();
    //void drawLines();


protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QList<InputBox *> inputBoxesList;
    QList<OperationBox *> operationBoxesList;
    QList<OutputBox *> outputBoxesList;
    QList<QGraphicsLineItem *> linesList;
    int id;
    QString defaultPort = "-------";
    QList<QString> availablePorts;
    QList<QString> usedPorts;
private:
    void updateOperationBoxPort(auto &i, QString port);
    void updateInputBoxPort(auto &i);
    void updateOutputBoxPort(auto &i);
    void drawLines();
    void createSpecificOperationBox(QString type);
private slots:
    void on_selectionChanged();
    void on_deleteButton_clicked(OperationBox *toDelete);
    void updatePorts();
    void onChangeIn1Main(QString in_port, QString out_port);
    void onChangeOutMain(QString in_port, QString out_port);
    void on_plusBoxButton_clicked();
    void on_inputButton_clicked();
    void on_outputButton_clicked();
    void on_itempositionhaschanged(QList<QRectF>);
    void on_runButton_clicked();
    void on_minusBoxButton_clicked();
    void on_multiBoxButton_clicked();
    void on_divideBoxButton_clicked();
};
#endif // MAINWINDOW_H
