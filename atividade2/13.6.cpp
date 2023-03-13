#include "funcoes.hpp"

int main() {
    No* raiz = NULL;
    raiz = insereNo(raiz, 15);
    insereNo(raiz, 30);
    insereNo(raiz, 35);
    insereNo(raiz, 28);
    insereNo(raiz, 34);
    insereNo(raiz, 57);

    printf("%d", eb(raiz));

    return 0;
}
