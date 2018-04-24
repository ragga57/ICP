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

<<<<<<< HEAD
=======
    connect(scene, SIGNAL (selectionChanged()), this, SLOT (on_selectionChanged()));
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::on_pushButton_clicked()
<<<<<<< HEAD
{
   // qDebug() << "neco" << endl;
    BoxPlus *newBox = new BoxPlus(&scene,&ui);

   // qDebug() << "vnitrek " << newBox->getData("inputPort1").first <<","<< newBox->getData("inputPort1").second << endl;

=======
{   /*
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = scene->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    */
    BoxPlus newBox(&scene, &ui);
    ui->label->setText("Test58");
}
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f

void MainWindow::on_selectionChanged(){
    ui->label->setText("Test69");
    // pri kliknuti do sceny crash...
    auto temp_items = scene->selectedItems();
    QVariant data0 = temp_items[0]->data(0);
    ui->label->setText(data0.toString());
     qDebug() << temp_items[0] << endl;
     qDebug() << temp_items[0]->parentObject() << endl;
     qDebug() << temp_items[0]->parentWidget() << endl;
     qDebug() << temp_items[0]->parentItem() << endl;
     qDebug() << temp_items[0]->data(0) << endl;
}


<<<<<<< HEAD
BoxPlus::BoxPlus(auto *scene,auto *ui){

=======
double test = 1.0;
BoxPlus::BoxPlus(auto *scene, auto *ui){
    test = test+1.0;
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
    inputPort1.first = "number";
    inputPort1.second = test;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

<<<<<<< HEAD
    //funguje
    //qDebug() << "tady " << (*ui)->label->text() << endl;
    //nefunguje
    //(*ui)->label->setText("HOVNO");
    //qDebug() << "tady " << (*ui)->label->text() << endl;



    QBrush blueBrush(Qt::yellow);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = (*scene)->addRect(0,20,150,150,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);


    //QLabel *label = new QLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);
    //label->setText("newBoxLabel");

    //qDebug() << "titulek " << label->text() << endl;
=======
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
>>>>>>> 4d6a35fee6076d62405f9ed8d9fc041dbe73ba7f
}
BoxPlus::~BoxPlus(){

}
void BoxPlus::calculate(QPair<QString, double> opt1, QPair<QString, double> opt2){
    if (opt1.first == "number" && opt2.first == "number" && outputPort.first == "number"){
        outputPort.second = opt1.second + opt2.second;
    }

}
