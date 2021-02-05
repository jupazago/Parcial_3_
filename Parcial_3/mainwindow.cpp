#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, -680, 1000, 450);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);
/*
    timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSimular_clicked()
{
    try {
        escena->clear();

        //Ofensivo
        double xO = ui->LE_PosxO->text().toDouble();
        double yO = ui->LE_PosyO->text().toDouble();
        //defensivo
        double xD = ui->LE_PosxD->text().toDouble();
        double yD = ui->LE_PosyD->text().toDouble();

        if(yO < 0 || yO > 450) throw 1; //si el ofensivo esta muy alto
        if(xD < 200 || xD > 900) throw 2;//si el defensivo esta muy cerca o muy lejos
        if(yD < 0 || yD > 300) throw 3; //si el defensivo esta muy alto

        //ofensivo
        canion1 = new Canion(xO, yO, 1);
        escena->addItem(canion1);

        //Defensivo
        canion2 = new Canion(xD, yD, 2);
        escena->addItem(canion2);

        //damos valor a la distancia entre caniones
        canion1->obtenerDistancia(canion2->getPosx());
        canion2->obtenerDistancia(canion1->getPosx());

        /*  Vamos a calcular 3 disparos ofensivos
         *  que afecten la integridad del canion defensivo
         *  luego los simulamos
         */

        Inicio_de_ataques();
    }
    catch (int error) {
        if(error == 1){
            QMessageBox::information(this, "Información", "Altura del cañón ofensivo inválida");
        }else if(error == 2){
            QMessageBox::information(this, "Información", "Distancia del cañón Defensivo Inválida");
        }else if(error == 3) {
            QMessageBox::information(this, "Información", "Altura del cañón Defensivo inválida");
        }
    }

    /*
    double x=ui->LE_Posx->text().toDouble();
    double y=ui->LE_Posy->text().toDouble();
    double v= ui->LE_Vel->text().toDouble();
    double a= ui->lineEdit_4->text().toDouble();



    a=(a*3.14159)/180;
    //cuerpo= new Particula(x,y,v,a);
    Particulas.push_back(new Misil(x,y,v,a));
    escena->addItem(Particulas.back());
    timer->start(5);

    */
}

void MainWindow::Mover()
{
    QList<Misil*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++)
       (*it)->ActualizarPosicion();
}

void MainWindow::Inicio_de_ataques()
{

    //Análisis de ataques comprometedores

    double velocidadx, velocidady, radio, posx, posy;

    for (int angulos = 1; angulos < 90; angulos++) {
        for (int velocidades = 40; velocidades < 125; velocidades += 5) {


            velocidadx = velocidades*cos(angulos*pi/180);  //Vellocidad X
            velocidady = velocidades*sin(angulos*pi/180);  //Vellocidad Y
            radio = 0.05*(canion2->getDistancia());        //0.05*d __ distancia entre caniones


            for (float tiempos=0; tiempos <15; tiempos += 0.1) {

                posx = velocidadx*tiempos;
                posy = canion1->getPosy() + velocidady*tiempos - (0.5*9.81*tiempos*tiempos);

                if(sqrt(pow((canion2->getPosx() - posx),2) + pow((canion2->getPosy() - posy),2)) < radio){
                    if(posy<0) posy = 0;
                    ofensivos_efectivos++;

                    angulos += 5;
                    velocidades += 10;

                    if(ofensivos_efectivos == 3){
                        QMessageBox::information(this, "Información", "3 disparos efectivos");
                        break;
                    }
                    /*

                    //Creamos la reaccion DEFENSIVA
                    if(tiempos>2){
                        //3 disparos defensivos
                        DisparoDefensivo(OFENSIVO1, DEFENSIVO1, t);
                    }
                    break;
                    */
                }
            }
            if(ofensivos_efectivos == 3) break;
        }
        if(ofensivos_efectivos == 3) break;
    }

   ofensivos_efectivos = 0;
}





