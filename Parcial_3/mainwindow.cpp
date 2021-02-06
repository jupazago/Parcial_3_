#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,-450,900,450);
    escena->addRect(escena->sceneRect());
    ui->graphicsView->setScene(escena);

    escena->setBackgroundBrush(QPixmap(":/fondo.jpg"));
    ui->graphicsView->setScene(escena);

    //preparamos los timer que vamos a necesitar para graficar
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));

    timer_ofe = new QTimer();
    connect(timer_ofe,SIGNAL(timeout()),this,SLOT(imprimirVectores()));

    timer_defe = new QTimer();
    connect(timer_defe,SIGNAL(timeout()),this,SLOT(imprimirVectores2()));

    timer_neutral = new QTimer();
    connect(timer_neutral,SIGNAL(timeout()),this,SLOT(imprimirVectores3()));

    timer_graficos = new QTimer();
    connect(timer_graficos,SIGNAL(timeout()),this,SLOT(imprimirGraficos()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSimular_clicked()
{
    try {
        //obtenemos los valores
        //de cada line edit del formulario

        //Ofensivo
        double xO = ui->LE_PosxO->text().toDouble();
        double yO = ui->LE_PosyO->text().toDouble();
        //defensivo
        double xD = ui->LE_PosxD->text().toDouble();
        double yD = ui->LE_PosyD->text().toDouble();

        //verificamos los rangos
        //necesitamos que se encuentren correctamente
        if(yO < 0 || yO > 450) throw 1; //si el ofensivo esta muy alto
        if(xD < 300 || xD > 900) throw 2;//si el defensivo esta muy cerca o muy lejos
        if(yD < 0 || yD > 300) throw 3; //si el defensivo esta muy alto

        //los agregamos a la escena
        //ofensivo
        canion1 = new Canion(xO, yO-225, 1);
        escena->addItem(canion1);

        //Defensivo
        canion2 = new Canion(xD, yD-225, 2);
        escena->addItem(canion2);

        //damos valor a la distancia entre caniones
        canion1->obtenerDistancia(canion2->getPosx());
        canion2->obtenerDistancia(canion2->getPosx());


        /*  Vamos a calcular 3 disparos ofensivos
         *  que afecten la integridad del canion defensivo
         *  luego los simulamos
         */

        DisparoOfensivo();

        //despues de almacenar los valores que necesitamos
        //gracias a una estrcutura sencilla
        //continuamos

        /*  Aqui empezamos a graficarlos
         * a medida que se empieza atacar
         * se tomaran reacciones
         */
        timer_ofe->start(1);
        timer_graficos->start(333);


    }catch (int error) {
        if(error == 1){
            QMessageBox::information(this, "Información", "Altura del cañón ofensivo inválida");
        }else if(error == 2){
            QMessageBox::information(this, "Información", "Distancia del cañón Defensivo Inválida");
        }else if(error == 3) {
            QMessageBox::information(this, "Información", "Altura del cañón Defensivo inválida");
        }
    }
}

void MainWindow::Mover()
{
    //movimiento parabolico
    //usando en metodo de la clase misil
    QList<Misil*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++)
       (*it)->ActualizarPosicion();
}

void MainWindow::imprimirGraficos()
{
    //agregamos el rastro dependiendo de la ubicacion del misil
    QList<Misil*>::iterator it;
    for(it=Particulas.begin();it!=Particulas.end();it++){
        Particulas_graficadas.push_back(new Grafica((*it)->getPosx(), (*it)->getPosy(), (*it)->getR()));
        escena->addItem(Particulas_graficadas.back());
    }
}

void MainWindow::imprimirVectores()
{
    //empezamos a graficarlo
    if(Particulas_graficadas.size() > 0){
        QList<Grafica*>::iterator itt;
        for(itt=Particulas_graficadas.begin();itt!=Particulas_graficadas.end();itt++){
            escena->removeItem(*itt);
        }

    }
    //para mayor orden los lanzamos cada 15 segundo
    if(contador_ofensivo == 0){
        timer_ofe->setInterval(15000);
    }

    //aqui es donde toma forma nuestro movimiento y nuestro rastro graficado
    Particulas.push_back(new Misil(canion1->getPosx(), canion1->getPosy(), ofensivos3.at(contador_ofensivo).velocidad, (ofensivos3.at(contador_ofensivo).angulo*3.14159)/180));
    Particulas.back()->setR(canion1->getDistancia() * 0.05);
    escena->addItem(Particulas.back());
    timer->start(5);

    //iniciamos la reaccion defensiva
    //recordando el retraso
    timer_defe->start(2000);

    contador_ofensivo++;
    //si terminamos de recorrerlo, detenemos el timer
    if(contador_ofensivo == 3){
        timer_ofe->stop();
        contador_ofensivo = 0;
    }
}

void MainWindow::imprimirVectores2()
{
    //lo ponemos ordenado y los agregamos al grafico por medio de metodos
    timer_defe->stop();

    Particulas.push_back(new Misil(canion2->getPosx(), canion2->getPosy(), defensivos3.at(contador_defensivo).velocidad, (defensivos3.at(contador_defensivo).angulo*3.14159)/180));
    Particulas.back()->setR(canion2->getDistancia() * 0.025);
    escena->addItem(Particulas.back());
    timer->start(5);

    timer_neutral->start(1000);
    contador_defensivo++;
}

void MainWindow::imprimirVectores3()
{
    timer_neutral->stop();
    for (int i = 0; i < 3; i++) {
        Particulas.push_back(new Misil(canion1->getPosx(), canion1->getPosy(), neutrales9.at(contador_neutral).velocidad, (neutrales9.at(contador_neutral).angulo*3.14159)/180));
        Particulas.back()->setR(canion2->getDistancia() * 0.005);
        escena->addItem(Particulas.back());
        timer->start(5);
        contador_neutral++;
    }
}



void MainWindow::DisparoOfensivo(){


    //calculamos los podibles ataques ofensivos que atenten
    //contra la integridad del canion defensivo
    int flag = 0;
    float x = 0.0;
    float y = 0.0;

    OFENSIVO = new Misil(canion1->getPosx(), canion1->getPosy());
    DEFENSIVO = new Misil(canion2->getPosx(), canion2->getPosy());

    for(float angulo = 1; angulo < 90 ; angulo += 0.5){
        OFENSIVO->setAng(angulo);//Angulo
        for(float velocidad = 50; velocidad < 120 ; velocidad++){
            OFENSIVO->setVel(velocidad);
            OFENSIVO->setVelx(velocidad*cos(OFENSIVO->getAng()*pi/180));  //Vellocidad X
            OFENSIVO->setVely(velocidad*sin(OFENSIVO->getAng()*pi/180));  //Vellocidad Y
            OFENSIVO->setR(0.05*(canion1->getDistancia())); //0.05*d __ distancia entre caniones
            x = 0.0;
            y = 0.0;
            for(float t = 0; ; t+= 0.05){
                x = OFENSIVO->getVelx()*t;
                y = OFENSIVO->getPosy()+ OFENSIVO->getVely()*t -(0.5*9.81*t*t);
                //Verificar impacto
                //comprobar que este en el radio de impacto
                //distancia entre dos puntos (bala y DEFENSIVO) < radio de explosion
                //qDebug() << sqrt(pow((canion2->getPosx() - x),2)+pow((canion2->getPosy() - y),2));
                //qDebug() << x;
                if(sqrt(pow((canion2->getPosx() - x),2)+pow((canion2->getPosy() - y),2)) < OFENSIVO->getR()){
                    if(y<0) y = 0;

                    //add al vector
                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    ofensivos3.push_back(misil_cargador);

                    //Creamos la reaccion DEFENSIVA
                    if(t>2){
                        DisparoDefensivo(t);

                    }
                    flag++;
                    angulo += 5;
                    velocidad += 10;
                    break;
                }
                if(y < 0 || x > 1000) break;
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
    if(flag != 3){
        qDebug() << "Informacion, Siguiente O";
    }
}

void MainWindow::DisparoDefensivo(float Limite_tiempo){

    //con el ataque ofensivo que se aproxima, pasaran 2 segundos
    //de retraso y obtenemos valores para una defensa que será efectiva
    float xo = 0.0;
    float yo = 0.0;
    float xd = 0.0;
    float yd = 0.0;
    int flag = 0;

    //Generar disparo defensivo

    for(float angulo = 180; angulo > 90 ; angulo-=0.5){
        DEFENSIVO->setAng(angulo); //Angulo
        for(float velocidad = 70; velocidad < 120 ; velocidad+=0.3){
            DEFENSIVO->setVel(velocidad);
            DEFENSIVO->setVelx(velocidad*cos(DEFENSIVO->getAng()*pi/180));  //Vellocidad X
            DEFENSIVO->setVely(velocidad*sin(DEFENSIVO->getAng()*pi/180));  //Vellocidad Y
            DEFENSIVO->setR(0.025*(DEFENSIVO->getPosx())); //0.025*d __ distancia entre caniones

            for(float t2 = 0; t2 < Limite_tiempo ; t2 += 0.025){
                xd = (DEFENSIVO->getVelx()*t2)+DEFENSIVO->getPosx();
                yd = DEFENSIVO->getPosy() + DEFENSIVO->getVely()*t2 - (0.5*9.81*t2*t2);
                float t = t2+2;
                xo = OFENSIVO->getVelx()*t;
                yo = OFENSIVO->getPosy() + OFENSIVO->getVely()*t - (0.5*9.81*t*t);

                if(yd < 0 || yo < 0 || xo > 1000 || xd < -10) break;
                if(sqrt(pow((canion2->getPosx() - xo),2)+pow((canion2->getPosy() - yo),2)) > 1200) break;
                //Verificar impacto
                //comprobar que este en el radio de impacto
                //distancia entre dos puntos (bala y DEFENSIVO) < radio de explosion
                //qDebug() << (sqrt(pow((xo - xd),2)+pow((yo - yd),2)));

                //qDebug() << t;
                if(sqrt(pow((xo - xd),2)+pow((yo - yd),2)) <= OFENSIVO->getR()){
                    //qDebug() << (sqrt(pow((xo - xd),2)+pow((yo - yd),2)));
                    if(yd<0) yd = 0;

                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    defensivos3.push_back(misil_cargador);

                     //Creamos la reaccion NEUTRALIZAR
                    //usaremos 3 disparos ofensivos para neutralizar
                    //la defensa del otro canion
                    if(t>1){
                        //3 disparos NEUTRALES
                        DisparoNeutral(t2);
                    }
                    flag++;
                    angulo -= 5;
                    velocidad += 10;
                    break;
                }
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
    if(flag != 3){
        qDebug() << "Informacion, Siguiente D";
    }
}

void MainWindow::DisparoNeutral(float Limite_tiempo){

    //calculamos los disparos
    //los llamaremos neutrales o neutralizadores
    float xo = 0.0;
    float yo = 0.0;
    float xd = 0.0;
    float yd = 0.0;
    int flag = 0;

    OFENSIVO->setPosx(canion1->getPosx());
    OFENSIVO->setPosy(canion1->getPosy());

    DEFENSIVO->setPosx(canion2->getPosx());
    DEFENSIVO->setPosy(canion2->getPosy());

    //Generar disparo NEUTRAL
    for(float angulo = 1; angulo < 90 ; angulo+=0.5){
        OFENSIVO->setAng(angulo);
        for(float velocidad = 600; velocidad < 1200 ; velocidad++){
            OFENSIVO->setVel(velocidad); //Angulo
            OFENSIVO->setVelx(velocidad*cos(OFENSIVO->getAng()*pi/180));  //Vellocidad X
            OFENSIVO->setVely(velocidad*sin(OFENSIVO->getAng()*pi/180));  //Vellocidad Y
            OFENSIVO->setR(0.005*(canion1->getDistancia())); //0.005*d __ distancia entre caniones

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
                    //capturamos los valores
                    Datos misil_cargador;
                    misil_cargador.angulo = angulo;
                    misil_cargador.velocidad = velocidad;
                    neutrales9.push_back(misil_cargador);

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
    if(flag != 3){
        qDebug() << "Informacion, Siguiente N";
    }
}
