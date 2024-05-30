#include <iostream>
#include "trees.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Lista<int> lista;
	ArbolBinarioBusqueda<int> abb;
	int opc = 0;
	cout << "\tBIENVENIDO AL GENERADOR DE ARBOLES BLAS PASCAL" << endl;
	lista.imprimirLista();

	while (opc != 5) {	

		cout << "\n\t1. Generar árbol binario."  << endl;
		cout << "\n\t2. Generar árbol binario de búsqueda." << endl;
		cout << "\n\t3. Generar AVL." << endl;
		cout << "\n\t4. Generar árbol rojo y negro." << endl;
		cout << "\n\t5. Salir del generador." << endl;
		cout << "\nIngrese opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			break;
		case 2:
			abb.construirArbolDesdeLista(lista);
			abb.imprimirGrafico();
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}

	return 0;
}