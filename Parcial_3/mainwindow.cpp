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
        if(xD < 300 || xD > 900) throw 2;//si el defensivo esta muy cerca o muy lejos
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

        //Inicio_de_ataques();
        DisparoOfensivo();

        imprimirVectores();
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
{/*
    QList<Misil*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++)
       (*it)->ActualizarPosicion();
       */
}

void MainWindow::imprimirVectores()
{
    for (int i=0; i<3; i++) {
        for (int i=0; i<3; i++) {
            for (int i=0; i<3; i++) {

            }
        }
    }
}

/*
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

                    misil = new Misil(canion1->getPosx(), canion1->getPosy(), velocidades, angulos, velocidadx, velocidady);


                    if(ofensivos_efectivos == 3){
                        //QMessageBox::information(this, "Información", "3 disparos efectivos");
                        //break;
                    }


                    //analizamos la reaccion DEFENSIVA
                    if(tiempos>2){
                        //3 disparos defensivos
                        DisparoDefensivo(misil, tiempos);
                    }
                    break;

                }
            }
            if(ofensivos_efectivos == 3) break;
        }
        if(ofensivos_efectivos == 3) break;
    }
   ofensivos_efectivos = 0;
}
*/



void MainWindow::DisparoOfensivo(){



    int flag = 0;
    float x = 0.0;
    float y = 0.0;

    OFENSIVO = new Misil(canion1->getPosx(), canion1->getPosy());
    DEFENSIVO = new Misil(canion2->getPosx(), canion2->getPosy());

    for(int angulo = 1; angulo < 90 ; angulo++){
        OFENSIVO->setAng(angulo);//Angulo
        for(float velocidad = 50; velocidad < 100 ; velocidad += 5){
            OFENSIVO->setVel(velocidad);
            OFENSIVO->setVelx(velocidad*cos(OFENSIVO->getAng()*pi/180));  //Vellocidad X
            OFENSIVO->setVely(velocidad*sin(OFENSIVO->getAng()*pi/180));  //Vellocidad Y
            OFENSIVO->setR(0.05*(DEFENSIVO->getPosx())); //0.05*d __ distancia entre caniones
            x = 0.0;
            y = 0.0;
            for(float t = 0; ; t+= 0.05){
                x = OFENSIVO->getVelx()*t;
                y = OFENSIVO->getPosy()+ OFENSIVO->getVely()*t -(0.5*9.81*t*t);
                //Verificar impacto
                //comprobar que este en el radio de impacto
                //distancia entre dos puntos (bala y DEFENSIVO) < radio de explosion
                if(sqrt(pow((canion2->getPosx() - x),2)+pow((canion2->getPosy() - y),2)) < OFENSIVO->getR()){
                    if(y<0) y = 0;

                    //add al vector
                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    ofensivos3.push_back(misil_cargador);

                    //Creamos la reaccion DEFENSIVA
                    if(t>2){
                        //3 disparos defensivos
                        DisparoDefensivo(t);

                    }
                    flag++;
                    angulo += 5;
                    velocidad += 10;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
}

void MainWindow::DisparoDefensivo(float Limite_tiempo){

    float xo = 0.0;
    float yo = 0.0;
    float xd = 0.0;
    float yd = 0.0;
    int flag = 0;

    //Generar disparo defensivo
    for(int angulo = 180; angulo > 90 ; angulo--){
        DEFENSIVO->setAng(angulo); //Angulo
        for(float velocidad = 50; velocidad < 100 ; velocidad += 5){
            DEFENSIVO->setVel(velocidad);
            DEFENSIVO->setVelx(velocidad*cos(DEFENSIVO->getAng()*pi/180));  //Vellocidad X
            DEFENSIVO->setVely(velocidad*sin(DEFENSIVO->getAng()*pi/180));  //Vellocidad Y
            DEFENSIVO->setR(0.025*(DEFENSIVO->getPosx())); //0.025*d __ distancia entre caniones

            for(float t2 = 0; t2<Limite_tiempo ; t2 += 0.05){
                xd = (DEFENSIVO->getVelx()*t2)+DEFENSIVO->getPosx();
                yd = DEFENSIVO->getPosy() + DEFENSIVO->getVely()*t2 - (0.5*9.81*t2*t2);
                float t = t2+2;
                xo = OFENSIVO->getVelx()*t;
                yo = OFENSIVO->getPosy() + OFENSIVO->getVely()*t - (0.5*9.81*t*t);
                //Verificar impacto
                //comprobar que este en el radio de impacto
                //distancia entre dos puntos (bala y DEFENSIVO) < radio de explosion
                if(sqrt(pow((xo - xd),2)+pow((yo - yd),2)) <= OFENSIVO->getR()){
                    if(yd<0) yd = 0;

                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    defensivos9.push_back(misil_cargador);

                     //Creamos la reaccion NEUTRALIZAR
                    if(t>1){
                        //3 disparos NEUTRALES
                        DisparoNeutral(t2);

                    }
                    flag++;
                    angulo -= 5;
                    velocidad += 10;
                    break;
                }
                if(yd < 0) break;
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
}

void MainWindow::DisparoNeutral(float Limite_tiempo){

    float xo = 0.0;
    float yo = 0.0;
    float xd = 0.0;
    float yd = 0.0;
    int flag = 0;

    //Generar disparo NEUTRAL
    for(float angulo = 1; angulo < 90 ; angulo+=0.5){
        OFENSIVO->setAng(angulo);
        for(float velocidad = 600; velocidad < 1200 ; velocidad += 1){
            OFENSIVO->setVel(velocidad); //Angulo
            OFENSIVO->setVelx(velocidad*cos(OFENSIVO->getAng()*pi/180));  //Vellocidad X
            OFENSIVO->setVely(velocidad*sin(OFENSIVO->getAng()*pi/180));  //Vellocidad Y
            OFENSIVO->setR(0.005*(DEFENSIVO->getPosx())); //0.005*d __ distancia entre caniones

            for(float t2 = 0; t2<Limite_tiempo ; t2 += 0.025){
                xo = OFENSIVO->getVelx()*t2;
                yo = OFENSIVO->getPosy() + OFENSIVO->getVely()*t2 - (0.5*9.81*t2*t2);
                float t = t2+1;
                xd = (DEFENSIVO->getVelx()*t)+DEFENSIVO->getPosx();
                yd = DEFENSIVO->getPosy() + DEFENSIVO->getVely()*t - (0.5*9.81*t*t);
                //Verificar impacto
                //comprobar que este en el radio de impacto
                //distancia entre dos puntos (Neutralizador y DEFENSIVO) < radio de explosion
                if(sqrt(pow((xo - xd),2)+pow((yo - yd),2)) <= OFENSIVO->getR()){
                    if(yd<0) yd = 0;

                    //add vector neutral
                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    neutrales27.push_back(misil_cargador);

                    flag++;
                    angulo += 5;
                    velocidad += 10;
                    break;
                }
                if(yd < 0) break;
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
}

