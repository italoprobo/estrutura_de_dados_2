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