//fila.c
#include <stdio.h>
#include "fila.h"

fila create(){
    fila f;
    f.ini=0;
    f.fim=0;
    f.total=0;
    return f;
}

int isempty(fila *f){
    if (f->total==0){
        return 1;
    }else return 0;
}
int isfull(fila *f){
    if (f->fim==tam){
        return 1;
    } else return 0;
}
int inserir(fila *f, elem x){
    if (!isfull(f)){
        f->vet[f->fim]=x;
        if (f->fim==tam){
        f->fim= (f->fim+1)%tam;}
        else f->fim++;
        f->total++;
        return 1;
    }else return 0;
}
int remover(fila *f, elem *x){
    if (!isempty(f)){
        *x=f->vet[f->ini];
        if (f->ini==tam){
        f->ini= (f->ini +1)%tam;}
        else f->ini++;
        f->total--;
        return 1;}else
    return 0;
        
}
int empty(fila *f){
    if (!isempty(f)){
    f->ini=0;
    f->fim=0;
    f->total=0;
    return 1;} else
    return 0;
}