//arquivo pilha.h
#include <stdio.h>

//número do tamanho do vetor que seja alterável
#define TAM 10

//tipo de variável que seja alterável
typedef int elem;

//union que guarde o valor armazenado e o a posição do topo da pilha
typedef struct {
    elem vet[TAM];
    int topo;
}pilha;

//cria pilha e o topo(igual a zero)
pilha create();
//se a pilha está cheia, retorna 1. se não, retorna 0 
int isfull(pilha *p);
//se a pilha está vazia, retorna 1. se não, retorna 0
int isempty(pilha *p);
//empilha o valor de X no topo da pilha
void push(pilha *p, elem x);
//desempilha o valor do topo da pilha para variável x
elem pop(pilha *p);
//acessa o valor do topo da pilha e retorna em x
elem top(pilha *p);
//esvazia um pilha
void empty(pilha *p);