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

main(){
	struct DADOS_ALUNO FilaAlunos[MAX_FILA]; //Fila
	int IniFila = 0; // Inicio da fila
	int TotalFila = 0; // Total de elementos na fila
	int FimFila = 0; // Fim da fila
	bool Ret; 
	int CodAluno;
	char Nome[100], Turma;
	
	cout << "Insercao: " << endl;
	cout << "Digite o codigo do aluno: ";
	cin >> CodAluno;
	cout << "Digite o nome do aluno: ";
	cin >> Nome;
	cout << "Digite a turma: ";
	cin >> Turma;
	
	Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, FimFila, TotalFila);
	if(Ret == true){
		cout << "Insercao efetuada com sucesso!" << endl;
}
	Ret = Exibir(FilaAlunos, IniFila, FimFila, TotalFila);
	if (Ret == false){
		cout << "Nao foi possivel exibir fila." << endl;
	}
	
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
		cout << "Código do Aluno: " << Fila [ind].CodAluno << endl;
		cout << "Nome: " << Fila[ind].Nome << endl;
		cout << "Turma: " << Fila[ind].Turma << endl;
	}
}else {
	for (ind = IniFila; ind < MAX_FILA; ind ++){
		if (Fila[ind].Removido == false){
			cout << "Código do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
	for (ind = 0; ind < FimFila; ind ++){
		if (Fila[ind].Removido == false) {
			cout << "Código do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
		}
	}
}
return true;
	
}
	
