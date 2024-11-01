/*deque é uma estrutura do tipo fila de extremidade dupla
ou seja, insere no início, e no fim
remove no início e no fim*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

deque *cria(){
    deque *d = (deque *)malloc(sizeof(deque));
    assert(d!=NULL);
    d->ini = NULL;
    d->fim = NULL;
    d->total = 0;
    return d;
}
int esta_vazio(deque *d){
    assert(d!=NULL);
    return (d->total == 0);
}
void libera(deque*d){
    assert(d!=NULL);
    no *p=d->ini;
    while(p!=NULL){
        no*q=p;
        p=p->prox;
        free(q);
        
    }
    free(d);
}
int tamanho(deque *d){
    assert(d!=NULL);
    return d->total;
}
int esta_no_deque(deque *d, elem x){
    assert(d!=NULL);
    no*p=d->ini;
    assert(p!=NULL);
    while (p!=NULL){
        if(p->info == x){
            return 1;
            break;
        }
        p=p->prox;
    }
    return 0;
}
void imprime(deque *d){
    assert(d!=NULL);
    no*p=d->ini;
    assert(p!=NULL);
    while(p!=NULL) {
        printf("%d ",p->info);
        p=p->prox;
        }
    printf("\n");
}
void insere_inicio(deque *d, elem x){
    assert(d!=NULL);
    no *p=(no*)malloc(sizeof(no));
    assert(p!=NULL);
    //se for o primeiro nó
    p->info=x;
    if(esta_vazio(d)){
        p->prox=NULL;
        d->fim=p;
        }
    else {
        p->prox=d->ini;
    }
    d->ini=p;
    d->total++;
}
void insere_final(deque *d, elem x){
    assert(d!=NULL);
    no *p=(no*)malloc(sizeof(no));
    assert(p!=NULL);
    //se for o primeiro nó
    p->info=x;
    p->prox=NULL;
    if(esta_vazio(d)){
        d->ini=p;
        }
    else {
        d->fim->prox=p;
    }
    d->fim=p;
    d->total++;
}
elem remove_final(deque *d){
    assert(d!=NULL);
    if (!esta_vazio(d)){
    elem x;
    //se for apenas 1 elemento
    if (tamanho(d)==1){
        x=d->ini->info;
        free(d->ini);
        d->ini=NULL;
        d->fim=NULL;
    }else{
    no *q=d->ini;
    no *p=d->ini->prox;
    
    while(p!=d->fim){
        p=p->prox;
        q=q->prox;
    }
    x=p->info;
    free(p);
    q->prox=NULL;
    d->fim=q;}
    d->total--;
    return x;
    }
}
elem remove_inicio(deque *d){
    assert(d!=NULL);
    no *p=d->ini;
    if (!esta_vazio(d)){
        elem x=p->info;
        d->ini=p->prox;
        free(p);
        d->total--;
        return x;
    }
}