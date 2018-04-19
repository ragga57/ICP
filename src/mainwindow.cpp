#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
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

}


BoxPlus::BoxPlus(auto *scene, auto *ui){
    inputPort1.first = "number";
    inputPort1.second = 0.0;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

    (*ui)->label->setText("HOVNO");

    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = (*scene)->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}
BoxPlus::~BoxPlus(){

}
void BoxPlus::calculate(QPair<QString, double> opt1, QPair<QString, double> opt2){
    if (opt1.first == "number" && opt2.first == "number" && outputPort.first == "number"){
        outputPort.second = opt1.second + opt2.second;
    }

}
