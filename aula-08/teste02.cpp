//Atividade sobre pilhas

#include <iostream>
#include <conio.h>
#define TAM 5

using namespace std;

void empilha (int [], int &t, int v);
int desempilha (int p[], int &t, int &v);
void mostraTopo(int p[], int &t);
void situacaoPilha(int p[],int &t);
void mostraMaior(int p[], int t);
void mostraPares(int p[], int t);
void mostraImpares(int p[],int t);

main (){
	int op, val, topo =-1, pilha [TAM],resp;
	do{
		system("cls");
		system("color f0");
		cout<<"\nPILHA (LIFO- Last In - First Out ) \n\n";
		cout<<"\n1- Inserir um valor na pilha";
		cout<<"\n2- Remover um valor na pilha";
		cout<<"\n3- Mostrar o elemento do topo da pilha";
		cout<<"\n4- Mostrar situacao da pilha";
		cout<<"\n5- Mostrar o maior elemento da pilha";
        cout<<"\n6- Mostrar elementos pares da pilha";
        cout<<"\n7- Mostrar elementos impares da pilha";
        cout<<"\n8- Sair";
		cout<<"\nOpcao: ";
		cin >>op;
		system("cls");
		
		switch(op){
			case 1: cout <<"Digite o valor a ser empilhado: "; cin >>val;
					empilha(pilha, topo, val);
					break;
			case 2: resp=desempilha(pilha, topo, val);
					if(resp==0){
						cout<<"\nATENCAO! Pilha Vazia\n";
					} else {
						cout<<"\nValor removido: "<<val;
					}
					break;
			case 3: mostraTopo(pilha, topo);
					break;
			case 4: situacaoPilha(pilha, topo);
					break;
			case 5: mostraMaior(pilha, topo);
            		break;
        	case 6: mostraPares(pilha, topo);
            		break;
        	case 7: mostraImpares(pilha, topo);
            		break;
        	case 8: cout << "\nPrograma basico da Pilha\n";
            		break;
        default: cout << "\nOPCAO INVALIDA!\n";
		}
		cout<<"\n\n";
		system("pause");
	}while (op!=8);
}
//Insere
void empilha(int p[],int &t, int v){
	if(t == TAM-1)
		cout<<"\nATENCAO! Pilha cheia\n";
	else {
		t++; //atualiza o topo
		p[t] = v; //pilha receve valor
	}
}
//Remove
int desempilha(int p[], int &t, int &v){
	if (t == -1)
		return 0;
	else {
		v=p[t]; //guarda o valor do topo
		t--; //atualiza o topo
		return 1;
	}
}
//Mostra a pilha
void mostraTopo(int p[], int &t){
	if(t == -1)
		cout<<"\nATENCAO!Pilha vazia\n";
	else {
		cout<<"\nElemento do Topo da PILHA: "<<p[t];
	}
}
//Mostra situacao da Pilha
void situacaoPilha(int p[], int&t){
	int i, maior;
	if(t == -1)
	cout<<"\nATENCAO! Pilha vazia\n";
	else if (t == TAM)cout<<"\nATENCAO! Pilha cheia\n";
	else 
		cout<<"\nTotal de elementos na pilha: "<<t+1<<"\n";
		cout<<"\n\nEspaco disponivel na pilha: "<<TAM-(t+1)<<"\n";
		cout<<"\n\nElementos na pilha: ";
		maior = p[0];
			for (i=0; i<t+1; i++){
				cout << " " <<p[i];
			}
}
// Mostra o maior elemento da pilha
void mostraMaior(int p[], int t) {
    if (t == -1) {
        cout << "\nATENCAO! Pilha vazia\n";
    } else {
        int maior = p[0];
        for (int i = 1; i <= t; i++) {
            if (p[i] > maior) {
                maior = p[i];
            }
        }
        cout << "\nMaior elemento da pilha: " << maior;
    }
}

// Mostra elementos pares da pilha
void mostraPares(int p[], int t) {
    if (t == -1) {
        cout << "\nATENCAO! Pilha vazia\n";
    } else {
        cout << "\nElementos pares da pilha: ";
        for (int i = 0; i <= t; i++) {
            if (p[i] % 2 == 0) {
                cout << p[i] << " ";
            }
        }
    }
}

// Mostra elementos ímpares da pilha
void mostraImpares(int p[], int t) {
    if (t == -1) {
        cout << "\nATENCAO! Pilha vazia\n";
    } else {
        cout << "\nElementos impares da pilha: ";
        for (int i = 0; i <= t; i++) {
            if (p[i] % 2 != 0) {
                cout << p[i] << " ";
            }
        }
    }
}
