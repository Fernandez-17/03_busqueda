#include <iostream>
using namespace std;

int Busqueda_secuencial_ordenado(int array [], int n,int dato){
	int i = 0;
	int pos;
	while ( i < n && array [i] < dato){
		i = i+1;
	}
	if( i >=n || array [i] != dato){
		return pos = -i;
	}else{
		return pos = i;
	}
}

int Busqueda_secuencial_desordenada (int array [], int n, int dato){
	int i = 0 ;
	int pos = 0 ;
	while ( i <n && array[i] != dato){
		i = i+1;
	}
	if (i < n){
		return pos = i;		
	}else{
		return pos = -i;
	}
}
int main ( ){
	
	int array [50];
	int tam;
	
	cout << "\nIngrese la cantidad de elementos del arreglo: ";
	cin  >> tam;
	cout << "\n  Elementos del Arreglo " << endl;
	for (int i = 0; i < tam ;i++){
		cout << "Elemento ["<< i+1<<"] : ";
		cin  >> array [i];
	}
	
	cout << "\n        ARREGLO      " << endl;
	for (int i =0; i<tam ;i++){
		cout << array [i] <<" ";
	}
	cout << endl;
	
	int elemento_buscar;
	cout << "\nIngrese el elemento que desea buscar en el arreglo : ";
	cin  >> elemento_buscar;
	
	int opcion;
	cout << "\n ¿El arreglo esta ordenado?" << endl;
	cout << "1. Si  " << endl;
	cout << "2. No  " << endl;
	cout << "\n Seleccione un opcion: ";
	cin  >> opcion;
	
	int resultado;
	switch (opcion){
		case 1:
			resultado = Busqueda_secuencial_ordenado(array ,tam, elemento_buscar);
			if (resultado > 0){
				cout << "\nEl elemento que busca se encontro en la posicion " << resultado +1<< "." << endl;
			} else {
				cout << "\nEl elemento que busca No se encontro. " << endl;
			}
			break;
		case 2:
			resultado = Busqueda_secuencial_desordenada(array,tam, elemento_buscar);
			if (resultado > 0){
				cout << "\nEl elemento que busca se encontro en la posicion " << resultado +1 << "."<< endl;
			} else {
				cout << "\nEl elemento que busca No se encontro. " << endl;
			}
			break;
		default:
			cout << "\nIntentelo nuevamente" << endl;
			break;
	}
	return 0;
}
