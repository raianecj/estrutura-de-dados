#include <iostream> //biblioteca de entrada e saída cout e cin
#include <conio.h> // conexão entrada e saída

using namespace std; //para não precisar colocar o std::cout

main(){
	char nome [21];
	cout << "Digite seu nome: ";
	gets(nome); // uma função pronta para ler uma cadeida de caracteres, nome
	cout << "O nome digitado foi: ";
	puts(nome); // imprime a cadeia de caracteres, nome
	
	// para ler uma posição especifica do nome, o vetor
	cout << "Primeira letra: " << nome [0];
	
}
