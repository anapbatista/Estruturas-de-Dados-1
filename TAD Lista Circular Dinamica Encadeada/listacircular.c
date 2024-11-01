#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "listacircular.h"

lista *criar(){
    lista *l = (lista*)malloc(sizeof(lista));
    assert(l!=NULL);
    l->fim=NULL;
    l->total=0;
    return l;
}
void inserir(lista *l, char *name, char *fpc, char *gr){
    no *p=(no*)malloc(sizeof(no));

    p->info.nome = (char *)malloc((strlen(name) + 1) * sizeof(char));
    p->info.cpf = (char *)malloc((strlen(fpc) + 1) * sizeof(char));
    p->info.rg = (char *)malloc((strlen(gr) + 1) * sizeof(char));

    assert(p->info.nome != NULL);
    assert(p->info.cpf != NULL);
    assert(p->info.rg != NULL);

    strcpy(p->info.nome, name);
    strcpy(p->info.cpf, fpc);
    strcpy(p->info.rg, gr);


    if (l->fim==NULL){
        l->fim=p;
        p->prox=p;
    } else {
        p->prox=l->fim->prox;
        l->fim->prox = p; 
        l->fim = p;
    }
    l->total++; 
}
void libera(lista *l){
    assert(l!=NULL);
    no *p=l->fim->prox;
    assert(p!=NULL);
    while (p!=l->fim){
        no *q=p->prox;
        free(p->info.nome);
        free(p->info.cpf);
        free(p->info.rg);
        free(p);
        p=q;
    }
    free(l);   
}
int esta_na_lista(lista*l, char *name, char *fcp, char *rg){
    assert(l->fim!=NULL);
    no *p=l->fim->prox;
    assert(p!=NULL);
    while (p!=l->fim){
        if (strcmp(p->info.nome,name)==0) return 1;
        else p=p->prox;}
    return 0;
}
void imprime(lista *l){
    no *p=l->fim->prox;
    do {
        printf("%s, %s, %s\n", p->info.nome, p->info.cpf, p->info.rg);
        p=p->prox;}
        
        while (p!=l->fim->prox);
}
void remover(lista *l, char *nome, char *cpf, char *rg){
    assert(l->fim!=NULL);
    
    if (esta_na_lista(l,nome,cpf,rg)){
        no *p=l->fim->prox;
        no *ant=l->fim;

        while (strcmp(p->info.nome, nome)!=0 && 
        strcmp(p->info.cpf, cpf) != 0 && 
        strcmp(p->info.rg, rg) != 0){
            ant=p;
            p=p->prox;}

        if (p == l->fim && p->prox == p) {
            // Se for o único e primeiro nó
            free(p->info.nome);
            free(p->info.cpf);
            free(p->info.rg);
            free(p); 
            l->fim = NULL; }
        else if (p==l->fim && p->prox==l->fim->prox){
            // Se for o último nó
            ant->prox=l->fim->prox;
            l->fim=ant;
            free(p->info.nome);
            free(p->info.cpf);
            free(p->info.rg);
            free(p);
        } else{
            // Se for qualquer outro nó
            ant->prox=p->prox;
            free(p->info.nome);
            free(p->info.cpf);
            free(p->info.rg);
            free(p);
        }
        l->total--;
    }
}
lista *uniao(lista *l1, lista *l2){
    lista *l3=(lista*)malloc(sizeof(lista));
    assert(l3!=NULL);
    l3->fim = NULL;
    l3->total = 0;
   
   no *p=(no*)malloc(sizeof(no));
   assert(p!=NULL);
   p=l1->fim->prox;
   while (p!=l1->fim){
    inserir(l3,p->info.nome, p->info.cpf, p->info.rg);
    p=p->prox;
   }
   p=l1->fim;
   inserir(l3,p->info.nome, p->info.cpf, p->info.rg);
   p=l2->fim->prox;
   while (p!=l2->fim){
    inserir(l3,p->info.nome, p->info.cpf, p->info.rg);
    p=p->prox;
   }
   p=l2->fim;
   inserir(l3,p->info.nome, p->info.cpf, p->info.rg);
   return l3;
}
lista *interseccao(lista *l1, lista *l2){
    lista *l3=(lista*)malloc(sizeof(lista));
    assert(l3!=NULL);
    l3->fim = NULL;
    l3->total = 0;

    no *p1=l1->fim->prox;
    do{
    no *p2=l2->fim->prox;
    do{
        if (strcmp(p1->info.nome,p2->info.nome)==0 && 
        strcmp(p1->info.cpf,p2->info.cpf)==0 &&
        strcmp(p1->info.rg,p2->info.rg)==0){
            
        inserir(l3,p1->info.nome, p1->info.cpf, p1->info.rg);}
        
        p2=p2->prox;
        }while (p2!=l2->fim->prox);
        p2=p2->prox;
    } while(p1!=l1->fim->prox);    
    return l3;
    }