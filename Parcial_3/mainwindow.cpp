#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,-600,800,600);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);

    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSimular_clicked()
{
    double x=ui->LE_Posx->text().toDouble();
    double y=ui->LE_Posy->text().toDouble();
    double v= ui->LE_Vel->text().toDouble();
    double a= ui->lineEdit_4->text().toDouble();
    a=(a*3.14159)/180;
    //cuerpo= new Particula(x,y,v,a);
    Particulas.push_back(new Misil(x,y,v,a));
    escena->addItem(Particulas.back());
    timer->start(5);
}

void MainWindow::Mover()
{
    QList<Misil*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++)
       (*it)->ActualizarPosicion();
}
