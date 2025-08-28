#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

int contador = 0;
double tamanho = 0;
int numThreads = 0;
long fracao = 0;
string x;
list <string> palavras;
sem_t semaforo;

void *threadPalavras (void *arg) {

  sem_wait(&semaforo);
  contador ++;

  int inicio = contador*fracao;

  auto it1 = palavras.begin();
  auto it2 = it1;
  it2++;

  double j=1;
  while (it2 != palavras.end()){
    if (*it1 == *it2){
      j++;
    } else {
      cout << *it1 << ' ' << j << ' ' << (j/tamanho)*100 << endl;
      it1 = it2;
      j = 1;
    }
    it2 ++;
  }

  pthread_exit (NULL) ;

}

int main(int argc, char *argv[]) {
  ifstream arq(argv[1]);

  while (arq >> x) {
    palavras.push_back(x);
  }

  palavras.sort();

  tamanho = palavras.size();

  try
  {
    numThreads = atoi(argv[2]);
  }
  catch(const std::exception& e)
  {
    cerr << "Erro no arqumento informado" << endl;
    return 0;
  }

  //Inicializando o semáforo
  sem_init(&semaforo, 0 , 1);

  if (numThreads > tamanho) {
  cerr << "O número de threads não pode ser maior do que o número de palavras." << endl;
  return 0;
  }

  fracao = tamanho/numThreads;

  pthread_t thread[numThreads];

  long i, status;

  // para o printf não se confundir com a threads
  setvbuf (stdout, 0, _IONBF, 0) ;

  for(i=0; i<numThreads; i++)
   {
      status = pthread_create (&thread[i], NULL, threadPalavras, (void *) i) ;
      if (status)
      {
         perror ("pthread_create") ;
         exit (1) ;
      }
   }

   pthread_exit (NULL) ;

   return 0;

}