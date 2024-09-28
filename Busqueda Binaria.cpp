#include <iostream>
using namespace std;
void solicitar_datos(int array [], int &n){
	
	cout << "\nIngrese la cantidad de elementos del arreglo : ";
	cin  >> n;
	
	cout << "\n  Elementos del  arreglo  " << endl;
	for (int i = 0; i <n; i++){
		cout <<"Elemento ["<<i+1<<"] : ";
		cin  >> array [i];
	}
	
	cout << "\n  ARREGLO ACTUAL  \n"<< endl;
	for (int i =0; i<n ;i++){
		cout << array [i] << " ";
	}
	cout << endl;
}
 int Busqueda_binaria (int array [], int n, int dato){
 	int izq=0, der= n-1, m, pos ;
 	int centinela = 0;
 	while (izq <= der && centinela ==0){
	 	m = (izq+der)/2;
	 	if (array [m] == dato){
	 		centinela = 1;
		 }else{
		 	if(array [m] < dato){
		 		izq = m+1;
			 }else{
			 	der = m-1;
			 }
		 }
	 }
	 if( centinela ==1){
	 	pos = m;
	 }else{
	 	pos = -izq;
	 }
	 return pos ;
 }

int main (){

	int array [50];
	int tam;
	int resultado;
	solicitar_datos( array, tam);
	
	int elemento_buscar;
	cout << "\nIngrese el elemento que desea buscar : ";
	cin  >> elemento_buscar;
	
	resultado = Busqueda_binaria ( array, tam, elemento_buscar);
	if (resultado >= 0){
		cout << "\nEl elemento que esta buscando se encuentra en la posicion  " << resultado +1 << "  del arreglo."<< endl;
	} else{
	    cout << "\nEl elemento que esta buscando No se encuentro en el arreglo." << endl;
	}
	
	return 0;
}
