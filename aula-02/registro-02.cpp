#include <iostream>
using namespace std;

struct aluno{   //criando um tipo, registro
	int matricula;
	float nota;
	char turma;
};

main(){
	const int TAM_MAX_VETOR = 2; //criar registro para "n" alunos usando o vetor
	int i;
	float mediaA = 0;
	struct aluno alunos[TAM_MAX_VETOR];
	for (i=0; i< TAM_MAX_VETOR; i++){
		cout << "Digite matricula do " << i+1 << "o aluno: ";
		cin >> alunos[i].matricula;
		cout << "Digite nota do "<< i+1 << "o aluno: ";	
		cin >> alunos[i].nota;
		cout << "Digite a turma do "<< i+1 << "o aluno: ";	
		cin >> alunos[i].turma;
	}
	cout << "\nAlunos cadastrados: \n";
	for (i=0; i< TAM_MAX_VETOR; i++){
		cout << "Matricula: " << alunos[i].matricula;
		cout << "\nNota: " << alunos[i].nota;
		cout << "\nTurma: " << alunos[i].turma << " \n";
	}
	//fazer pesquisa dos alunos
	cout << "\nLista de Alunos com nota maior que 7 da Turma A: \n";
	for(i=0; i< TAM_MAX_VETOR; i++){
		if((alunos[i].turma == 'a')&&(alunos[i].nota>=7)){
			cout << "\nMatricula: " << alunos[i].matricula;
			cout << "\nNota: "<< alunos[i].nota;
		}
	}
	cout << "\nMedia das notas da turma A";
	for(i=0; i< TAM_MAX_VETOR; i++){
		if(alunos[i].turma == 'a'){
			mediaA = alunos[i].nota
			cout << "\nMatricula: " << alunos[i].matricula;
			cout << "\nNota: "<< alunos[i].nota;
		}
	}
	
	cout << "\nMedia das notas da turma B;"
	
	
	
	
	
	
	
}
