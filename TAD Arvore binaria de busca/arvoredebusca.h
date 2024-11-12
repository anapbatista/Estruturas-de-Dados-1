//arvore binaria de busca ou ordenada

typedef int elem;
typedef struct bloco{
    elem info;
    struct bloco *esq, *dir;
}no;

typedef struct{
    no *raiz;
} arvore;   

arvore *create(void);
int isempty(arvore *a);
int buscar(no *p, elem *x);
int inserir(no**p, elem *x);
elem busca_maior(no **p);
int remover(no **p, elem *x);

 