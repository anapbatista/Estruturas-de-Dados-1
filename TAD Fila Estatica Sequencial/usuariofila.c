//usuariofila.c
#include <stdio.h>
#include "fila.h"

int main(){

fila f=create();
elem x;
if (isempty(&f)){
    printf("Fila vazia\n");
}
inserir(&f,5);
inserir(&f,10);
inserir(&f,15);
inserir(&f,20);
if (isempty(&f)){
    printf("Fila vazia\n");
}
if (isfull(&f)){
    printf("Fila cheia\n");
}
inserir(&f,25);
inserir(&f,30);
inserir(&f,35);
inserir(&f,40);
inserir(&f,45);
inserir(&f,50);
inserir(&f,55);
printf("teste\n");
if (isfull(&f)){
    printf("Fila cheia\n");
}
remover(&f,&x);
printf("Elemento removido: %d\n",x);




    return 0;
}