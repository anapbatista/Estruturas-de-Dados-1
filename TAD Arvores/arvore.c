// greu de um nó: numero de filhos
// grau de uma arvore: grau máximo entre os nós
#include <stdio.h>
#include "arvore.h"

arvore *create(void)
{
    arvore *aux = (arvore *)malloc(sizeof(arvore));
    if (aux != NULL)
    {
        aux->raiz = NULL;
    }
    return aux;
}

int isempty(arvore *a)
{
    if (a->raiz == NULL)
    {
        return 1;
    }
    else
        return 0;
}

no *busca(no *p, elem *x)
{
    no *aux;
    if (p == NULL)
        return NULL;
    else if (p->info == x)
        return (p);
    else
    {
        aux = busca(p->esq, x);
        if (aux != NULL)
            aux = busca(p->dir, x);
        return aux;
    }
}

no *buscapai(no *p, elem *x)
{
    no *aux;
    if (p == NULL)
    {
        return NULL;
    }
    else if ((p->esq != NULL) && (p->esq->info == *x))
    {
        return p;
    }
    else if ((p->dir != NULL) && (p->dir->info == *x))
    {
        return (p);
    }
    else
    {
        aux = buscapai(p->esq, x);
        if (aux = NULL)
            aux = buscapai(p->dir, x);
        return aux;
    }
}
void insere_esq(arvore*a, elem *x, elem*pai, int *erro){
    


}
