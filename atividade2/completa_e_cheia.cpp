#include "funcoes.hpp"

int main() {
    No* raiz = NULL;
    raiz = insereNo(raiz, 15);
    insereNo(raiz, 30);
    insereNo(raiz, 35);
    insereNo(raiz, 28);
    insereNo(raiz, 34);
    insereNo(raiz, 57);

    if (eh_arvore_binaria_cheia(raiz)) {
        printf("A arvore eh binaria cheia.\n");
    } else {
        printf("A arvore nao eh binaria cheia.\n");
    }

    if (completa(raiz)) {
        printf("A arvore eh completa.\n");
    } else {
        printf("A arvore nao eh completa.\n");
    }

    return 0;
}