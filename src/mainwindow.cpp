#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "string"
#include <QDebug>
#include <QList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    id = 0;
    connect(scene, SIGNAL (selectionChanged()), this, SLOT (on_selectionChanged()));
   // qDebug() <<"Main Windows Consturctor" << endl;
    qWarning() << "FUCK YOU QT" << endl;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
void MainWindow::updatePorts(){
    QString curr1;
    QString curr2;
    QString curr3;
    for(auto &i: boxesList){
        //qDebug() << i->id << endl;
        curr1 = i->ComboBoxInput1->currentText();
        curr2 = i->ComboBoxInput2->currentText();
        curr3 = i->ComboBoxOutput->currentText();
        i->ComboBoxInput1->clear();
        i->ComboBoxInput2->clear();
        i->ComboBoxOutput->clear();
       // i->ComboBoxInput1->addItem(curr1);
       // i->ComboBoxInput1->setCurrentText(curr1);
       // qDebug() << i->ComboBoxInput1->currentIndex() << endl;
        i->ComboBoxInput1->addItems(availablePorts);
        int temp_index = i->ComboBoxInput1->findText(curr1);
        if(temp_index >= 0){
            i->ComboBoxInput1->setCurrentIndex(temp_index);
        }
        else{
            i->ComboBoxInput1->setCurrentIndex(0);
        }
    }



}
void MainWindow::on_pushButton_clicked()
{   /*
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = scene->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    */
    qWarning() << &boxesList <<endl;
    //int test = boxesList;
     BoxPlus *temp = new BoxPlus(&scene, &ui, boxesList);
     temp->id = id;
     temp->type = "+";
    boxesList.append(temp);
     //qWarning() << boxesList <<endl;
    qWarning() << "PUSH button" << boxesList <<endl;
    ui->label->setText("Test58");
    availablePorts.append(QString::number(id)+QString("-inputPort1"));
    availablePorts.append(QString::number(id)+QString("-inputPort2"));
    availablePorts.append(QString::number(id)+QString("-OutputPort"));
    qWarning() <<"pushButton" << endl;
    qWarning() << "FUCK YOU QT" << endl;
    for(auto &i: availablePorts)
        qDebug() << i << endl;

    id++;
    updatePorts();

}

void MainWindow::on_selectionChanged(){
   // qWarning() << boxesList <<endl;

    ui->label->setText("Test69");
    // pri kliknuti do sceny crash...
   auto temp_items = scene->selectedItems();
   if (!temp_items.empty()){
        QVariant data0 = temp_items[0]->data(0);
        ui->label->setText(data0.toString());
   }
    // qDebug() << temp_items[0] << endl;
     //qDebug() << temp_items[0]->parentObject() << endl;
     //qDebug() << temp_items[0]->parentWidget() << endl;
     //qDebug() << temp_items[0]->parentItem() << endl;
     //qDebug() << temp_items[0]->data(0) << endl;
}


double test = 1.0;
BoxPlus::BoxPlus(auto *scene, auto *ui, QList<BoxPlus*> &boxesList){
    test = test+1.0;
    inputPort1.first = "number";
    inputPort1.second = test;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

    qWarning() << &boxesList << endl;

    boxesListTemp = &boxesList;

    qWarning() << "BoxPLUS Const" << boxesListTemp << endl;
    //(*ui)->label->setText("HOVNO");

    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    MainItem = (*scene)->addRect(0,20,200,125,Pen,blueBrush);
    MainItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    MainItem->setData(0,inputPort1.second);
    ComboBoxInput1 = new QComboBox();
    ComboBoxInput2 = new QComboBox();
    ComboBoxOutput = new QComboBox();
    auto LabelName = new QLabel("+");
    auto deleteButton = new QPushButton();

    ComboBoxInput1->setFixedHeight(25);
    ComboBoxInput1->setFixedWidth(75);
    ComboBoxInput2->setFixedHeight(25);
    ComboBoxInput2->setFixedWidth(75);
    ComboBoxOutput->setFixedHeight(25);
    ComboBoxOutput->setFixedWidth(75);

    LabelName->setFixedHeight(25);
    LabelName->setFixedWidth(25);

    QFont font = LabelName->font();
    font.setPointSize(20);
    font.setBold(true);
    LabelName->setFont(font);
    LabelName->setAlignment(Qt::AlignCenter);
    LabelName->setAutoFillBackground(false);
    LabelName->setStyleSheet("background:transparent");


    QGraphicsProxyWidget* ComboProxyInput1 = new QGraphicsProxyWidget(MainItem);
    QGraphicsProxyWidget* ComboProxyInput2 = new QGraphicsProxyWidget(MainItem);
    QGraphicsProxyWidget* ComboProxyOutput = new QGraphicsProxyWidget(MainItem);
    QGraphicsProxyWidget* LabelProxyName = new QGraphicsProxyWidget(MainItem);
    QGraphicsProxyWidget* DeleteProxyButton = new QGraphicsProxyWidget(MainItem);

    ComboProxyInput1->setWidget(ComboBoxInput1);
    ComboProxyInput2->setWidget(ComboBoxInput2);
    ComboProxyOutput->setWidget(ComboBoxOutput);
    LabelProxyName->setWidget(LabelName);
    DeleteProxyButton->setWidget(deleteButton);

    ComboProxyInput1->setPos(10, 45);
    ComboProxyInput2->setPos(10, 105);
    ComboProxyOutput->setPos(115,76 );
    LabelProxyName->setPos(150,35);
    DeleteProxyButton->setPos(150,200);

    qWarning() << "PRE SIGNAL" << endl;

    connect(deleteButton, SIGNAL (clicked()), this, SLOT (on_deleteButton_clicked()));
    qWarning() << "POST SIGNAL" << endl;
   // item->setData(1,toString(this));
   // item->setParentItem(&this);
}

BoxPlus::~BoxPlus(){

}
void BoxPlus::calculate(QPair<QString, double> opt1, QPair<QString, double> opt2){
    if (opt1.first == "number" && opt2.first == "number" && outputPort.first == "number"){
        outputPort.second = opt1.second + opt2.second;
    }

}

QList<BoxPlus*> MainWindow::getList(){
    return boxesList;

}

void BoxPlus::on_deleteButton_clicked(){
    QObject *temp = sender();
    qWarning() << temp << endl;
    qWarning() << "this : " << this << endl;

    qWarning() << "Pred" <<endl;
    qWarning() << "index" << &(*boxesListTemp->at(0)) << endl;
    qWarning() << "index of" << ((*boxesListTemp).indexOf(this)) << endl;

    qWarning() << *boxesListTemp <<endl;

    //QList<BoxPlus *> templist = w.getList();
    delete MainItem;
    int temp2 = ((*boxesListTemp).indexOf(this));
    (*boxesListTemp).removeAt(temp2);

    qWarning() << "Po" <<endl;
    qWarning() << *boxesListTemp <<endl;

    qWarning() << "DELETE" << endl;
}

void MainWindow::on_deleteButton_clicked(BoxPlus *toDelete){
   // delete MainItem;
    qWarning() << "DELETE" << endl;
}
