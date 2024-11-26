// arvore binaria de busca ou ordenada

typedef int elem;
typedef struct bloco
{
    elem info;
    struct bloco *esq, *dir;
    int fb; // AVL
} no;

typedef struct
{
    no *raiz;
} arvore;

arvore *create(void);
int isempty(arvore *a);
int buscar(no *p, elem *x);
int inserir(no **p, elem *x);
elem busca_maior(no **p);
int remover(no **p, elem *x);

// arvore de busca balanceada (AVL)
void rotacao_dd(no **r);
void rotacao_ee(no **r);
void rotacao_ed(no **r);
void rotacao_de(no **r);
int inserir_avl(no**p,elem*x);
int aux_inserir_avl(no**p, elem *x, int*cresceu);