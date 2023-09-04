#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int num,valor;
    int*p;  // um ponteiro para inteiro p é declarado
            //um ponteiro é uma variavel que armazena o endereço de outra variavel

    num = 55;
    p = &num;   // O ponteiro p é atribuído com o endereço da variável num. Agora, p aponta para num.
    valor = *p;     //O valor apontado por p (ou seja, o valor da variável num) é atribuído à variável valor. Isso é uma atribuição indireta, onde *p desreferencia o ponteiro, dando acesso ao valor armazenado no endereço apontado por p

    cout << "\n" << valor;
    cout << "\nEndereco para onde o ponteiro aponta: " << p;    //Isso mostrará o endereço de memória da variável num
    cout << "\nValor da variavel apontada: " <<*p;  //O valor da variável apontada por p (ou seja, o valor da variável num) é impresso na tela novamente.
    getch();    //Isso aguarda que o usuário pressione uma tecla antes de encerrar o programa. É uma função geralmente usada para pausar a execução do programa até que o usuário tome alguma ação.

}
