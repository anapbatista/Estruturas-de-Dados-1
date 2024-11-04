#include <stdio.h>
#include "listaordenada.h"

int main() {
    lista *l = cria();
    int opcao, x;

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Remover elemento\n");
        printf("3 - Verificar se elemento está na lista\n");
        printf("4 - Imprimir lista\n");
        printf("5 - Mostrar tamanho da lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a inserir: ");
                scanf("%d", &x);
                insere(l, x);
                printf("Elemento inserido.\n");
                break;

            case 2:
                printf("Digite o elemento a remover: ");
                scanf("%d", &x);
                if (retira(l, x)) {
                    printf("Elemento removido.\n");
                } else {
                    printf("Elemento não encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o elemento a buscar: ");
                scanf("%d", &x);
                if (esta_na_lista(l, x)) {
                    printf("Elemento está na lista.\n");
                } else {
                    printf("Elemento não está na lista.\n");
                }
                break;

            case 4:
                printf("Lista: ");
                imprimir(l);
                break;

            case 5:
                printf("Tamanho da lista: %d\n", tamanho(l));
                break;

            case 0:
                libera(l);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
