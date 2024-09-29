/*Se tienen los siguientes atributos de personal : DNI, nombres, día, mes y año de nacimiento. 
Se pide realizar una búsqueda binaria por fecha de nacimiento. Sugerencia: Use dos registros 
(personal y fecha) y tres funciones (uno para ordenar el arreglo por cada inserción, otro 
para la búsqueda y el último para comparar fechas). Asuma que nadie comparte la misma fecha 
de nacimiento*/

#include <iostream>
using namespace std;

struct Fecha {
	int dia;
	int mes;
	int anio;
};
struct Personal {
	string  DNI;
	string  nombre;
	Fecha  f_nacimiento;
};

bool Comparar_fechas(const Fecha &fecha1, const Fecha &fecha2) {
    if (fecha1.anio < fecha2.anio) {
        return true; 
    } else if (fecha1.anio > fecha2.anio) {
        return false; 
    }

    if (fecha1.mes < fecha2.mes) {
        return true; 
    } else if (fecha1.mes > fecha2.mes) {
        return false; 
    }

    return fecha1.dia < fecha2.dia; 
}


void Ordenar_por_fechas (Personal array [],int n){
	Personal aux;
	for (int i = 0; i<n-1; i++){
		for (int j =0 ;j<n-i-1; j++){
			if ( Comparar_fechas (array[j+1].f_nacimiento, array [j].f_nacimiento)){
				aux     = array [j];
			    array [j] = array [j+1];
			    array [j+1]= aux;
			}
		} 
	}
}

int Busqueda_binaria(Personal array[], int n, int dia, int mes, int anio) {
    int izq = 0, der = n - 1, m, pos;
    int centinela = 0;

    while (izq <= der && centinela == 0){
        m = (izq + der) / 2; 
        Fecha fecha_medio = array[m].f_nacimiento;

        if (fecha_medio.dia == dia && fecha_medio.mes == mes && fecha_medio.anio == anio){
            centinela = 1; 
        } else if (Comparar_fechas(fecha_medio, {dia, mes, anio})){
            izq = m + 1; 
        } else {
            der = m - 1; 
        }
    }

    if (centinela == 1){
        return pos = m; 
    } else {
        return pos = -izq; 
    }
}

int main (){

	int tam ;	
	cout << "Ingrese la cantidad del personal : ";
	cin  >> tam;
	Personal array [tam];	
	
	for(int i=0; i <tam ;i++){
		cout << "\n------------------------\n"<< endl;
		cout << "     DATOS PERSONALES   \n"<< endl;
		cout << "Persona ["<<i+1<<"] : "<<endl;
		cout << "DNI : ";
		cin  >> array [i].DNI;
		cout << "Nombre : ";
		cin.ignore();    // limpia el buffer 
		getline(cin,array [i].nombre);	
		cout << "\nFecha de nacimiento"<< endl;
		cout << "Dia : ";
		cin  >> array[i].f_nacimiento.dia;
		cout << "Mes : ";
		cin  >> array[i].f_nacimiento.mes;
		cout << "Año : ";
		cin  >> array[i].f_nacimiento.anio;
	}
	cout << "\n------------------------\n"<< endl;
	
	Ordenar_por_fechas (array,tam);
	
	int dia_buscar, mes_buscar, anio_buscar;
	cout << "\n Ingrese la fecha a buscar \n" << endl;
	cout << "Dia : ";
	cin  >> dia_buscar;
	cout << "Mes : ";
	cin  >> mes_buscar;
	cout << "Año : ";
	cin  >> anio_buscar;
	
	int resultado = Busqueda_binaria( array,tam,dia_buscar,mes_buscar,anio_buscar);
	
	if (resultado >= 0) {
		cout << "\n-----------------------------------" << endl;
        cout << "\nFecha encontrada en la posicion: " << resultado+1<< endl;
        cout << "\nDNI   : " << array[resultado].DNI    << endl;
		cout << "Nombre: " << array[resultado].nombre << endl;
    } else {
    	cout << "\n-----------------------------------" << endl;
        cout << "\nFecha no encontrada." << endl;
    }
	
	return 0;
}
