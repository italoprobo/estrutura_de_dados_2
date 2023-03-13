#include "funcoes.hpp"

int main() {
    No* raiz = NULL;
    raiz = insereNo(raiz, 15);
    insereNo(raiz, 30);
    insereNo(raiz, 35);
    insereNo(raiz, 28);
    insereNo(raiz, 34);
    insereNo(raiz, 57);

    No* b = NULL;
    b = insereNo(b, 15);
    insereNo(b, 30);
    insereNo(b, 35);
    insereNo(b, 28);
    insereNo(b, 34);
    insereNo(b, 57);

    printf("%d", igual(raiz, b));

    return 0;
}
