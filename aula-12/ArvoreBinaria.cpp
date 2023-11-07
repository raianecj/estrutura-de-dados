#include <iostream>
#include <string>

using namespace std;

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_criavazia(void) {
    return NULL;
}

Arv* arv_cria(int c) {
    Arv* novo = (Arv*)malloc(sizeof(Arv));
    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Arv* arv_libera(Arv* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv* a) {
    return (a == NULL);
}

int arv_pertence(Arv* a, int c) {
    if (a == NULL) {
        return 0;
    } else {
        return (a->info == c || arv_pertence(a->esq, c) || arv_pertence(a->dir, c));
    }
}

void arv_inordem(Arv* a) {
    if (a != NULL) {
        arv_inordem(a->esq);
        cout << a->info << " ";
        arv_inordem(a->dir);
    }
}

void arv_preordem(Arv* a) {
    if (a != NULL) {
        cout << a->info << " ";
        arv_preordem(a->esq);
        arv_preordem(a->dir);
    }
}

void arv_posordem(Arv* a) {
    if (a != NULL) {
        arv_posordem(a->esq);
        arv_posordem(a->dir);
        cout << a->info << " ";
    }
}

void arv_imprime(Arv* a) {
    if (a != NULL) {
        arv_imprime(a->esq);
        cout << a->info << " ";
        arv_imprime(a->dir);
    }
}

int main() {
    Arv* a = arv_cria(34);
    a->esq = arv_cria(25);
    a->esq->esq = arv_cria(16);
    a->esq->esq->esq = arv_cria(14);
    a->esq->esq->dir = arv_cria(1);
    a->esq->esq->dir->dir = arv_cria(8);
    a->esq->esq->dir->esq = arv_cria(18);
    a->esq->dir = arv_cria(28);
    a->esq->dir->esq = arv_cria(26);
    a->esq->dir->dir = arv_cria(33);
    a->esq->dir->dir->esq = arv_cria(50);
    a->esq->dir->dir->esq->esq = arv_cria(40);
    a->esq->dir->dir->esq->esq->esq = arv_cria(30);
    a->esq->dir->dir->esq->esq->dir = arv_cria(42);
    a->esq->dir->dir->esq->dir->esq = arv_cria(53);
    a->esq->dir->dir->esq->dir->esq->esq = arv_cria(51);
    a->esq->dir->dir->esq->dir->esq->dir = arv_cria(55);

    arv_imprime(a);
    cout << "\tArvore montada.";
    cout << "\n";
    arv_preordem(a);
    cout << "\tArvore pre-ordem.";
    cout << "\n";
    arv_inordem(a);
    cout << "\tArvore in-ordem.";
    cout << "\n";
    arv_posordem(a);
    cout << "\tArvore pos_ordem.";

    return 0;
}
