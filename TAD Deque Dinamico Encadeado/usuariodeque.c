#include <stdio.h>
#include "deque.h"

int main(){

deque *d=cria();
if (esta_vazio){
    printf("Deque vazio\n");
}
insere_inicio(d,3);
insere_final(d,4);
printf("deque inicio:\n");
imprime(d);

insere_inicio(d,2);
insere_final(d,7);
insere_inicio(d,1);
insere_inicio(d,-2);
printf("deque meio 1:\n");
imprime(d);

remove_inicio(d);
printf("deque meio 2:\n");
imprime(d);

remove_final(d);
printf("deque final:\n");
imprime(d);

if (!esta_vazio){
    printf("Deque nao vazio\n");
}
if (esta_no_deque(d,2)){
    printf("Elemento 2 esta no deque\n");
}else printf("Elemento 2 nao esta no deque\n");
printf("o tamanho do deque eh: %d",tamanho(d));

libera(d);

    return 0;
}