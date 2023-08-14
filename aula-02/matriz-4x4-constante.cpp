//Matriz 4x4 utilizando constante
#include <iostream>
using namespace std;
main(){
  const int TAM_MAX_MATRIZ = 4;
  int matriz[TAM_MAX_MATRIZ][TAM_MAX_MATRIZ];
  int i,j;
  int somaImparDP = 0;
  int somaParDS = 0;
  	for (i=0;i<TAM_MAX_MATRIZ; i++){
  		for (j=0; j<TAM_MAX_MATRIZ; j++){
  		    cout << "Digite elemento ("<<
			  i << "-" << j << "): ";	
			  cin >> matriz[i][j];
		  }
	  }	
	cout << "\nMatriz Digitada: \n";
	for (i=0;i<TAM_MAX_MATRIZ; i++){
		cout << "\n";
  		for (j=0; j<TAM_MAX_MATRIZ; j++){
  		cout << matriz[i][j]<< "\t";	
  		}
  	}
  	cout << "\nElementos da DP: \n";
	for (i=0;i<TAM_MAX_MATRIZ; i++){
		cout << "\n";
  		for (j=0; j<TAM_MAX_MATRIZ; j++){
  		  if (i==j){
		  cout << matriz[i][j]<< "\t";	
  		  }
  		  else{
  		  cout << " *\t";	
			}
  	    }
    }
  	cout << "\nElementos da DS: \n";
	for (i=0;i<TAM_MAX_MATRIZ; i++){
		cout << "\n";
  		for (j=0; j<TAM_MAX_MATRIZ; j++){
  		  if (i+j==TAM_MAX_MATRIZ-1){
		  cout << matriz[i][j]<< "\t";	
  		  }
  		  else{
  		  cout << " *\t";	
			}
  	    }
    }
	cout << "\nSoma dos elementos ímpares da DP: \n";
	for (i=0;i<TAM_MAX_MATRIZ; i++){
		for (j=0; j<TAM_MAX_MATRIZ; j++){
				if((i==j)&&(matriz[i][j]%2==1)){
					somaImparDP = somaImparDP + matriz[i][j];
				}  	
				
		}
	}
	cout << somaImparDP; 
	cout << "\nSoma dos elementos pares da DS: \n";
	for (i=0;i<TAM_MAX_MATRIZ; i++){
  		for (j=0; j<TAM_MAX_MATRIZ; j++){
  		  if ((i+j==TAM_MAX_MATRIZ-1)&&(matriz[i][j]%2==0)){
  		  		somaParDS = somaParDS + matriz[i][j];
			}
		}
	}
	cout << somaParDS;
}
