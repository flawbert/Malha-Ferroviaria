#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, pthread_mutex_t * mut){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    mutex = mut;
    passo = 10;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(velocidade == 0){
                emit updateGUI(ID, x,y);
                break;
            }
            // Travando os Mutex.
            if(x == 310 && y == 30){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[0]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[0]);
            }
            if(x == 330 && y == 130) {
                pthread_mutex_lock(&mutex[2]);
            }

            // Destravando os Mutex.
            if(x == 310 && y == 150){
                pthread_mutex_unlock(&mutex[0]);
            }
            if(x == 180 && y == 150){
                pthread_mutex_unlock(&mutex[2]);
            }

            if (y == 30 && x <330)
                x+=passo;
            else if (passo < 0 && y == 30 && x ==330)
                x+=passo;
            else if (x == 330 && y < 150)
                y+=passo;
            else if (x > 60 && y == 150)
                x-=passo;
            else
                y-=passo;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 2: //Trem 2
            if(velocidade == 0){
                emit updateGUI(ID, x,y);
                break;
            }
            //Travando os Mutex.
            if(x == 350 && y == 150){
                pthread_mutex_lock(&mutex[0]);
            }
            if(x == 490 && y == 150){
                pthread_mutex_lock(&mutex[3]);
            }
            if(x == 580 && y == 30){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[1]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[1]);
            }
            if(x == 600 && y == 130){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[4]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[4]);
            }

            // Destravando os Mutex.
            if(x == 350 && y == 30){
                pthread_mutex_unlock(&mutex[0]);
            }
            if(x == 330 && y == 130){
                pthread_mutex_unlock(&mutex[3]);
            }
            if(x == 580 && y == 150){
                pthread_mutex_unlock(&mutex[1]);
            }
            if(x == 450 && y == 150){
                pthread_mutex_unlock(&mutex[4]);
            }

            if (y == 30 && x <600)
                x+=passo;
            else if (passo < 0 && y == 30 && x == 600)
                x+=passo;
            else if(passo < 0 && x == 600 && y == 150)
                y+=passo;
            else if (x == 600 && y < 150)
                y+=passo;
            else if (x > 330 && y == 150)
                x-=passo;
            else
                y-=passo;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 3: //Trem 3
            if(velocidade == 0){
                emit updateGUI(ID, x,y);
                break;
            }

            //Travando os Mutex.
            if(x == 620 && y == 150) {
                pthread_mutex_lock(&mutex[1]);
            }
            if(x == 760 && y == 150){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[5]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[5]);
            }

            //Destravando os Mutex.
            if(x == 620 && y == 30) {
                pthread_mutex_unlock(&mutex[1]);
            }
            if(x == 600 && y == 130){
                pthread_mutex_unlock(&mutex[5]);
            }

            if (y == 30 && x <870)
                x+=passo;
            else if (x == 870 && y < 150)
                y+=passo;
            else if (x > 600 && y == 150)
                x-=passo;
            else
                y-=passo;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 4: //Trem 4
            if(velocidade == 0){
                emit updateGUI(ID, x,y);
                break;
            }

            //Travando os Mutex.
            if(x == 200 && y == 170){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[2]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[2]);
            }
            if(x == 310 && y == 150){
                if(passo < 0){
                    pthread_mutex_unlock(&mutex[3]);
                    passo = 10;
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[3]);
            }
            if(x == 450 && y == 150){
                pthread_mutex_lock(&mutex[6]);
            }

            // Destravando os Mutex.
            if(x == 350 && y == 150){
                if(passo < 0){ // Caso ande para trás:
                    // Ativa o lock para não bater no trem 1, que também está usando a região 3.
                    pthread_mutex_lock(&mutex[2]);
                    emit updateGUI(ID, x,y);
                } else {
                    pthread_mutex_unlock(&mutex[2]);
                }
            }
            if(x == 470 && y == 170){
                pthread_mutex_unlock(&mutex[3]);
            }
            if(x == 450 && y == 270){
                pthread_mutex_unlock(&mutex[6]);
            }


            if (passo < 0 && y == 150 && x == 200)
                y-=passo;
            else if (y == 150 && x <470)
                x+=passo;
            else if (x == 470 && y < 270)
                y+=passo;
            else if (x > 200 && y == 270)
                x-=passo;
            else
                y-=passo;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 5: //Trem 5
            if(velocidade == 0){
                emit updateGUI(ID, x,y);
                break;
            }

            //LOCKS

            if(x == 580 && y == 150){ // Se estiver entrando na região 6:
                pthread_mutex_lock(&mutex[5]); // Bloqueia a região 6 para o trem 3 não poder passar.
            }
            if(x == 470 && y == 170){ // Se estiver entrando na região 5:
                if(passo < 0){ // Se estiver andando para trás (ré):
                    // Ativa o lock que dá acesso ao trem 2 que está utilizando a região 7
                    pthread_mutex_unlock(&mutex[4]);
                    passo = 10; // Região liberada, trem volta a andar para frente.
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[4]); // Bloqueia o acesso do trem 2 para a região 5.
            }
            if(x == 490 && y == 270){ // e estiver entrando na região 7:
                if(passo < 0){ // Se estiver andando para trás (ré):
                    // Ativa o lock que dá acesso ao trem 4 que está utilizando a região 7
                    pthread_mutex_unlock(&mutex[6]);
                    passo = 10; // Região liberada, trem volta a andar para frente.
                    emit updateGUI(ID, x,y);
                    break;
                }
                pthread_mutex_lock(&mutex[6]); // Bloqueia o acesso do trem 4 para a região 7.
            }

            // UNLOCKS

            if(x == 740 && y == 170){ // Se o trem estiver deixando a região 6:
                // Liberando a região 6 para o trem 3 ter acesso.
                pthread_mutex_unlock(&mutex[5]);
            }
            if(x == 620 && y == 150){ // Se o trem estiver deixando a região 5:
                // Liberando a região 5 para o trem 2 ter acesso.
                pthread_mutex_unlock(&mutex[4]);
            }
            if(x == 490 && y == 150){ // Se o trem estiver deixando a região 7:
                if(passo < 0){ // Se estiver andando para trás (ré):
                    // Ativa o lock para que não haja impacto na região 7, onde o trem 4 também faz uso.
                    pthread_mutex_lock(&mutex[6]);
                    emit updateGUI(ID, x,y);
                } else { // Se o trem estiver andando para a frente, libera a região 7 para o trem 4 fazer uso.
                    pthread_mutex_unlock(&mutex[6]);
                }
            }

            if (passo < 0 && y == 150 && x == 470)
                y-=passo;
            else if (y == 150 && x <740)
                x+=passo;
            else if (x == 740 && y < 270)
                y+=passo;
            else if (x > 470 && y == 270)
                x-=passo;
            else if (passo < 0 && y == 270 && x == 470)
                x-=passo;

            else
                y-=passo;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        default:
            break;
        }
        msleep(velocidade);
    }
}

// Possibilita a manipulação da velocidade do trem.
void Trem::setVelocidade(int v){
    if(v <= 0){
        velocidade = 0;
        return;
    }
    velocidade = 99*7/v;
}

void Trem::inverter_passo(){
    passo = passo*(-1);
}

int Trem::get_passo(){
    return passo;
}

void Trem::reset_passo(){
    passo = 10;
}
