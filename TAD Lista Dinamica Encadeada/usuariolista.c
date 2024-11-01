//mainlista.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"



int main(){

lista *l=cria();
insere(l, 1);
insere(l, 2);
insere(l, 3);
insere(l, 4);
insere(l, 5);
imprimir(l);
int num = tamanho(l);
printf("o tamanho eh %d\n", num);

if (esta_na_lista(l,2)==1){
    printf("o elemento 2 estah na lista\n");
}
inverte(l);
imprimir(l);

inverte(l);
imprimir(l);

retira(l,1);
imprimir(l);
retira(l,5);
imprimir(l);
retira(l,3);
imprimir(l);

libera(l);

    return 0;
}