#include <stdio.h>
#include <stdlib.h>


typedef struct no_l
{
    int valor;
    struct no_l *prox;
    struct no_l *ant;
} no;

typedef struct lista_l
{
    no *cabeca;

} lista;

lista *cria()
{
    lista *l = (lista *)malloc(sizeof(lista));
    if (l == NULL)
    {
        return NULL;
    }

    l->cabeca = (no *)malloc(sizeof(no));
    if (l->cabeca == NULL)
    {
        free(l);
        return NULL;
    }

    l->cabeca->valor = 0;
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;

    return l;
}

int estavazia(lista *l)
{
    if (l->cabeca->valor != 0)
        return 0;
    return (1);
}

no *estanalista(lista *l, int x)
{
    if (!estavazia(l))
    {
        no *aux = l->cabeca->prox;
        while (aux != l->cabeca)
        {
            if (aux->valor == x)
            {
                return aux;
            }
            aux = aux->prox;
        }
    }
    return NULL;
}

void insereadireitade(lista *l, int x, int y)
{

    if (!estavazia(l))
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo != NULL)
        {

            no *aux = estanalista(l, y);
            if (aux != NULL)
            {
                // inserção no fim
                if (aux->prox == l->cabeca)
                {
                    novo->valor = x;
                    novo->prox = aux;
                    novo->prox = l->cabeca;
                    novo->ant = aux;
                    l->cabeca->ant = novo;
                    aux->prox = novo;
                }
                // inserção no meio
                else
                {
                    novo->valor = x;
                    novo->prox = aux->prox;
                    novo->ant = aux;
                    aux->prox->ant = novo;
                    aux->prox = novo;
                }
            }
        }
    }
    else
    {
        no *novo = (no *)malloc(sizeof(no));
        if (novo != NULL)
        {
            novo->valor = x;
            novo->prox = l->cabeca;
            novo->ant = l->cabeca;
            l->cabeca->prox = novo;
            l->cabeca->ant = novo;
        }
    }
    l->cabeca->valor++;
}

void imprime(lista *l)
{
    no *aux = l->cabeca->prox;
    while (aux->prox != l->cabeca)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

int main()
{

    lista *l = cria();
    insereadireitade(l, 1, 0);
    imprime(l);
    insereadireitade(l, 3, 1);
    imprime(l);
    insereadireitade(l, 2, 1);
    imprime(l);
    insereadireitade(l, 4, 3);
    imprime(l);

    return 0;
}