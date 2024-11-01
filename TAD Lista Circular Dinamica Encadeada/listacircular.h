
typedef struct no_t no;
typedef struct  listacircular lista;
typedef struct elem elem;

struct elem{
    char *nome;
    char *cpf;
    char *rg;
};
struct no_t{
    elem info;
    no *prox;
};
struct listacircular{
    no* fim;
    int total;
};

lista *criar();
void inserir(lista *l, char *nome, char *cpf, char *rg);
void libera(lista *);
int esta_na_lista(lista*, char *nome, char *cpf, char *rg);
void imprime(lista *l);
void remover(lista *l, char *nome, char *cpf, char *rg);
lista *uniao(lista *, lista *);
lista *interseccao(lista *, lista *);