// grau de um nó: numero de filhos
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
void insere_esq(arvore *a, elem *x, elem *pai, int *erro)
{
    no *aux, *p;
    if (*pai != -1)
    {
        aux = busca(a->raiz, pai);
        if ((aux != NULL) && (aux->esq == NULL))
        {
            p = (no *)malloc(sizeof(no));
            if (p != NULL)
            {
                p->info = *x;
                p->esq = NULL;
                p->dir = NULL;
                aux->esq = p;
                *erro = 0;
            }
            else
            {
                *erro = 1;
            }
        }
    }
    else if (*pai == -1)
    {
        if (a->raiz == NULL)
        {
            p = (no *)malloc(sizeof(no));
            if (p != NULL)
            {
                p->info = *x;
                p->esq = NULL;
                p->dir = NULL;
                a->raiz = p;
                *erro = 0;
            }
            else
            {
                *erro = 1;
            }
        }
    }
}

void imprimir(no *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esq);
        printf("%d\n", raiz->info);
        imprimir(raiz->dir);
    }
}
void finaliza(arvore *a)
{
    libera_mem(a->raiz);
    free(a);
}
void libera_mem(no *p)
{
    if (p != NULL)
    {
        libera_mem(p->esq);
        libera_mem(p->dir);
        free(p);
    }
}
int altura(no *p)
{
    int altdir, altesq;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        altesq = 1 + altura(p->esq);
        altdir = 1 + altura(p->dir);
        if (altesq > altdir)
        {
            return altesq;
        }
        else
            return altdir;
    }
}