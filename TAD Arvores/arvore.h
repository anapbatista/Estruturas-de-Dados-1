//arvore dinamica e encadeada

typedef char elem;
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
/*
 Buscar um elemento
 Buscar pai de um elemento na árvore
 Inserir elemento à esquerda de outro elemento
 Inserir elemento à direita de outro elemento
 Imprimir elementos da árvore
 Finalizar árvore
 Determinar altura da árvore*/

