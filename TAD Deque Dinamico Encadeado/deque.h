
typedef int elem;
typedef struct no_t no;
typedef struct deque_t deque;
struct no_t{
    elem info;
    no *prox;
};
struct deque_t{
    no* ini,*fim;
    int total;
};

deque* cria();
void insere_final(deque* q, elem x);
void insere_inicio(deque* q, elem x);
elem remove_final(deque* q);
elem remove_inicio(deque* q);
void imprime(deque* q);
int tamanho(deque* q);
int esta_no_deque(deque *, elem x);
int esta_vazio(deque *q);
void libera(deque *q);