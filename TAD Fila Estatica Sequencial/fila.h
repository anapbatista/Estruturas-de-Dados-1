//fila.h
#define tam 10
typedef int elem;

typedef struct{
    int ini, fim, total;
    elem vet[tam];
}fila;

fila create();
int isempty(fila *f);
int isfull(fila *f);
int inserir(fila *f, elem x);
int remover(fila *f, elem *x);
int empty(fila *f);