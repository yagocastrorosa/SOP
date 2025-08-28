// g++ -Wall questao_1.cpp -o questao_1 -lpthread

// Infelizmente não consegui deixar nenhum dos dois programas funcionando corretamente. Estou tendo dificuldade no conteúdo de threads, mas estou
// estudando e praticando mais o conteúdo para melhorar o meu entendimento.

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>

using namespace std;

int soma = 0;
int n = 0;
int p = 0;
int k = 0;
queue<int> fila;
sem_t semaforo;

void *threadPerfeito (void *id) {

    sem_wait(&semaforo);
    long identificador = (long) id;
    long inicio = identificador * k;
    long fim = (identificador + 1) * k - 1;

    int j = 0;

    for (j = inicio; j < fim; j++) {
        if (n % j == 0) {
            cout << "Valor: " << j << endl;
                fila.push(j);
            }
    }
    sem_post(&semaforo);

    pthread_exit (NULL) ;

}

int main() {

        cout << "Digite o valor desejado que você deseja consultar: ";
        cin >> n;

        cout << "Digite o número de threads que serão utilizadas: ";
        cin >> p;

        if ((n/2) < p) {
            cout << "O número de threads foi excedido.";
            return 0;
        }

        k = n/(2*p);

        pthread_t threads[p];

        long i, status;

        // para o printf não se confundir com a threads
        setvbuf (stdout, 0, _IONBF, 0) ;

        //Inicializando o semáforo
        sem_init(&semaforo, 0 , 1);

        //Inicializando as threads
        for(i=0; i<p; i++)
        {
            status = pthread_create (&threads[i], NULL, threadPerfeito, (void *) i) ;
            if (status)
            {
                perror ("pthread_create") ;
                exit (1) ;
            }
        }

        while (! fila.empty()) {
            soma += fila.front();
            fila.pop();
        }

        cout << soma << endl;

        cout << (n == soma ? "Número perfeito" : "Número imperfeito") << endl;
        
        pthread_exit (NULL) ;

        return 0;
        
        }