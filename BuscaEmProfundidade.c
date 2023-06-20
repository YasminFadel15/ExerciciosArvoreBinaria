#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no* pai;      //ponteiro para o nó pai
    struct no* esquerda; //ponteiro para o nó filho a esquerda
    struct no* direita;  //ponteiro para o nó filho a direita
    int valor;           //conteúdo de um nó arbitrário da árvore
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* criar() {
    Arvore *arvore;
    arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

No* adicionar(Arvore* arvore, No* pai, int valor) {
    No *no = malloc(sizeof(No));

    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;
    
    if (pai == NULL) {
        arvore->raiz = no;
    }

    return no;
}

void remover(Arvore* arvore, No* no) {
    if (no->esquerda != NULL)
        remover(arvore, no->esquerda);  
  
    if (no->direita != NULL)
        remover(arvore, no->direita);
  
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no)
            no->pai->esquerda = NULL;
        else
            no->pai->direita = NULL;
    }
    free(no);
}

void percorrerPreOrder(No* no) {
    if (no != NULL) {
        printf("%d ", no->valor); //raiz
        percorrerPreOrder(no->esquerda); //esquerda
        percorrerPreOrder(no->direita);  //direita
    }
}

void percorrerInOrder(No* no) {
    if (no != NULL) {
        percorrerInOrder(no->esquerda); //esquerda
        printf("%d ", no->valor); //raiz
        percorrerInOrder(no->direita);  //direita
    }
}

void percorrerPosOrder(No* no) {
    if (no != NULL) {
        percorrerPosOrder(no->esquerda); //esquerda
        percorrerPosOrder(no->direita);  //direita
        printf("%d ", no->valor); //raiz
    }
}

int main() {
    Arvore *a = criar();

    No *no4 = adicionar(a, NULL, 4);
    No *no2 = adicionar(a, no4, 2);
    No *no8 = adicionar(a, no4, 8);
    no4->esquerda = no2;
    no4->direita = no8;

    No *no1 = adicionar(a, no2, 1);
    No *no3 = adicionar(a, no2, 3);
    no2->esquerda = no1;
    no2->direita = no3;

    No *no6 = adicionar(a, no8, 6);
    No *no9 = adicionar(a, no8, 9);
    no8->esquerda = no6;
    no8->direita = no9;

    No *no5 = adicionar(a, no6, 5);
    No *no7 = adicionar(a, no6, 7);
    no6->esquerda = no5;
    no6->direita = no7;

    percorrerPreOrder(a->raiz);
    printf("\n");
    percorrerInOrder(a->raiz);
    printf("\n");
    percorrerPosOrder(a->raiz);
}
