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
/*
 Inserir elemento à direita de outro elemento
 Imprimir elementos da árvore
 Finalizar árvore
 Determinar altura da árvore*/

