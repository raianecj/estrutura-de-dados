//Exemplo de criação de um tipo de registro basico

#include <iostream>
using namespace std;

struct aluno{   //criando um tipo, registro
	int matricula;
	float nota;
	char turma;
};

main(){
	struct aluno aluno1;
	cout << "Digite matricula do aluno: ";
	cin >> aluno1.matricula;
	cout << "Digite nota do aluno: ";	
	cin >> aluno1.nota;
	cout << "Digite a turma do aluno: ";	
	cin >> aluno1.turma;
	cout << "\nAlunos cadastrados: \n";
	cout << "Matricula " << aluno1.matricula;
	cout << "\nNota " << aluno1.nota;
	cout << "\nTurma " << aluno1.turma;
	
	
	
}
