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
 //   ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    id = 0;
    availablePorts.append(defaultPort);
    connect(scene, SIGNAL (selectionChanged()), this, SLOT (on_selectionChanged()));
    //qDebug() <<"Main Windows Consturctor" << endl;
    qWarning() << "FUCK YOU QT" << endl;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
void MainWindow::updatePorts(){

    //projde listy a naplni hodnotama
    for(auto &i: inputBoxesList){
        updateInputBoxPort(i);
    }
    for(auto &i: operationBoxesList){
        updateOperationBoxPort(i,"in1");
        updateOperationBoxPort(i,"in2");
        updateOperationBoxPort(i,"out");
    }
    for(auto &i: outputBoxesList){
        updateOutputBoxPort(i);
    }
}
void MainWindow::updateInputBoxPort(auto &i){
    QString currVal;
    QString currBoxId = QString::number(i->id);
    QList<QString> tmpList;
    int temp_index = 0;

        //ulozi selected, vymaze puvodni stav, vytvori potrebny regex

            currVal = i->comboBoxOutput->currentText();
            i->comboBoxOutput->clear();
        QRegExp regEx(".{1,4}-out");
        //do input portu muzou prijit jen output porty a naopak takze osetreni
        for(auto &list: availablePorts){
            if (!regEx.exactMatch(list)){
                tmpList.append(list);
            }
        }
        //naplni novyma hodnotama, smaze self porty a da zpatky selected

             i->comboBoxOutput->addItems(tmpList);
             //smaze z listu self porty
             //i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-out")));
             //i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-in1")));
             //i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-in2")));
             //da zpatky ten selected
             temp_index = i->comboBoxOutput->findText(currVal);
             //osetreni 2x stejne hodnoty pri vkladani selected
             if(temp_index >= 0){
                 i->comboBoxOutput->setCurrentIndex(temp_index);
             }
             else{
                 i->comboBoxOutput->setCurrentIndex(0);
             }


        tmpList.clear();



}

void MainWindow::updateOperationBoxPort(auto &i,QString port){
    QString currVal;
    QString specRegExp;
    QString currBoxId = QString::number(i->id);
    QList<QString> tmpList;
    int temp_index = 0;

        //ulozi selected, vymaze puvodni stav, vytvori potrebny regex
        if (port == "in1"){
            currVal = i->comboBoxInput1->currentText();
            i->comboBoxInput1->clear();
            specRegExp = ".{1,4}-in.{1}";
        }else if(port == "in2"){
            currVal = i->comboBoxInput2->currentText();
            i->comboBoxInput2->clear();
            specRegExp = ".{1,4}-in.{1}";
        }else{
            currVal = i->comboBoxOutput->currentText();
            i->comboBoxOutput->clear();
            specRegExp = ".{1,4}-out";
        }
        QRegExp regEx(specRegExp);
        //do input portu muzou prijit jen output porty a naopak takze osetreni
        for(auto &list: availablePorts){
            if (!regEx.exactMatch(list)){
                tmpList.append(list);
            }
        }
        //naplni novyma hodnotama, smaze self porty a da zpatky selected
        if (port == "in1"){
            i->comboBoxInput1->addItems(tmpList);
            //smaze z listu self porty
            i->comboBoxInput1->removeItem(i->comboBoxInput1->findText(currBoxId+QString("-out")));
            //da zpatky ten selected
            temp_index = i->comboBoxInput1->findText(currVal);
            //osetreni 2x stejne hodnoty pri vkladani selected
            if(temp_index >= 0){
                i->comboBoxInput1->setCurrentIndex(temp_index);
            }
            else{
                i->comboBoxInput1->setCurrentIndex(0);
            }
        }else if(port == "in2"){
            i->comboBoxInput2->addItems(tmpList);
            //smaze z listu self porty
            i->comboBoxInput2->removeItem(i->comboBoxInput2->findText(currBoxId+QString("-out")));
            //da zpatky ten selected
            temp_index = i->comboBoxInput2->findText(currVal);
            //osetreni 2x stejne hodnoty pri vkladani selected
            if(temp_index >= 0){
                i->comboBoxInput2->setCurrentIndex(temp_index);
            }
            else{
                i->comboBoxInput2->setCurrentIndex(0);
            }
        }else{
             i->comboBoxOutput->addItems(tmpList);
             //smaze z listu self porty
             //i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-out")));
             i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-in1")));
             i->comboBoxOutput->removeItem(i->comboBoxOutput->findText(currBoxId+QString("-in2")));
             //da zpatky ten selected
             temp_index = i->comboBoxOutput->findText(currVal);
             //osetreni 2x stejne hodnoty pri vkladani selected
             if(temp_index >= 0){
                 i->comboBoxOutput->setCurrentIndex(temp_index);
             }
             else{
                 i->comboBoxOutput->setCurrentIndex(0);
             }
        }

        tmpList.clear();

}

void MainWindow::updateOutputBoxPort(auto &i){
    QString currVal;
    QString currBoxId = QString::number(i->id);
    QList<QString> tmpList;
    int temp_index = 0;

        //ulozi selected, vymaze puvodni stav, vytvori potrebny regex

            currVal = i->comboBoxInput1->currentText();
            i->comboBoxInput1->clear();
        QRegExp regEx(".{1,4}-in.{1}");
        //do input portu muzou prijit jen output porty a naopak takze osetreni
        for(auto &list: availablePorts){
            if (!regEx.exactMatch(list)){
                tmpList.append(list);
            }
        }
        //naplni novyma hodnotama, smaze self porty a da zpatky selected

            i->comboBoxInput1->addItems(tmpList);
            //smaze z listu self porty
            i->comboBoxInput1->removeItem(i->comboBoxInput1->findText(currBoxId+QString("-out")));
            //da zpatky ten selected
            temp_index = i->comboBoxInput1->findText(currVal);
            //osetreni 2x stejne hodnoty pri vkladani selected
            if(temp_index >= 0){
                i->comboBoxInput1->setCurrentIndex(temp_index);
            }
            else{
                i->comboBoxInput1->setCurrentIndex(0);
            }


        tmpList.clear();

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
     //qDebug() << temp_items[0] << endl;
     //qDebug() << temp_items[0]->parentObject() << endl;
     //qDebug() << temp_items[0]->parentWidget() << endl;
     //qDebug() << temp_items[0]->parentItem() << endl;
     //qDebug() << temp_items[0]->data(0) << endl;
}

void MainWindow::on_deleteButton_clicked(OperationBox *toDelete){
   // delete MainItem;
    qWarning() << "DELETE" << endl;
}

void MainWindow::on_plusBoxButton_clicked()
{
    qWarning() << &operationBoxesList <<endl;
    //int test = boxesList;
    OperationBox *temp = new OperationBox(&scene, operationBoxesList);
    temp->id = id;
    temp->type = "+";
    temp->labelType->setText("+");
    temp->labelName->setText(QString("obj ")+QString::number(id));

            //toto by asi slo do konstruktoru
            temp->comboBoxInput1->setCurrentText(defaultPort);
            temp->comboBoxInput2->setCurrentText(defaultPort);
            temp->comboBoxOutput->setCurrentText(defaultPort);

    operationBoxesList.append(temp);
    //qWarning() << boxesList <<endl;
    qWarning() << "PUSH button" << operationBoxesList <<endl;
    ui->label->setText("Test58");
    availablePorts.append(QString::number(id)+QString("-in1"));
    availablePorts.append(QString::number(id)+QString("-in2"));
    availablePorts.append(QString::number(id)+QString("-out"));
    qWarning() <<"pushButton" << endl;
    qWarning() << "FUCK YOU QT" << endl;
    for(auto &i: availablePorts)
        qDebug() << i << endl;

    id++;
    updatePorts();

     connect(temp, SIGNAL (sigOnChangeIn1(QString, QString)), this, SLOT(onChangeIn1Main(QString, QString)));
     connect(temp, SIGNAL (sigOnChangeOut(QString, QString)), this, SLOT(onChangeOutMain(QString, QString)));
}

void MainWindow::on_inputButton_clicked()
{
    qWarning() << &inputBoxesList <<endl;
    //int test = boxesList;
    InputBox *temp = new InputBox(&scene, inputBoxesList);
    temp->id = id;
    temp->labelName->setText(QString("obj ")+QString::number(id));

            //toto by asi slo do konstruktoru
            temp->comboBoxOutput->setCurrentText(defaultPort);

    inputBoxesList.append(temp);
    //qWarning() << boxesList <<endl;
    qWarning() << "PUSH button" << inputBoxesList <<endl;
    ui->label->setText("Test58");
    availablePorts.append(QString::number(id)+QString("-out"));
    for(auto &i: availablePorts)
        qDebug() << i << endl;

    id++;
    updatePorts();
}

void MainWindow::drawLines(){
    QBrush blueBrush(Qt::blue);
    QPen Pen(Qt::black);
    qWarning() << "Drawing Lines" << endl;
    for(auto &i: operationBoxesList){
        QString start_in1_text = i->comboBoxInput1->currentText();
        QString start_in2_text = i->comboBoxInput2->currentText();
        QString start_out_text = i->comboBoxOutput->currentText();

        int start_in1_x = i->mainItem->pos().x(); // TODO: OFFSETS
        int start_in1_y = i->mainItem->pos().y();
        int start_in2_x = i->mainItem->pos().x();
        int start_in2_y = i->mainItem->pos().y();
        int start_out_x = i->mainItem->pos().x();
        int start_out_y = i->mainItem->pos().y();
       for(auto &j: operationBoxesList){
           QStringList start_in1_text_split = start_in1_text.split('-');
           QStringList start_in2_text_split = start_in2_text.split('-');
           QStringList start_out_text_split = start_out_text.split('-');

           if (QString::number(j->id) == start_in1_text_split[0]){

               //TODO OFFSETS BASED ON WHICH PORT SAME SHIT JUST CONDITION FOR out
               // TODO PUSHOVANIE DO LISTU
                int end_x = j->mainItem->pos().x();
                int end_y = j->mainItem->pos().y();
                QGraphicsLineItem *line = (*scene).addLine(start_in1_x, start_in1_y, end_x, end_y,Pen);
           }

           if (QString::number(j->id) == start_in2_text_split[0]){

               //TODO OFFSETS BASED ON WHICH PORT SAME SHIT JUST CONDITION FOR out
                int end_x = j->mainItem->pos().x();
                int end_y = j->mainItem->pos().y();
                QGraphicsLineItem *line = (*scene).addLine(start_in2_x, start_in2_y, end_x, end_y,Pen);
           }
           if (QString::number(j->id) == start_out_text_split[0]){

               //TODO OFFSETS BASED ON WHICH PORT SAME SHIT JUST CONDITION FOR in1/in2
                int end_x = j->mainItem->pos().x();
                int end_y = j->mainItem->pos().y();
                QGraphicsLineItem *line = (*scene).addLine(start_out_x, start_out_y, end_x, end_y,Pen);
           }

       }

    }
}

void MainWindow::onChangeIn1Main(QString in_port, QString out_port){
    qWarning() << "Main on change1" <<endl;
    qWarning() << in_port <<endl;
    qWarning() << out_port << endl;

    QStringList in_temp = in_port.split('-');
    QStringList out_temp = out_port.split('-');






    for(auto &i: operationBoxesList){
        if (QString::number(i->id) == out_temp[0]){

            int temp_index = i->comboBoxOutput->findText(in_port);
            //osetreni 2x stejne hodnoty pri vkladani selected
            if(temp_index >= 0){
                i->comboBoxOutput->setCurrentIndex(temp_index);
            }
            else{
                i->comboBoxOutput->setCurrentIndex(0);
            }
        }
    }

    drawLines();

}

void MainWindow::onChangeOutMain(QString in_port, QString out_port){

    QStringList in_temp = in_port.split('-');
    QStringList out_temp = out_port.split('-');

    for(auto &i: operationBoxesList){
        if (QString::number(i->id) == in_temp[0]){

            if(in_temp[1] == "in1"){
                int temp_index = i->comboBoxInput1->findText(out_port);
                //osetreni 2x stejne hodnoty pri vkladani selected
                if(temp_index >= 0){
                    i->comboBoxInput1->setCurrentIndex(temp_index);
                }
                else{
                    i->comboBoxInput1->setCurrentIndex(0);
                }
            }
            else if (in_temp[1] == "in2"){
                int temp_index = i->comboBoxInput2->findText(out_port);
                //osetreni 2x stejne hodnoty pri vkladani selected
                if(temp_index >= 0){
                    i->comboBoxInput2->setCurrentIndex(temp_index);
                }
                else{
                    i->comboBoxInput2->setCurrentIndex(0);
                }
            }
        }
    }

    drawLines();
}

void MainWindow::on_outputButton_clicked()
{
    qWarning() << &outputBoxesList <<endl;
    //int test = boxesList;
    OutputBox *temp = new OutputBox(&scene, outputBoxesList);
    temp->id = id;
    temp->labelName->setText(QString("obj ")+QString::number(id));

            //toto by asi slo do konstruktoru
            temp->comboBoxInput1->setCurrentText(defaultPort);

    outputBoxesList.append(temp);
    //qWarning() << boxesList <<endl;
    qWarning() << "PUSH button" << outputBoxesList <<endl;
    ui->label->setText("Test58");
    availablePorts.append(QString::number(id)+QString("-in1"));
    for(auto &i: availablePorts)
        qDebug() << i << endl;

    id++;
    updatePorts();

}

OperationBox::OperationBox(auto *scene,QList<OperationBox*> &boxesList){
    inputPort1.first = "number";
    inputPort1.second = 0.0;
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
    mainItem = (*scene)->addRect(0,20,200,125,Pen,blueBrush);
    mainItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    mainItem->setData(0,inputPort1.second);
    comboBoxInput1 = new QComboBox();
    comboBoxInput2 = new QComboBox();
    comboBoxOutput = new QComboBox();
    labelType = new QLabel();
    labelName = new QLabel();

    deleteButton = new QPushButton();

    comboBoxInput1->setFixedHeight(25);
    comboBoxInput1->setFixedWidth(75);
    comboBoxInput2->setFixedHeight(25);
    comboBoxInput2->setFixedWidth(75);
    comboBoxOutput->setFixedHeight(25);
    comboBoxOutput->setFixedWidth(75);

    labelType->setFixedHeight(25);
    labelType->setFixedWidth(25);
    labelName->setFixedHeight(25);
    labelName->setFixedWidth(60);

    QFont font = labelType->font();
    font.setPointSize(20);
    font.setBold(true);
    labelType->setFont(font);
    labelType->setAlignment(Qt::AlignCenter);
    labelType->setAutoFillBackground(false);
    labelType->setStyleSheet("background:transparent");

    labelName->setFont(font);
    labelName->setAutoFillBackground(false);
    labelName->setStyleSheet("background:transparent");


    QGraphicsProxyWidget* comboProxyInput1 = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* comboProxyInput2 = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* comboProxyOutput = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* labelTypeProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* labelNameProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* deleteProxyButton = new QGraphicsProxyWidget(mainItem);

    comboProxyInput1->setWidget(comboBoxInput1);
    comboProxyInput2->setWidget(comboBoxInput2);
    comboProxyOutput->setWidget(comboBoxOutput);
    labelTypeProxyName->setWidget(labelType);
    labelNameProxyName->setWidget(labelName);
    deleteProxyButton->setWidget(deleteButton);

    comboProxyInput1->setPos(10, 45);
    comboProxyInput2->setPos(10, 105);
    comboProxyOutput->setPos(115,76 );
    labelTypeProxyName->setPos(150,35);
    labelNameProxyName->setPos(0,-5);
    deleteProxyButton->setPos(150,200);

    qWarning() << "PRE SIGNAL" << endl;

    connect(comboBoxInput1, SIGNAL (currentIndexChanged(QString)), this, SLOT(onChangeIn1(QString)));
    connect(comboBoxInput2, SIGNAL (currentIndexChanged(QString)), this, SLOT(onChangeIn2(QString)));
    connect(comboBoxOutput, SIGNAL (currentIndexChanged(QString)), this, SLOT(onChangeOut(QString)));
    connect(deleteButton, SIGNAL (clicked()), this, SLOT (on_deleteButton_clicked()));
    qWarning() << "POST SIGNAL" << endl;
   // item->setData(1,toString(this));
   // item->setParentItem(&this);
}

OperationBox::~OperationBox(){

}

bool OperationBox::calculate(){

}

void OperationBox::on_deleteButton_clicked(){
    QObject *temp = sender();
    qWarning() << temp << endl;
    qWarning() << "this : " << this << endl;

    qWarning() << "Pred" <<endl;
    qWarning() << "index" << &(*boxesListTemp->at(0)) << endl;
    qWarning() << "index of" << ((*boxesListTemp).indexOf(this)) << endl;

    qWarning() << *boxesListTemp <<endl;

    //QList<BoxPlus *> templist = w.getList();
    delete mainItem;
    int temp2 = ((*boxesListTemp).indexOf(this));
    (*boxesListTemp).removeAt(temp2);

    qWarning() << "Po" <<endl;
    qWarning() << *boxesListTemp <<endl;

    qWarning() << "DELETE" << endl;
}
void OperationBox::onChangeIn1(QString port_name){
   // qWarning() << sender()->parentWidget() << endl;
    qWarning() << this << endl;
    qWarning() << sender() << endl;
    qWarning() << "Changed index:" << port_name << endl;
    QString in_port = QString::number(id) + "-in1";
    qWarning() <<"In port: "  <<in_port << endl;
    QString out_port = port_name ;
    qWarning() <<"Out port: "<< out_port << endl;
    emit sigOnChangeIn1(in_port, out_port);
}

void OperationBox::onChangeIn2(QString port_name){
   // qWarning() << sender()->parentWidget() << endl;
    qWarning() << this << endl;
    qWarning() << sender() << endl;
    qWarning() << "Changed index:" << port_name << endl;
    QString in_port = QString::number(id) + "-in2";
    qWarning() <<"In port: "  <<in_port << endl;
    QString out_port = port_name ;
    qWarning() <<"Out port: "<< out_port << endl;
    emit sigOnChangeIn1(in_port, out_port);
}

void OperationBox::onChangeOut(QString port_name){
   // qWarning() << sender()->parentWidget() << endl;
    qWarning() << this << endl;
    qWarning() << sender() << endl;
    qWarning() << "Changed index:" << port_name << endl;
    QString in_port = port_name;
    qWarning() <<"In port: "  <<in_port << endl;
    QString out_port = QString::number(id) + "-out";
    qWarning() <<"Out port: "<< out_port << endl;
    emit sigOnChangeOut(in_port, out_port);
}

InputBox::InputBox(auto *scene,QList<InputBox*> &boxesList){

    outputPort.first = "nonValid";
    outputPort.second = 0.0;

    qWarning() << &boxesList << endl;

    boxesListTemp = &boxesList;

    qWarning() << "InputBox Const" << boxesListTemp << endl;
    //(*ui)->label->setText("HOVNO");

    QBrush blueBrush(Qt::yellow);
    QPen Pen(Qt::black);
    mainItem = (*scene)->addRect(0,20,200,125,Pen,blueBrush);
    mainItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    //mainItem->setData(0,inputPort1.second);

    comboBoxOutput = new QComboBox();
    labelName = new QLabel();
    inputSpinBox = new QDoubleSpinBox();

    deleteButton = new QPushButton();

    comboBoxOutput->setFixedHeight(25);
    comboBoxOutput->setFixedWidth(75);
    labelName->setFixedHeight(25);
    labelName->setFixedWidth(60);
    inputSpinBox->setFixedHeight(25);
    inputSpinBox->setFixedWidth(75);

    QFont font = labelName->font();
    font.setPointSize(20);
    font.setBold(true);

    labelName->setFont(font);
    labelName->setAutoFillBackground(false);
    labelName->setStyleSheet("background:transparent");

    QGraphicsProxyWidget* comboProxyOutput = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* labelNameProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* inputSpinBoxProxy = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* deleteProxyButton = new QGraphicsProxyWidget(mainItem);

    comboProxyOutput->setWidget(comboBoxOutput);
    labelNameProxyName->setWidget(labelName);
    inputSpinBoxProxy->setWidget(inputSpinBox);
    deleteProxyButton->setWidget(deleteButton);

    comboProxyOutput->setPos(115,76 );
    labelNameProxyName->setPos(0,-5);
    inputSpinBoxProxy->setPos(50,30);
    deleteProxyButton->setPos(150,200);

    qWarning() << "PRE SIGNAL" << endl;

    connect(deleteButton, SIGNAL (clicked()), this, SLOT (on_deleteButton_clicked()));
    qWarning() << "POST SIGNAL" << endl;
   // item->setData(1,toString(this));
   // item->setParentItem(&this);
}

InputBox::~InputBox(){

}

void InputBox::on_deleteButton_clicked(){
    QObject *temp = sender();
    qWarning() << temp << endl;
    qWarning() << "this : " << this << endl;

    qWarning() << "Pred" <<endl;
    qWarning() << "index" << &(*boxesListTemp->at(0)) << endl;
    qWarning() << "index of" << ((*boxesListTemp).indexOf(this)) << endl;

    qWarning() << *boxesListTemp <<endl;

    //QList<BoxPlus *> templist = w.getList();
    delete mainItem;
    int temp2 = ((*boxesListTemp).indexOf(this));
    (*boxesListTemp).removeAt(temp2);

    qWarning() << "Po" <<endl;
    qWarning() << *boxesListTemp <<endl;

    qWarning() << "DELETE" << endl;
}


OutputBox::OutputBox(auto *scene,QList<OutputBox*> &boxesList){

    inputPort1.first = "nonValid";
    inputPort1.second = 0.0;

    qWarning() << &boxesList << endl;

    boxesListTemp = &boxesList;

    qWarning() << "InputBox Const" << boxesListTemp << endl;
    //(*ui)->label->setText("HOVNO");

    QBrush blueBrush(Qt::green);
    QPen Pen(Qt::black);
    mainItem = (*scene)->addRect(0,20,200,125,Pen,blueBrush);
    mainItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    //mainItem->setData(0,inputPort1.second);

    comboBoxInput1 = new QComboBox();
    resultLabel = new QLabel();
    result = new QLineEdit();
    labelName = new QLabel();
    deleteButton = new QPushButton();

    comboBoxInput1->setFixedHeight(25);
    comboBoxInput1->setFixedWidth(75);
    resultLabel->setFixedHeight(25);
    resultLabel->setFixedWidth(60);
    result->setFixedHeight(25);
    result->setFixedWidth(75);

    labelName->setFixedHeight(25);
    labelName->setFixedWidth(60);

    QFont font = labelName->font();
    font.setPointSize(20);
    font.setBold(true);

    labelName->setFont(font);
    labelName->setAutoFillBackground(false);
    labelName->setStyleSheet("background:transparent");

    resultLabel->setFont(font);
    resultLabel->setAutoFillBackground(false);
    resultLabel->setStyleSheet("background:transparent");

    QGraphicsProxyWidget* comboProxyInput = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* labelNameProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* resultLabelProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* resultProxyName = new QGraphicsProxyWidget(mainItem);
    QGraphicsProxyWidget* deleteProxyButton = new QGraphicsProxyWidget(mainItem);

    comboProxyInput->setWidget(comboBoxInput1);
    labelNameProxyName->setWidget(labelName);
    resultLabelProxyName->setWidget(resultLabel);
    resultProxyName->setWidget(result);
    deleteProxyButton->setWidget(deleteButton);

    comboProxyInput->setPos(115,76 );
    labelNameProxyName->setPos(0,-5);
    resultLabelProxyName->setPos(70,70);
    resultProxyName->setPos(50,50);
    deleteProxyButton->setPos(150,200);

    qWarning() << "PRE SIGNAL" << endl;

    connect(deleteButton, SIGNAL (clicked()), this, SLOT (on_deleteButton_clicked()));
    qWarning() << "POST SIGNAL" << endl;
   // item->setData(1,toString(this));
   // item->setParentItem(&this);
}

OutputBox::~OutputBox(){

}

void OutputBox::on_deleteButton_clicked(){
    QObject *temp = sender();
    qWarning() << temp << endl;
    qWarning() << "this : " << this << endl;

    qWarning() << "Pred" <<endl;
    qWarning() << "index" << &(*boxesListTemp->at(0)) << endl;
    qWarning() << "index of" << ((*boxesListTemp).indexOf(this)) << endl;

    qWarning() << *boxesListTemp <<endl;

    //QList<BoxPlus *> templist = w.getList();
    delete mainItem;
    int temp2 = ((*boxesListTemp).indexOf(this));
    (*boxesListTemp).removeAt(temp2);

    qWarning() << "Po" <<endl;
    qWarning() << *boxesListTemp <<endl;

    qWarning() << "DELETE" << endl;
}


