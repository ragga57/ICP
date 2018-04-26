#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "string"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(scene, SIGNAL (selectionChanged()), this, SLOT (on_selectionChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::on_pushButton_clicked()
{   /*
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = scene->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    */
    /*
    BoxPlus newBox(&scene, &ui);
    ui->label->setText("Test58");
    */
    static OperationBox newBox(&scene, &ui);
    list.append(newBox);
    for(auto &i: list){
                qDebug() << i.id << endl;
        }
     qDebug() << "zarazka" << endl;
     for(auto &i: list){
                 scene->addItem(i.MainItem);
         }
    ui->label->setText("Test58");
}

void MainWindow::on_selectionChanged(){
    ui->label->setText("Test69");
    // pri kliknuti do sceny crash...
    /*
    auto temp_items = scene->selectedItems();
    QVariant data0 = temp_items[0]->data(0);
    ui->label->setText(data0.toString());
     qDebug() << temp_items[0] << endl;
     qDebug() << temp_i/tems[0]->parentObject() << endl;
     qDebug() << temp_items[0]->parentWidget() << endl;
     qDebug() << temp_items[0]->parentItem() << endl;
     qDebug() << temp_items[0]->data(0) << endl;
     */
}


double test = 1.0;
/*
BoxPlus::BoxPlus(auto *scene, auto *ui){
    test = test+1.0;
    inputPort1.first = "number";
    inputPort1.second = test;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

    //(*ui)->label->setText("HOVNO");

    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = (*scene)->addRect(0,20,100,300,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    item->setData(0,inputPort1.second);
    auto custom_combo_box = new QComboBox();
    auto c2ustom_combo_box = new QComboBox();

    QGraphicsProxyWidget* pMyProxy = new QGraphicsProxyWidget(item);
    QGraphicsProxyWidget* pMyProxy2 = new QGraphicsProxyWidget(item);

    pMyProxy->setWidget(custom_combo_box);
    pMyProxy2->setWidget(c2ustom_combo_box);
    pMyProxy->setPos(10,50);
    pMyProxy2->setPos(10, 100);


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
*/
/*
OutputBox::OutputBox(auto *scene, auto *ui){

    item = (*scene)->addRect(0,20,100,300,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    item->setData(0,inputPort1.second);
    auto comboBox = new QComboBox();
    auto doubleSpinBox = new QDoubleSpinBox();

    QGraphicsProxyWidget* pMyProxy = new QGraphicsProxyWidget(item);
    QGraphicsProxyWidget* pMyProxy2 = new QGraphicsProxyWidget(item);

    pMyProxy->setWidget(comboBox);
    pMyProxy2->setWidget(doubleSpinBox);
    pMyProxy->setPos(10,50);
    pMyProxy2->setPos(10, 100);

}
OutputBox::~OutputBox(){
    delete item;
}
*/

OperationBox::~OperationBox(){
    qDebug() << "mazu" << endl;
    delete MainItem;
}
OperationBox::OperationBox(auto *scene, auto *ui){
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
     qDebug() << "asdasdad" << endl;

        id = 5;
        MainItem = (*scene)->addRect(0,20,200,125,Pen,blueBrush);
        MainItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
        //MainItem->setData(0,inputPort1.second);
        auto ComboBoxInput1 = new QComboBox();
        auto ComboBoxInput2 = new QComboBox();
        auto ComboBoxOutput = new QComboBox();
        auto LabelName = new QLabel("+");

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

        ComboProxyInput1->setWidget(ComboBoxInput1);
        ComboProxyInput2->setWidget(ComboBoxInput2);
        ComboProxyOutput->setWidget(ComboBoxOutput);
        LabelProxyName->setWidget(LabelName);

        ComboProxyInput1->setPos(10, 45);
        ComboProxyInput2->setPos(10, 105);
        ComboProxyOutput->setPos(115,76 );
        LabelProxyName->setPos(150,35);

        qDebug() << "konec" << endl;
}
