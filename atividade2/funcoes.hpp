#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerda, *direita;
} No;

No* novoNo(int valor) {
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

No* insereNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return novoNo(valor);
    } else {
        if (valor < raiz->valor) {
            raiz->esquerda = insereNo(raiz->esquerda, valor);
        } else {
            raiz->direita = insereNo(raiz->direita, valor);
        }
        return raiz;
    }
}


int tem(No* n, int x){
        if (n == NULL) {
            return 0;
        } else if(n->valor == x) {
            return 1;
        } else if (n->valor < x) {
            tem(n->direita, x);
        } else {
            tem(n->esquerda, x);
        }
}

int eb(No* n){
    if (n == NULL) {
        return 0;
    } 
    if (n->esquerda == NULL && n->direita == NULL) {
        return 1;
    } 
    if (n->esquerda != NULL && n->direita != NULL) {
        return eb(n->esquerda) && eb(n->direita);
    }

    return 0;
    
}

int altura_arvore(No* n){
    if(n == NULL) {
        return 0;
    }
    else{
        int alturaesquerda = altura_arvore(n->esquerda);
        int alturadireita = altura_arvore(n->direita);
        if(alturaesquerda > alturadireita){
            return 1 + alturaesquerda;
        }else {
            return 1 + alturadireita;
        }
    }
}

int qtd_folhas(No* n){
    if(n == NULL){
        return 0;
    }else if(n->esquerda == NULL && n->direita == NULL){
        return 1;
    }else{
        return qtd_folhas(n->esquerda) + qtd_folhas(n->direita);
    }
}

int qtd_nos(No* n){
    if(n == NULL) {
        return 0;
    } else {
        return 1 + qtd_nos(n->esquerda) + qtd_nos(n->direita);
    }
}

int igual(No* a, No* b){
    if(a == NULL || b == NULL){
        return 0;
    } 
    if (a == NULL && b == NULL) {
        return 1;
    } 
    if (a->valor == b->valor) {
        return 1;
    } 
    return igual(a->esquerda, b->esquerda) && igual(a->direita, b->direita);
}

int exibe_dec(No *n){
    if(n != NULL){
        exibe_dec(n->direita);
        printf("%d ", n->valor);
        exibe_dec(n->esquerda);
    }
}

int completa(No *n){
    if(n == NULL){
        return 0;
    }

    int altura = altura_arvore(n);
    int qnt_nos = qtd_nos(n);

    if(qnt_nos == (1 << altura) - 1){
        return 1;
    }else{
        return 0;
    }
}

int eh_arvore_binaria_cheia(No* raiz) {
    if (raiz == NULL) {
        return 0; 
    }
    
    int altura_esquerda = altura_arvore(raiz->esquerda);
    int altura_direita = altura_arvore(raiz->direita);
    
    if (altura_esquerda != altura_direita) {
        return 0; 
    } else {
        int qtd_nos_esquerda = qtd_nos(raiz->esquerda);
        int qtd_nos_direita = qtd_nos(raiz->direita);
        int qtd_nos_total = qtd_nos_esquerda + qtd_nos_direita + 1;
        
        return qtd_nos_total == (1 << altura_esquerda) - 1;
    }
}