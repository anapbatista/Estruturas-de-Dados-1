//arvore dinamica e encadeada

typedef int elem;
typedef struct bloco{
    elem info;
    struct bloco *esq, *dir;
}no;

typedef struct{
    no *raiz;
} arvore;   

arvore* create(void);
int isempty(arvore*);
no* busca(no *p, elem *x);
no *buscapai(no*p, elem *x);
void insere_esq(arvore*a, elem *x, elem*pai, int *erro);
void imprimir(no *raiz);
void finaliza(arvore *a);
void libera_mem(no*p);
int altura(no *p);

/* Inserir elemento à direita de outro elemento*/


