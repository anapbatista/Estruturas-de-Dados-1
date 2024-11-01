#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listacircular.h"



int main(){

lista*l1=criar();
lista*l2=criar();
char nome[101], cpf[12], rg[8];

for (int i=0; i<1; i++){
    scanf(" %s",nome);
    scanf(" %s",cpf);
    scanf(" %s",rg);
    inserir(l1, nome, cpf, rg);
}
printf("lista1:\n");
imprime(l1);

for (int i=0; i<1; i++){
    scanf(" %s",nome);
    scanf(" %s",cpf);
    scanf(" %s",rg);
    inserir(l2, nome, cpf, rg);
}
printf("lista2:\n");
imprime(l2);

lista*l3=uniao(l1,l2);
printf("lista3:\n");
imprime(l3);

lista*l4=interseccao(l1,l3);
printf("lista4:\n");
imprime(l4);

libera(l1);
libera(l2);
libera(l3);


    return 0;
}