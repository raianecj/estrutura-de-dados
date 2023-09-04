#include <iostream>
using namespace std;
struct aluno{
	int matricula;
	float nota;
	char turma;
};
main(){
	const int TAM_VETOR = 5;
	struct aluno alunos[TAM_VETOR];
	float mediaTurmaA=0; int contaTurmaA=0;
	float mediaTurmaB=0; int contaTurmaB=0;	
	float maiorNotaA=0, maiorNotaB=0;
	int qtdA=0, qtdB=0;
	int i;
	for (i=0; i<TAM_VETOR; i++){
	 cout << "\nDigite matricula do " << i+1 <<"o aluno: ";
	 cin >> alunos[i].matricula;
	 cout << "\nDigite nota do " << i+1 << "o aluno: ";
	 cin >> alunos[i].nota;
	 cout << "\nDigite a turma do " << i+1 <<"o aluno: ";
	 cin >> alunos[i].turma;
	 	if ((alunos[i].turma == 'A')||(alunos[i].turma == 'a'))	{
	 		contaTurmaA++;
	 		mediaTurmaA += alunos[i].nota;
	 		 if (alunos[i].nota>maiorNotaA){
	 		 	maiorNotaA = alunos[i].nota;
			  }
		 }	
	 	if ((alunos[i].turma == 'B')||(alunos[i].turma == 'b'))	{
	 		contaTurmaB++;
	 		mediaTurmaB += alunos[i].nota;
	 		 if (alunos[i].nota>maiorNotaB){
	 		 	maiorNotaB = alunos[i].nota;
			  }
		 }			 
	}
	cout << "\nAlunos cadastrados: \n";
	for (i=0; i<TAM_VETOR; i++){
	 cout << "\nMatricula: " << alunos[i].matricula;
	 cout << "\nNota: " << alunos[i].nota;
	 cout << "\nTurma: " << alunos[i].turma;
	}	
	float mediaA = mediaTurmaA/contaTurmaA;
	float mediaB = mediaTurmaB/contaTurmaB;
	cout << "\nMedia das notas da Turma A: " << mediaA;
	cout << "\nMedia das notas da Turma B: " << mediaB;
	cout << "\nMaior nota da turma A: " << maiorNotaA;
	cout << "\nMaior nota da turma B: " << maiorNotaB;
	for (i=0; i<TAM_VETOR; i++){
		if ((alunos[i].turma == 'A')||(alunos[i].turma == 'a'))	{
			if (alunos[i].nota >= mediaA){
				qtdA++;
			}
		}
	}
	for (i=0; i<TAM_VETOR; i++){
		if ((alunos[i].turma == 'B')||(alunos[i].turma == 'b'))	{
			if (alunos[i].nota >= mediaB){
				qtdB++;
			}
		}
	}
	cout << "\nQuantidade de alunos com " << 
            "a nota maior que a media da Turma A:" << qtdA;
	cout << "\nQuantidade de alunos com " << 
            "a nota maior que a media da Turma B:" << qtdB;	            
}	
