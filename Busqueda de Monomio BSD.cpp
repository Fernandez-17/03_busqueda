//1.  Se tiene un polinomio almacenado en un arreglo. Se pide leer un monomio y buscar si forma parte del polinomio. Usa búsqueda secuencial

#include <iostream>
using namespace std;

struct Monomio {
	int coeficiente;
	int exponente;
};

int Buscar_monomio_secuencial_desordenado (Monomio array[],int n, int coef,int exp){
	int pos =0;
	int i = 0;
	while ( i < n ){
	    if (array[i].coeficiente == coef && array[i].exponente == exp){
		    return i ;
		}
		i = i+1;
	}
	return pos = -i;
	
}
int main (){
	Monomio array [50];
	int tam,resultado;
	
	cout << "\nIngrese la cantidad de monomios del polinomio : ";
	cin  >> tam;
        cout << "\n------------------"<< endl;	
	for (int i= 0; i< tam; i++){
		cout << "\nMonomio ["<< i+1 << "] :\n" << endl;
		cout << "Coeficiente : ";
		cin  >> array[i].coeficiente;
		cout << "Exponente : ";
		cin  >> array[i].exponente;
		cout << "------------------"<< endl;
	}
	int coef_buscar ,exp_buscar;
	cout << "\nIngrese el monomio que desea buscar \n" << endl;
	cout << "Coeficiente : ";
	cin  >> coef_buscar;
	cout << "Exponente : ";
	cin  >>exp_buscar;
	
	resultado = Buscar_monomio_secuencial_desordenado (array,tam,coef_buscar,exp_buscar);
	
	if(resultado >=0){
	cout << "\nEl monomio de coeficiente "<<coef_buscar<<" y exponente "<<exp_buscar<<" buscado se encuentra en la posicion "<<resultado+1<<" ."<< endl;		
	}else{
	cout << "\nEl monomio de coeficiente "<<coef_buscar<<" y exponente "<<exp_buscar<<" buscado No se encuentra en el polinomio."<< endl;
	}

	return 0;
}
