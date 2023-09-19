#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_FILA 5 // Tamanho maximo da fila circular

using namespace std;
struct DADOS_ALUNO {
	int CodAluno;
	char Nome[100], Turma;
	bool Removido; // indica se o elemento foi removido
	float Nota;
};

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], char Turma, float Nota, int &FimFila, int &TotalFila);
bool Exibir (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool Desenfileirar (DADOS_ALUNO Fila[], int &IniFila, int &TotalFila);
bool ExibirTurmaA (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool ExibirTurmaB (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool ExibirMediaTurmaA(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila, float &MediaTurmaA);
bool ExibirMaiorNota(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila, float &MaiorNota, char &TurmaMaiorNota);


int main(){
	struct DADOS_ALUNO FilaAlunos[MAX_FILA]; //Fila
	int IniFila = 0; // Inicio da fila
	int TotalFila = 0; // Total de elementos na fila
	int FimFila = 0; // Fim da fila
	bool Ret; 
	int CodAluno, opcao;
	char Nome[100], Turma; 
	float Nota, MediaTurmaA, MaiorNota;
	char TurmaMaiorNota;

	
	do {
		// escolhendo a opção
		cout << "\n1 - Enfileirar \n";
		cout << "\n2 - Exibir \n";
		cout << "\n3 - Desenfileirar \n";
		cout << "\n4 - Exibir alunes da Turma A \n";
		cout << "\n5 - Exibir alunes da Turma B \n";
		cout << "\n6 - Exibir media das notas dos alunos da Turma A \n";
		cout << "\n7 - Exibir maior nota geral entre as Turmas A e B \n";
		cout << "\n8 - Sair \n";
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
				cout << "Digite a nota do aluno: ";
				cin >> Nota;
				Ret = Enfileirar(FilaAlunos, CodAluno, Nome, Turma, Nota, FimFila, TotalFila);
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
		case 6: Ret = ExibirMediaTurmaA(FilaAlunos, IniFila, FimFila, TotalFila, MediaTurmaA);
				if(Ret == false){
					cout << "\nNao foi possivel exibir media da turma A." << endl;
				}
				break;
		case 7: Ret = ExibirMaiorNota(FilaAlunos, IniFila, FimFila, TotalFila, MaiorNota, TurmaMaiorNota);
				if(Ret == false){
					cout << "\nNao foi possivel exibir maior nota geral entre as turmas." << endl;
				}
				break;
		case 8: cout << "\nSaindo do Programa!";
				break;
		default: cout << "\n\nERRO: A opcao digitada não e valida. Tente novamente...\n";
	} //fim do switch
}while(opcao!=8);
getch();
	return 0;
}
// Função para enfileirar um aluno na fila
bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], char Turma, float Nota, int &FimFila, int &TotalFila){
	if(TotalFila == MAX_FILA){
		cout << "ERRO: Fila cheia.";
		return false;
	}
	else {
		Fila[FimFila].CodAluno = CodAluno;
		strcpy(Fila[FimFila].Nome, Nome);
		Fila[FimFila].Turma = Turma;
		Fila[FimFila].Nota = Turma;
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
		cout << "Nota: " << Fila[ind].Nota << endl;
	}
}else {
	for (ind = IniFila; ind < MAX_FILA; ind ++){
		if (Fila[ind].Removido == false){
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
			cout << "Nota: " << Fila[ind].Nota << endl;
		}
	}
	for (ind = 0; ind < FimFila; ind ++){
		if (Fila[ind].Removido == false) {
			cout << "Codigo do Aluno: " << Fila [ind].CodAluno << endl;
			cout << "Nome: " << Fila[ind].Nome << endl;
			cout << "Turma: " << Fila[ind].Turma << endl;
			cout << "Nota: " << Fila[ind].Nota << endl;
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
// Função ExibirMediaTurmaA
bool ExibirMediaTurmaA(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila, float &MediaTurmaA) {
    int ind;
    int contador = 0;
    float somaNotas = 0;

    if (TotalFila == 0) {
        cout << "ERRO: Fila vazia." << endl;
        return false;
    }

    if (IniFila < FimFila) {
        for (ind = IniFila; ind < FimFila; ind++) {
            if (Fila[ind].Turma == 'A') {
                somaNotas += Fila[ind].Nota;
                contador++;
            }
        }
    } else {
        for (ind = IniFila; ind < MAX_FILA; ind++) {
            if (Fila[ind].Removido == false && Fila[ind].Turma == 'A') {
                somaNotas += Fila[ind].Nota;
                contador++;
            }
        }
        for (ind = 0; ind < FimFila; ind++) {
            if (Fila[ind].Removido == false && Fila[ind].Turma == 'A') {
                somaNotas += Fila[ind].Nota;
                contador++;
            }
        }
    }

    if (contador > 0) {
        MediaTurmaA = somaNotas / contador;
        cout << "\nMedia da Turma A: " << MediaTurmaA << endl;
        return true;
    } else {
        cout << "\nNao ha alunos na Turma A." << endl;
        return false;
    }
}
	

// Função ExibirMaiorNota entre as Turmas A e B
bool ExibirMaiorNota(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila, float &MaiorNota, char &TurmaMaiorNota) {
    int ind;
    bool encontrouNota = false;

    if (TotalFila == 0) {
        cout << "ERRO: Fila vazia." << endl;
        return false;
    }

    MaiorNota = -1; // Inicializa com um valor impossível de nota
    TurmaMaiorNota = ' ';

    if (IniFila < FimFila) {
        for (ind = IniFila; ind < FimFila; ind++) {
            if (Fila[ind].Nota > MaiorNota) {
                MaiorNota = Fila[ind].Nota;
                TurmaMaiorNota = Fila[ind].Turma;
                encontrouNota = true;
            }
        }
    } else {
        for (ind = IniFila; ind < MAX_FILA; ind++) {
            if (Fila[ind].Nota > MaiorNota) {
                MaiorNota = Fila[ind].Nota;
                TurmaMaiorNota = Fila[ind].Turma;
                encontrouNota = true;
            }
        }
        for (ind = 0; ind < FimFila; ind++) {
            if (Fila[ind].Nota > MaiorNota) {
                MaiorNota = Fila[ind].Nota;
                TurmaMaiorNota = Fila[ind].Turma;
                encontrouNota = true;
            }
        }
    }

    if (encontrouNota) {
        cout << "\nMaior nota: " << MaiorNota << " (Turma " << TurmaMaiorNota << ")" << endl;
        return true;
    } else {
        cout << "\nNão foi encontrada nenhuma nota." << endl;
        return false;
    }
}
	
