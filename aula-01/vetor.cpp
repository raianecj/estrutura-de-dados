// vetor

#include <iostream> //biblioteca de entrada e saída cout e cin
#include <conio.h> // conexão entrada e saída

using namespace std; //para não precisar colocar o std::cout

main(){
	int i; 
	int maior;
	int menor;
	int idade[4];
	for (i=0; i<4; i++){
		cout<<"Digite o valor da "<< i+1 <<"a idade: "; //concatenar "<< <<"
		cin>>idade[i];
	}
	cout << "Idades digitadas:\n"; //apresentar as notas digitadas
	for (i=0; i<4; i++){
		cout<<idade[i]<< " - ";
	}
	maior = idade[0];
	menor = idade[0];
	for (i=0; i<4; i++){
		if (idade[i]>maior){ //se a idade atual é maior que a maior então 
			maior = idade[i]; //então troca o valor
		}
		if (idade[i]<menor){
			menor = idade[i]; //mostrar a menor idade
		}
	}
	cout<<"\nMaior idade digitada: "<< maior;
	cout<<"\nMenor idade digitada: "<< menor;


}
