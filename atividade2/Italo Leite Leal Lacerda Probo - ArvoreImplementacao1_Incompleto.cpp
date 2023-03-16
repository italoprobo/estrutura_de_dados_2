#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
}Arv;


Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;
	
}

void imprime(Arv *n){		
					
			if (n!=NULL){
					
				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
			}

int calculaQuantNos(Arv *no){
	if(no == NULL){
		return 0;
	}else{
		return 1 + calculaQuantNos(no->esq) + calculaQuantNos(no->dir);
	}
}

int calculaQuantNosFolha(Arv *no){
	if(no == NULL){
		return 0;
	}else if(no->esq == NULL && no->dir == NULL){
		return 1;
	}else{
		calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);
	}
}
		

int alturaArvore(Arv *no){	        
    if(no == NULL) {
        return 0;
    }
    else{
        int alturaesquerda = alturaArvore(no->esq);
        int alturadireita = alturaArvore(no->dir);
        if(alturaesquerda > alturadireita){
            return 1 + alturaesquerda;
        }else {
            return 1 + alturadireita;
        }
    }
}
   
int procura(Arv *no, char valor){
	if(no == NULL){
		return 0;
	}else if(no->info == valor){
		return 1;
	}else if(no->info < valor){
		return procura(no->dir, valor);
	}else{
		return procura(no->esq, valor);
	}
}


// remove o n� procurado. Se o n� tiver filhos, remova tamb�m os filhos		
void removeSubArvore(Arv *no, char valor) {
    if (no == NULL) {
        return;
    }
    if (no->info == valor) {
        if (no->esq != NULL) {
            removeSubArvore(no->esq, no->esq->info);
        }
        if (no->dir != NULL) {
            removeSubArvore(no->dir, no->dir->info);
        }
        free(no);
        return;
    }
    if (no->esq != NULL && procura(no->esq, valor)) {
        removeSubArvore(no->esq, valor);
        return;
    }
    if (no->dir != NULL && procura(no->dir, valor)) {
        removeSubArvore(no->dir, valor);
        return;
    }
}


	        
int main() {
	Arv *c = arvore('c', NULL, NULL);
	Arv *e = arvore('e', NULL, NULL);
	Arv *a = arvore('a', NULL, NULL);
	Arv *d = arvore('d', NULL, NULL);
	Arv *h = arvore('h', NULL, NULL);
	Arv *k = arvore('k', NULL, NULL);
	Arv *p = arvore('p', NULL, NULL);
	Arv *v = arvore('v', NULL, NULL);
	Arv *r = arvore('r', k, p);
	Arv *l = arvore('l', NULL, r);
	Arv *f = arvore('f', l, v);
	Arv *g = arvore('g', h, NULL);
	Arv *b = arvore('b', c, d);
	Arv *n = arvore('n', NULL, e);
	Arv *m = arvore('m', n, NULL);
	Arv *j = arvore('j', m, f);
	Arv *i = arvore('i', j, g);
	Arv *t = arvore('t', NULL, NULL);
	Arv *s = arvore('s', NULL, t);
	Arv *u = arvore('u', s, NULL);
	Arv *q = arvore('q', NULL, u);
	Arv *o = arvore('o', q, i);
	Arv *root = arvore('x', a, b);
	root = arvore('z', root, o);
    
    imprime(root);
    cout << endl;
    
    cout << "Número de nós na árvore: " << calculaQuantNos(root) << endl;
    
    cout << "Número de nós folha na árvore: " << calculaQuantNosFolha(root) << endl;
    
    cout << "Altura da árvore: " << alturaArvore(root) << endl;
    
    char valorProcurado = 'h';
    if (procura(root, valorProcurado)) {
        cout << "O valor " << valorProcurado << " foi encontrado na árvore." << endl;
    } else {
        cout << "O valor " << valorProcurado << " não foi encontrado na árvore." << endl;
    }
    
    char valorRemover = 'f';
    removeSubArvore(root, valorRemover);
    
    imprime(root);
    cout << endl;
    
    return 0;
}
