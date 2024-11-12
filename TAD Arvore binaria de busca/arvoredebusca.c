/*
Árvores binárias de busca são árvores ordenadas de grau 2, o que significa que cada nó pode ter, no máximo, dois filhos.
Em uma árvore binária de busca, o nó filho à esquerda é sempre menor que seu nó pai, enquanto o nó filho à direita é sempre maior.
Numero de nós: 2^n -1, sendo o n Nível da arvore
Big(O): log(N)
*/
#include "arvoredebusca.h"
#include <stdio.h>
#include <stdlib.h>

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

int buscar(no *p, elem *x)
{
    if (p == NULL)
        return 0;
    else if (p->info == *x)
        return 1;
    else if (*x < p->info)
        return (buscar(p->esq, x));
    else if (*x > p->info)
        return (buscar(p->dir, x));
}

int inserir(no **p, elem *x)
{
    if (*p == NULL)
    {
        *p = (no *)malloc(sizeof(no));
        (*p)->info = *x;
        (*p)->dir = NULL;
        (*p)->esq = NULL;
        return 1;
    }
    else if ((*p)->info == *x)
        return 0;
    else if (*x < (*p)->info)
        return (inserir(&(*p)->esq, x));
    else if (*x > (*p)->info)
        return (inserir(&(*p)->dir, x));
}

elem busca_maior(no **p)
{
    no *aux = *p;
    while (aux->dir != NULL)
        aux = aux->dir;
    return (aux->info);
}

int remover(no **p, elem *x)
{
    no *aux;
    if (*p == NULL)
        return 0;
    else if (*x < (*p)->info)
        return (remover(&(*p)->esq, x));
    else if (*x > (*p)->info)
        return (remover(&(*p)->dir, x));
    else if (*x == (*p)->info)
    {
        // caso 1: nó pai sem filhos
        if (((*p)->esq == NULL && (*p)->dir == NULL))
        {
            free(*p);
            *p = NULL;
            return 1;
        }
        // caso 2:tem 1 filho
        else if ((*p)->esq == NULL)
        {
            aux = *p;
            *p = (*p)->dir;
            free(aux);
            return 1;
        }
        else if ((*p)->dir == NULL)
        {
            aux = *p;
            *p = (*p)->esq;
            free(aux);
            return 1;
        }
        // caso 3: tem 2 filhos
        else if (((*p)->esq != NULL && (*p)->dir != NULL))
        {
            (*p)->info = busca_maior(&(*p)->esq);
            return (remover(&(*p)->esq, &(*p)->info));
        }
    }
}