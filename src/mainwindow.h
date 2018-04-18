#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *);


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
     bool m_clicked = false;
     QGraphicsScene *scene;
     QGraphicsRectItem *rectangle;
};

#endif // MAINWINDOW_H
