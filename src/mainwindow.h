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



class AbstractBox: public QObject{
public:
    int id;
    QLabel* labelName;
    QGraphicsRectItem *mainItem;
    QPushButton* deleteButton;

};
class OperationBox : public AbstractBox{
    Q_OBJECT

protected:

    QPair<QString, double> inputPort1;
    QPair<QString, double> inputPort2;
    QPair<QString, double> outputPort;

    QList<OperationBox *> *boxesListTemp;

public:
    QString type;
    QLabel* labelType;
    QComboBox* comboBoxInput1;
    QComboBox* comboBoxInput2;
    QComboBox* comboBoxOutput;
    OperationBox(auto *scene, QList<OperationBox *> &boxesList);
    ~OperationBox();
    bool calculate();

public slots:
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
public slots:
    void on_deleteButton_clicked();
};

class OutputBox: public AbstractBox{
    Q_OBJECT
protected:
    QPair<QString, double> inputPort1;
    QList<OutputBox *> *boxesListTemp;
public:
    QComboBox* comboBoxInput1;
    QLabel* resultLabel;
    QLineEdit* result;
    OutputBox(auto *scene, QList<OutputBox *> &boxesList);
    ~OutputBox();
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


protected:
  //  Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
    QList<InputBox *> inputBoxesList;
    QList<OperationBox *> operationBoxesList;
    QList<OutputBox *> outputBoxesList;
    int id;
    QString defaultPort = "-------";
    QList<QString> availablePorts;
    QList<QString> usedPorts;
private:
    void updateOperationBoxPort(auto &i, QString port);
    void updateInputBoxPort(auto &i);
    void updateOutputBoxPort(auto &i);
private slots:
    void on_selectionChanged();
    void on_deleteButton_clicked(OperationBox *toDelete);
    void updatePorts();


    void on_plusBoxButton_clicked();
    void on_inputButton_clicked();
    void on_outputButton_clicked();
};
#endif // MAINWINDOW_H
