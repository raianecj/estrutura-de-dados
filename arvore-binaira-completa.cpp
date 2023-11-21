#include <iostream>

using namespace std;

//Estrutura do nó para a árvore binária
struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;  

// Função para imprimir a árvore binária em percurso em ordem
void arv_inordem(Arv* a) {
    if (a != NULL) {
        arv_inordem(a->esq);
        cout << a->info << " ";
        arv_inordem(a->dir);
    }
}

// Função para imprimir a árvore binária em pré-ordem
void arv_preordem(Arv* a) {
    if (a != NULL) {
        cout << a->info << " ";
        arv_preordem(a->esq);
        arv_preordem(a->dir);
    }
}

// Função para imprimir a árvore binária em pós-ordem
void arv_posordem(Arv* a) {
    if (a != NULL) {
        arv_posordem(a->esq);
        arv_posordem(a->dir);
        cout << a->info << " ";
    }
}

// Função para imprimir arvore montada
void arv_imprime(Arv* a) {
    if (a != NULL) {
        arv_imprime(a->esq);
        cout << a->info << " ";
        arv_imprime(a->dir);
    }
}
// Função para criar um novo nó
Arv* arv_cria(int c) {
    Arv* novo = new Arv;
    novo->info = c;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para calcular a altura 
int arv_altura(Arv* a){
	if (a == NULL){
		return -1; // para arvore vazia
	} else {
		int altura_esq = arv_altura(a->esq);
		int altura_dir = arv_altura(a->dir);
		return 1 + max(altura_esq, altura_dir);
	}
}


// Função para liberar a memória alocada para a árvore binária
Arv* arv_libera(Arv* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        delete a;
    }
    return NULL;
}

int main() {
    // Criando uma árvore binária de exemplo
    Arv* a = arv_cria(1);
    a->esq = arv_cria(2);
    a->dir = arv_cria(3);
    a->esq->esq = arv_cria(4);
    a->esq->dir = arv_cria(5);
    a->esq->esq->esq = arv_cria(6);
    a->esq->esq->dir = arv_cria(7);
    a->esq->esq->esq->esq = arv_cria(8);
    a->esq->esq->esq->dir = arv_cria(9);
    

    // Imprimindo a árvore binária 
    cout << "Arvore montada: ";
    arv_imprime(a);
    cout << endl;
    
    cout << "Arvore in-ordem: ";
    arv_inordem(a);
    cout << endl;

    cout << "Arvore pre-ordem: ";
    arv_preordem(a);
    cout << endl;

    cout << "Arvore pos-ordem: ";
    arv_posordem(a);
    cout << endl;
    
    int altura = arv_altura(a);
    cout << "Altura da arvore: " << altura << endl;;
    

    // Limpa a memoria
    arv_libera(a);

    return 0;
}
