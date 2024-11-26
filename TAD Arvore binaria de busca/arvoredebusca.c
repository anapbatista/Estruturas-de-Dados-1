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

// AVL - Arvore de busca balanceada
void rotacao_dd(no **r)
{ // rotacao simples p/esquerda

    no *pai = *r;
    no *filho = pai->dir;

    pai->dir = filho->esq;
    filho->esq = pai;
    pai->fb = 0;
    filho->fb = 0;
    *r = filho;
}

void rotacao_ee(no **r)
{ // rotacao simples p/direita

    no *pai = *r;
    no *filho = pai->esq;
    pai->esq = filho->dir;
    filho->dir = pai;
    pai->fb = 0;
    filho->fb = 0;
    *r = filho;
}

void rotacao_ed(no **r)
{ // rotacao dupla esquerda-direita

    no *pai = *r;
    no *filho = pai->esq;
    no *neto = filho->dir;
    pai->esq = neto->dir;
    filho->dir = neto->esq;
    neto->esq = filho;
    neto->dir = pai;

    switch (neto->fb)
    {
    case -1:
        pai->fb = 1;
        filho->fb = 0;
        break;
    case 0:
        pai->fb = 0;
        filho->fb = 0;
        break;
    case 1:
        pai->fb = 0;
        filho->fb = -1;
        break;
    }
    neto->fb = 0;
    *r = neto;
}

void rotacao_de(no **r)
{ // rotação dupla direita-esquerda
    no *pai = *r;
    no *filho = pai->dir;
    no *neto = filho->esq;
    pai->dir = neto->esq;
    filho->esq = neto->dir;
    neto->dir = filho;
    neto->esq = pai;

    switch (neto->fb)
    {
    case -1:
        pai->fb = 1;
        filho->fb = 0;
        break;
    case 0:
        pai->fb = 0;
        filho->fb = 0;
        break;
    case 1:
        pai->fb = 0;
        filho->fb = -1;
        break;
    }
    neto->fb = 0;
    *r = neto;
}

int inserir_avl(no **p, elem *x)
{
    int cresceu;
    return (aux_inserir_avl(p, x, &cresceu));
}

int aux_inserir_avl(no **p, elem *x, int *cresceu)
{
    if (*p == NULL)
    {
        *p = (no *)malloc(sizeof(no));
        (*p)->info = *x;
        (*p)->fb = 0;
        (*p)->esq = (*p)->dir = NULL;
        *cresceu = 1;
        return (1);
    }
    else if ((*p)->info == *x)
    {
        return 0;
    }
    else if (*x < (*p)->info)
    {
        if (aux_inserir_avl(&(*p)->esq, x, cresceu))
        {
            if (*cresceu)
            {
                switch ((*p)->fb)
                {
                case -1:
                    if ((*p)->esq->fb == -1)
                    {
                        rotacao_ee(p);
                    }
                    else
                    {
                        rotacao_ed(p);
                    }
                    *cresceu = 0;
                    break;
                case 0:
                    (*p)->fb = -1;
                    *cresceu = 1;
                    break;
                case 1:
                    (*p)->fb = 0;
                    *cresceu = 0;
                    break;
                }
            }
            return 1;
        }
        return 0;
    }
    else if (*x > (*p)->info)
    {
        if (aux_inserir_avl(&(*p)->dir, x, cresceu))
        {
            if (*cresceu)
            {
                switch ((*p)->fb)
                {
                case -1:
                    (*p)->fb = 0;
                    *cresceu = 0;
                    break;
                case 0:
                    (*p)->fb = 1;
                    *cresceu = 1;
                    break;
                case 1:
                    if ((*p)->dir->fb == 1)
                    {
                        rotacao_dd(p);
                    }
                    else
                    {
                        rotacao_de(p);
                    }
                    *cresceu=0;
                    break;
                }
        
            }
        return 1;
        }
    return 0;
    }
}
