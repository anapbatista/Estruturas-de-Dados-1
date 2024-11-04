//listaordenada.c
#include <stdio.h>
#include <stdlib.h>
#include "listaordenada.h"

lista *cria(){
    lista *l = (lista*)malloc(sizeof(lista));
    if (l!=NULL){
        l->ini=NULL;
        l->fim=NULL;
        l->total=0;
    }
    return l;
}
void libera(lista* l){
    if (l!=NULL){
        no *p=l->ini;
        while (p!=NULL){
            l->ini=p->prox;
            free(p);
            p=l->ini;}
    }
    free(l);
}

void insere(lista *l, elem x) {
    // Insere apenas se o elemento não estiver na lista
    if (esta_na_lista(l, x) == 0) {
        no *p = (no*)malloc(sizeof(no));
        if (p != NULL) {
            p->info = x;
            p->prox = NULL;
            p->ant = NULL;
        } else {
            return; // Falha na alocação de memória
        }

        no *aux = l->ini;
        no *ant = NULL;

        // Encontrar posição para inserção ordenada
        while (aux != NULL && x > aux->info) {
            ant = aux;
            aux = aux->prox;
        }

        // Inserção no início da lista
        if (ant == NULL) {
            p->prox = l->ini;
            if (l->ini != NULL) { // A lista não está vazia
                l->ini->ant = p;
            } else {
                l->fim = p; // Primeiro elemento, fim aponta para p
            }
            l->ini = p;

        } else { // Inserção no meio ou no final da lista
            p->prox = ant->prox;
            p->ant = ant;
            ant->prox = p;

            if (p->prox != NULL) { // Inserção no meio
                p->prox->ant = p;
            } else { // Inserção no final
                l->fim = p;
            }
        }
        l->total++;
    }
}


int tamanho(lista * l){
    if (l!=NULL){
        return l->total;
    }   
}
void imprimir(lista*l){
    if (l!=NULL){
        no *p=l->ini;
        while (p!=NULL){
            printf("%d ",p->info);
            p=p->prox;}
            }
        printf("\n");
}
int esta_na_lista(lista *l, elem x){
    if (l!=NULL){
    no *p=l->ini;
    while (p!=NULL){
        if (p->info==x){
            return 1;}
        else{
            p=p->prox;}
        }return 0;  
    }}

int retira(lista *l, elem x){
    if(l!=NULL){
    no *ant=NULL;
    no *p=l->ini;
    while (p!=NULL){
        if (p->info==x){
        //remover início
            if (ant==NULL){
                l->ini=l->ini->prox;
                free(p);
            } //remover do fim
            else if (p==l->fim){
                l->fim=ant;
                ant->prox=NULL;
                free(p);
            } else{ //reomver do meio
                ant->prox=p->prox;
                free(p);   
            }
            l->total--;
            return 1;
        } 
        else{
            ant=p;
            p=p->prox;
            ant->prox=p;}

    }
} return 0; }