//arquivo pilha.c
#include <stdio.h>
#include "pilha.h"


pilha create(){
    pilha p;
    p.topo = 0;
    return p;
}
int isfull(pilha *p){
    if (p->topo==TAM){
        return 1;
    }else return 0;
}
int isempty(pilha *p){
    if (p->topo==0){
        return 1;}
    else return 0;
}
void push(pilha *p, elem x){
    if (!isfull(p)){
        p->vet[p->topo]=x;
        (p->topo)++;
    }
}
elem pop(pilha *p){
    if (!isempty(p)){
        elem x=(p->vet[p->topo-1]);
        (p->topo)--;
        return x;
    }
}
elem top(pilha *p){
    return (p->vet[p->topo-1]);
}
void empty(pilha *p){
    p->topo=0;
}