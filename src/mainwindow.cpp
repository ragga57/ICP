#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"


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
    BoxPlus newBox(&scene, &ui);
    ui->label->setText("Test58");
}

void MainWindow::on_selectionChanged(){
    ui->label->setText("Test69");
    auto temp_items = scene->selectedItems();
     qDebug() << temp_items[0] << endl;
     qDebug() << temp_items[0]->parentObject() << endl;
     qDebug() << temp_items[0]->parentWidget() << endl;
     qDebug() << temp_items[0]->parentItem() << endl;
     qDebug() << temp_items[0]->data(0) << endl;
}


double test = 1.0;
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
    QGraphicsRectItem *item = (*scene)->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    item->setData(0,inputPort1.second);
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
