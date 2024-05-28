#include <iostream>
#include "trees.h"
using namespace std;

int main() {	
	setlocale(LC_ALL, "");
	Lista<int> lista;
	ArbolBinarioBusqueda<int> abb;
	int opc = 0;
	cout << "BIENVENIDO AL GENERADOR DE ARBOLES BLAS PASCAL" << endl;
	lista.imprimirLista();

	while (opc != 5) {	

		cout << "\n1. Generar árbol binario."  << endl;
		cout << "\n2. Generar árbol binario de búsqueda." << endl;
		cout << "\n3. Generar AVL." << endl;
		cout << "\n4. Generar árbol rojo y negro." << endl;
		cout << "\n5. Salir del generador." << endl;
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