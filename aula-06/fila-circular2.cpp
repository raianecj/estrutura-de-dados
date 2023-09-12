#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_FILA 5 // Tamanho maximo da fila circular

using namespace std;
struct DADOS_ALUNO {
	int CodAluno;
	char Nome[100], Turma;
	bool Removido; // indica se o elemento foi removido
};

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], char Turma, int &FimFila, int &TotalFila);
bool Exibir (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool Desenfileirar (DADOS_ALUNO Fila[], int &IniFila, int &TotalFila);
bool ExibirTurmaA (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool ExibirTurmaB (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);

main(){
	struct DADOS_ALUNO FilaAlunos[MAX_FILA]; //Fila
	int IniFila = 0; // Inicio da fila
	int TotalFila = 0; // Total de elementos na fila
	int FimFila = 0; // Fim da fila
	bool Ret; 
	int CodAluno, opcao;
	char Nome[100], Turma;
	
	do {
		// escolhendo a opção
		cout << "\n1 - Enfileirar \n";
		cout << "\n2 - Exibir \n";
		cout << "\n3 - Desenfileirar \n";
		cout << "\n4 - Exibir alunes da Turma A \n";
		cout << "\n5 - Exibir alunes da Turma B \n";
		cout << "\n6 - Sair \n";
		cout << "\nDigite a Opcao: ";
		cin >> opcao;
		
	switch(opcao){
		case 1: cout << "Insercao: " << endl;
				cout << "Digite o codigo do aluno: ";
				cin >> CodAluno;
				cout << "Digite o nome do aluno: ";
				cin >> Nome;
				cout << "Digite a turma: (A) ou (B) ";
				cin >> Turma;
				Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila, TotalFila);
					if(Ret == true){
						cout << "\nInsercao efetuada com sucesso!" << endl;
					}
				system("cls");
				break;
		case 2: Ret = Exibir(FilaAlunos, IniFila, FimFila, TotalFila);
				if(Ret == false){
					cout << "\nNao foi possivel exibir a fila." << endl;
				}
				break;
		case 3: Ret = Desenfileirar (FilaAlunos, IniFila, TotalFila);
				if(Ret == false){
					cout << "\nNao foi possivel desenfileirar a fila." << endl;
				}
				break;
		case 4: Ret = ExibirTurmaA (FilaAlunos, IniFila, FimFila, TotalFila);
				if(Ret == false){
					cout << "\nNao foi possivel encontrar alunos da Turma A." << endl;
				}
				break;
		case 5: Ret = ExibirTurmaB (FilaAlunos, IniFila, FimFila, TotalFila);
				if(Ret == false){
					cout << "\nNao foi possivel encontrar alunos da Turma B." << endl;
				}
				break;
		
		case 6: cout << "\nSaindo do Programa!";
				break;
		default: cout << "\n\nERRO: A opcao digitada não e valida. Tente novamente...\n";
	} //fim do switch
}while(opcao!=6);
getch();
	
}
// Função para enfileirar um aluno na fila
bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], char Turma, int &FimFila, int &TotalFila){
	if(TotalFila == MAX_FILA){
		cout << "ERRO: Fila cheia.";
		return false;
	}
	else {
		Fila[FimFila].CodAluno = CodAluno;
		strcpy(Fila[FimFila].Nome, Nome);
		Fila[FimFila].Turma = Turma;
		Fila[FimFila].Removido = false;
		FimFila ++;
		/* Se chegou no fim da fila, então o proximo
		 elemento a ser inserido sera no inicio da fila */
		 if (FimFila == MAX_FILA)
		 	FimFila = 0;
		 	TotalFila ++;
	}
	return true;
}
// Função exibir
bool Exibir (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila){
int ind;
if (TotalFila == 0) {
	cout << "ERRO: Fila vazia.";
	return false;
}
if (IniFila < FimFila){
	for (ind = IniFila; ind < FimFila; ind++){
		cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
		cout << "Nome: " << Fila[ind].Nome << endl;
		cout << "Turma: " << Fila[ind].Turma << endl;
	}
}else {
	for (ind = IniFila; ind < MAX_FILA; ind ++){
		if (Fila[ind].Removido == false){
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
	for (ind = 0; ind < FimFila; ind ++){
		if (Fila[ind].Removido == false) {
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
}
return true;
}
// Função desenfileirar
bool Desenfileirar (DADOS_ALUNO Fila[], int &IniFila, int &TotalFila){
	int ind;
	int PosRem;
		if (TotalFila == 0){
			cout << "ERRO: Fila vazia.";
		return false;
		}
		// Indica que o elemento do inicio da fila foi removido
		Fila[IniFila].Removido = true;
		cout << "\nElemento desenfileirado com sucesso!\n";
		IniFila ++;
		// Se chegou no fim da fila, então o proximo elemento a ser removido será no inicio da fila
		if (IniFila == MAX_FILA)
			IniFila = 0;
TotalFila --;
return true;
}
// Função exibir alunos da Turma A 
bool ExibirTurmaA (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila){
	int ind;
	if (TotalFila == 0) {
	cout << "ERRO: Fila vazia.";
	return false;
}
cout << "\nAlunes da Turma A: \n";
	if(IniFila < FimFila){
		for (ind = IniFila; ind < FimFila; ind++){
			if(Fila[ind].Turma == 'A'){
				cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
				cout << "Nome: " << Fila[ind].Nome << endl;
			}
		
	}
}else{
	for (ind = IniFila; ind < MAX_FILA; ind ++){
		if (Fila[ind].Removido == false){
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
	for (ind = 0; ind < FimFila; ind ++){
		if (Fila[ind].Removido == false) {
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
}
return true;
}

// Função exibir alunos da Turma B
bool ExibirTurmaB (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila){
	int ind;
	if (TotalFila == 0) {
	cout << "ERRO: Fila vazia.";
	return false;
}
cout << "\nAlunes da Turma B: \n";
	if(IniFila < FimFila){
		for (ind = IniFila; ind < FimFila; ind++){
			if(Fila[ind].Turma == 'B'){
				cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
				cout << "Nome: " << Fila[ind].Nome << endl;
			}
		
	}
}else{
	for (ind = IniFila; ind < MAX_FILA; ind ++){
		if (Fila[ind].Removido == false){
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
	for (ind = 0; ind < FimFila; ind ++){
		if (Fila[ind].Removido == false) {
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
}
return true;
}

	
