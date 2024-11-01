//lista.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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

void insere(lista *l, elem x){
    if (esta_na_lista(l,x)==0){

    no *p=(no*)malloc(sizeof(no));
    if (p!=NULL){
        p->info=x;
        p->prox=NULL;
    }
    if (l->ini==NULL){
        l->ini=p;
        l->fim=p;
        }else{
            l->fim->prox=p;
            l->fim=p;
        }
    l->total++;
}}
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
void inverte(lista *l){
    no *atual=l->ini;
    no *anterior=NULL;
    no *proximo=NULL;

    l->fim=l->ini;

    while (atual!=NULL){
        proximo=atual->prox;
        atual->prox=anterior;

        anterior=atual;
        atual=proximo;
    }
    l->ini= anterior;
}
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