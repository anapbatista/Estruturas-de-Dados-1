/*Considere uma lista de pais que têm filhos estudando no ICMC. Tanto os pais quanto
os filhos são representados em listas dinâmicas e encadeadas, sendo que cada pai
deve estar ligado à lista de seus filhos.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct no_t no;
typedef struct lista_t lista;
struct no_t {
    char nome[100];
    no *prox; 
    lista *f; 
};
struct lista_t{
    no *ini, *fim;
    int total;
};

lista*criar(){
    lista *p=(lista*)malloc(sizeof(lista));
    assert(p!=NULL);
    p->ini=NULL;
    p->fim=NULL;
    p->total=0;
    return p;
}
int estavazia(lista *p){
    return (p->ini==NULL);
}
void inserir(lista *p, char *nome){
    no *n=(no*)malloc(sizeof(no));
    assert(n!=NULL);
    if (estavazia(p)){
        p->ini=n;
        p->fim=n;
        strcpy(n->nome,nome);
        n->prox=NULL;
        n->f=NULL;
        p->total++;
        }else{
            p->fim->prox=n;
            n->prox=NULL;
            n->f=NULL;
            strcpy(n->nome,nome);
            p->fim=n;
            p->total++;
    }  
}
void ligando(lista *p, lista *f) {
    assert(p != NULL);
    assert(f != NULL);

    no *q = p->ini;

    // Percorre a lista de pais até encontrar o primeiro pai sem filhos
    while (q != NULL) {
        if (q->f == NULL) {
            q->f = f; // Associa a lista de filhos ao pai
            break; // Sai do laço após encontrar o pai
        }
        q = q->prox;
    }
}
void imprimir(lista *p) {
    no *q = p->ini;
    while (q != NULL) {
        printf("Pai %s:\n", q->nome);
        if (q->f != NULL) { // Verifique se a lista de filhos não é nula
            no *filho = q->f->ini;
            while (filho != NULL) {
                printf("  Filho: %s\n", filho->nome);
                filho = filho->prox; // Mova para o próximo filho
            }
        }
        q = q->prox; // Mova para o próximo pai
    }
}
void libera(lista *p) {
    no *q = p->ini;
    while (q != NULL) {
        if (q->f != NULL) { // Verifica se a lista de filhos não é nula
            no *filho = q->f->ini;
            while (filho != NULL) {
                no *aux_filho = filho->prox; // Armazena o próximo filho
                free(filho); // Libera o filho atual
                filho = aux_filho; // Avança para o próximo
            }
            free(q->f); // Libera a lista de filhos
        }
        no *aux_pai = q; // Armazena o pai atual
        q = q->prox; // Avança para o próximo pai
        free(aux_pai); // Libera o pai atual
    }
    free(p); // Libera a lista de pais
}



int main(){

lista *p=criar();
inserir(p,"Geraldo");
inserir(p,"Mazinho");
lista *f1=criar();
inserir(f1,"Ana");
inserir(f1,"Gabriel");
lista *f2=criar();
inserir(f2,"Vitor");
inserir(f2,"Junior");
ligando(p,f2);
ligando(p,f1);
imprimir(p);
libera(p);




    return 0;
}