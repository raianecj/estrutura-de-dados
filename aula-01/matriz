#include <iostream> //biblioteca de entrada e saída cout e cin
#include <conio.h> // conexão entrada e saída

using namespace std; //para não precisar colocar o std::cout

main(){
	int Matriz [4][4], i,j;
	for (i=0; i<4; i++){ //carregando uma matriz
		for(j=0; j<4; j++){
			cout<<"\nDigite o elemento("<<i<<"-"<<j<<") da matriz: ";
			cin >> Matriz[i][j];
		}
	}
	for (i=0; i<4; i++){ //impressão de toda a matriz carregada
		cout << "\n";
		for(j=0; j<4; j++){
			cout << Matriz[i][j] << "\t"; // \t tabulação
		}
	}
	cout << "\nElementos da Diagonal Principal: ";
	for (i=0; i<4; i++){ 
		for(j=0; j<4; j++){
			if (i==j){ //lógica da Diagonal Principal
				cout << Matriz[i][j] << "\t";
			}
			 
		}
	}
	cout << "\nElementos da Diagonal Secundaria: ";
	for (i=0; i<4; i++){ 
		for(j=0; j<4; j++){
			if (i + j == 3){ //lógica da Diagonal Secundaria
				cout << Matriz[i][j] << "\t";
			}
			 
		}
	}
}
