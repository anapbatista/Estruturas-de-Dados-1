//lista dinâmica e encadeada 

#include <stdio.h>
#include <stdlib.h>

typedef int elem;

struct bloco{
    elem info;
    struct bloco *prox;
};
typedef struct bloco lista;

int main(){

    int num;
    lista *ini, *fim, *p;

    ini=NULL;
    fim=NULL;
    scanf("%d",&num);

    while(num!=-1){
        p=(lista*)malloc(sizeof(lista));
        p->info=num;
        p->prox=NULL;

        if (ini==NULL){ //a lista estava vazia, e tem 1 elemento agora
            ini=p;
            fim=p;
        } else { //a lista tem mais de 1 elemento
            fim->prox=p;
            fim=p;
        }

        scanf("%d",&num);
    }

    p=ini;
    while (p!=NULL){
        printf("%d ",p->info);
        p=p->prox;

    }

    while(ini!=NULL){
        p=ini;
        ini=ini->prox;
        free(p);
    }



 return 0;
}