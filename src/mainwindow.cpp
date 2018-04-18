#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    Pen.setWidth(6);
    QPainter painter(this);
    QRectF rect;
    Pen.setWidth(2);
    painter.setPen(Pen);
    rect.bottom();
    ui->graphicsView->setScene(scene);
    //scene->addRect(0,20,40,30,Pen,blueBrush);
    QGraphicsRectItem *item = scene->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{   /*
    m_clicked = true;
    update();
    */
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    QGraphicsRectItem *item = scene->addRect(0,20,40,30,Pen,blueBrush);
    item->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    /*
    QPainter p(this);
    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
    QRectF rectangle2(100.0, 20.0, 80.0, 60.0);
    if(m_clicked){
        p.setBrush(Qt::red);
        p.drawRect(rectangle);
    }else{
        p.setBrush(Qt::blue);
        p.drawRect(rectangle2);
    }
    */

}





void MainWindow::on_pushButton_2_clicked()
{
    m_clicked = false;
    update();
}
