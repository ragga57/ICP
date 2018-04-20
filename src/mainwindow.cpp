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
   // qDebug() << "neco" << endl;
    BoxPlus *newBox = new BoxPlus(&scene,&ui);

   // qDebug() << "vnitrek " << newBox->getData("inputPort1").first <<","<< newBox->getData("inputPort1").second << endl;


}


BoxPlus::BoxPlus(auto *scene,auto *ui){

    inputPort1.first = "number";
    inputPort1.second = 0.0;
    inputPort2.first = "number";
    inputPort2.second = 0.0;
    outputPort.first = "number";
    outputPort.second = 0.0;

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
