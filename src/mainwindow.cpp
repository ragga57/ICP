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
{
    qDebug() << "neco" << endl;
    BoxPlus *newBox = new BoxPlus();
    qDebug() << "vnitrek " << newBox->getData("inputPort1").first <<" "<< newBox->getData("inputPort1").second << endl;


}


BoxPlus::BoxPlus(){
    inputPort1.first = "number";
    inputPort1.second = 0.0;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

    qDebug() << "tady " << ui->label->text() << endl;
    ui->label->setText("HOVNO");
    ui->label->update();
    ui->label->setText("PROC");

    //QLabel *label = new QLabel(this);
    //label->setText("newBoxLabel");
    QBrush blueBrush(Qt::yellow);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = scene->addRect(0,20,150,150,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}
BoxPlus::~BoxPlus(){
   // delete label;

}
QPair<QString, double> BoxPlus::getData(QString opt){
    if (opt == "inputPort1"){
        return inputPort1;
    }else{
        return inputPort2;
    }
}
void BoxPlus::calculate(QPair<QString, double> opt1, QPair<QString, double> opt2){
    if (opt1.first == "number" && opt2.first == "number" && outputPort.first == "number"){
        outputPort.second = opt1.second + opt2.second;
    }

}
