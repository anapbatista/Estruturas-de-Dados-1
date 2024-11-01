//lista.h

typedef int elem;
typedef struct no_t no;
typedef struct lista_t lista;

struct no_t{
    elem info;
    no *prox;
};
struct lista_t{
    no *ini, *fim;
    int total;
};

lista *cria();
void libera(lista*);
void insere(lista *l, elem x);
int tamanho(lista*);
void imprimir(lista*);
int esta_na_lista(lista *, elem x);
void inverte(lista *);
int retira(lista*, elem x);