#include<iostream>
using namespace std;

int secuencial_desordenado (int array [] , int n, int dato){
	int pos;
	int i = 0;
	
	while(i < n && array[i] != dato){
		i = i +1;	
	}
	if(i < n){
		pos = i;
	}else{
		pos = -1;
	}
	return pos;
}

int secuencial_ordenado (int array[] , int n, int dato){
	int pos;
	int i = 0;
	
	while(i < n && array[i] < dato){
		i = i +1;	
	}
	if(i >= n || array [i] !=dato){
		pos =-i-1;
	}else{
		pos = i+1;
	}
	return pos;
}

void solicitar_datos(int array [], int n){
	cout << "\nIngrese la cantidad de elementos del arreglo\n" << endl;
	cin  >> n ;
	
	for (int i =0 ;i <n ; i++){
		cout << "Elemento [" << i+1<<"] : ";
		cin  >> array [i] ;
	}
	
    cout << "\nArreglo actual " << endl;
	for (int i=0; i < n ; i++){
		cout << array [i] <<" ";
	}
	cout << endl;
}
	
int opciones (){
	int opcion;
	cout << "\n¿Los elementos del arreglo estan ordenados?\n" << endl;
	cout << "1.SI   "           << endl;
	cout << "2.No   "           << endl;
	cout << "\n Seleccione una opcion : ";
	cin  >> opcion ;
	return opcion;
}

int elemento_buscar(){
	int dato;
	cout << "\nIngrese el elemento que desea buscar" << endl;
	cout << "\n Elemento : ";
	cin  >> dato;
	return dato;
}

 int main( ){
 	int array [50];
 	int tam;
 	int dato;
 	int opcion;
 	int posicion;
 	do {
 	    solicitar_datos(array,tam);
 	    elemento_buscar ();
 	    opciones();
 	    
 		switch(opcion){
 			case 1:
 				posicion = secuencial_ordenado(array,tam,dato);
 				cout << "\nEl elemnto que esta buscando se encuentra en la posicion : " << posicion +1 << endl;
 				break;
 			case 2:
 				posicion = secuencial_desordenado(array,tam,dato);
 				if(posicion >0){
 				cout << "\nEl elemento que esta buscando se encuentra en la posicion : " << posicion +1 << endl;
				}else{
					cout << "\nEl elemento que esta buscando NO se encuentra" << endl;
				}
				break;
 			default:
 				cout << "       Intentelo de nuevo   " << endl;	
				break;	
		 }
		 	
	 } while (opcion!=3);
 	
 	return 0;
 }
