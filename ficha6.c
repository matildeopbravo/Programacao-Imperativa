#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int inicio, tamanho;
    int valores [MAX];
} static_queue;


void Sinit_queue (static_queue *q) {
    q->tamanho=0;
    q->inicio=0;

}

int SisEmpty (static_queue *q) {
        return(q->tamanho == 0);
}

 int Senqueue (static_queue *q, int x) {
    if(q-> inicio + q->tamanho < MAX) {
         q->valores[q->inicio + q->tamanho++] = x;
         return 0;
     }
     return 1;
 }


int Sdequeue (static_queue *q, int *x) {

    if(!SisEmpty(q)) {
        *x = q->valores[q->inicio++];
        q->tamanho--;
        return 0;

    }
    return 1;
}

int Sfront (static_queue *q, int *x) {

    if(!SisEmpty(q)) {
        *x = q->valores[q->inicio];
        return 0;

    }
    return 1;
}

typedef struct {
    int size; // guarda o tamanho do array valores
    int inicio, tamanho;
    int * valores;
}dinamic_queue;

void Dinit (dinamic_queue *q){
    q->size = 5; // valor inicial arbitrário
    q->inicio = 0;
    q->tamanho = 0;
    q->valores = malloc(q->size * sizeof(int));

}

int DisEmpty(dinamic_queue *q) {

    return(q->tamanho == 0);

}

int Denqueue(dinamic_queue *q, int x) {

    if(q->inicio + q-> tamanho >= q->size) {
      q->size *= 2;
      q->valores = realloc(q->valores,sizeof(int) * q->size );
      if(!q->valores) return 1;
    }
    q->valores[q->inicio + q->tamanho++] = x;
    return 0;

}
int Ddequeue (dinamic_queue *q, int *x) {

    if(!DisEmpty(q)) {
        *x = q->valores[q->inicio];
        q->tamanho--;
        q->inicio++;
    }
    return 0;
    
}

int Dfront (dinamic_queue *q, int * x) {

    if(!DisEmpty(q)) {
        *x = q->inicio;
        return 0;
    }
    return 1;

}

int main () {

    dinamic_queue q = {0}; // Para evitar undefined behaviour
    Dinit(&q);
    for(int i = 0; i < 7; i++) Denqueue(&q,i);
    return 0;
  }


