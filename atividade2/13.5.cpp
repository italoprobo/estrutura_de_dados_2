#include "funcoes.hpp"

int main() {
    No* raiz = NULL;
    raiz = insereNo(raiz, 15);
    insereNo(raiz, 30);
    insereNo(raiz, 35);
    insereNo(raiz, 34);
    insereNo(raiz, 57);

    printf("type any number: ");
    int x;
    scanf("%d", &x);

    if (tem(raiz, x)) {
        printf("Number %d find on tree!", x);
    }else {
        printf("Number %d does not find on tree!", x);
    }

    return 0;
}
