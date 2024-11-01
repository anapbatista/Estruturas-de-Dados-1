//arquivo usuarioTADpilha.c
#include <stdio.h>
#include "pilha.h"

void imprimepilha(pilha *p){
    if (!isempty(p)){
        for (int i=p->topo-1; i>=0; i--){
            printf("%d\n", p->vet[i]);
        }
    }
}

void comparapilhas(pilha *p, pilha *p1){
    if (p->topo > p1->topo){
        printf("a primeira pilha tem mais elementos que a segunda\n");}
    else if (p->topo < p1->topo){
        printf("a primeira pilha tem menos elementos que a segunda\n");
    }else {
        printf("ambas tem a mesma quantidade de elementos\n");
    }
}

pilha inverte(pilha p){
    pilha p2=create();
    for (int i=p.topo-1; i>=0; i--){
        elem x=pop(&p);
        push(&p2, x);}
    return p2;
}


int main(){

pilha p=create();
pilha p1=create();
push(&p,2);
push(&p1,1);
push(&p,3);
push(&p1,2);
push(&p,4);
push(&p1,3);
push(&p,5);
push(&p1,1);
push(&p,6);
push(&p,500);
elem x=pop(&p);
printf("pop: %d\n",x);
elem y=top(&p);
printf("top: %d\n",y);
imprimepilha(&p);
imprimepilha(&p1);
pilha p2=inverte(p);
imprimepilha(&p2);
comparapilhas(&p,&p1);
empty(&p);
empty(&p1);
empty(&p2);



    return 0;
}