#include <iostream>
#include "trees.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	Lista<int> lista;
	ArbolBinarioBusqueda<int> abb;
	ArbolBinario<int> ab;
	ArbolAVL<int> avl;
	ArbolRN<int> arn;
	int opc = 0;
	cout << "\n\tBIENVENIDO AL GENERADOR DE ARBOLES BLAS PASCAL" << endl;
	lista.imprimirLista();

	while (opc != 5) {

		system("cls");

		cout << "\n\t1. Generar árbol binario." << endl;
		cout << "\n\t2. Generar árbol binario de búsqueda." << endl;
		cout << "\n\t3. Generar AVL." << endl;
		cout << "\n\t4. Generar árbol rojo y negro." << endl;
		cout << "\n\t5. Salir del generador." << endl;
		cout << "\n\tIngrese opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			system("cls");
			ab.construirArbolDesdeLista(lista);
			cout << "\nRepresentación gráfica del árbol binario:\n";
			ab.imprimirGrafico();

			cout << "Recorrido Pre-Order: ";
			ab.preorden(ab.raiz);
			cout << "\nRecorrido In-Order: ";
			ab.inorden(ab.raiz);
			cout << "\nRecorrido Post-Order: ";
			ab.postorden(ab.raiz);

			cin.ignore();
			cin.get();
			break;
		case 2:
			system("cls");
			abb.construirArbolDesdeLista(lista);
			cout << "\nRepresentación gráfica del árbol binario de búsqueda:\n";
			abb.imprimirGrafico();

			cout << "Recorrido Pre-Order: ";
			abb.preorden(abb.raiz);
			cout << "\nRecorrido In-Order: ";
			abb.inorden(abb.raiz);
			cout << "\nRecorrido Post-Order: ";
			abb.postorden(abb.raiz);

			cin.ignore();
			cin.get();
			break;
		case 3:
			system("cls");
			avl.construirArbolDesdeLista(lista);
			cout << "\nRepresentación gráfica del árbol AVL:\n";
			avl.imprimirGrafico();

			cout << "Recorrido Pre-Order: ";
			avl.preorden(avl.raiz);
			cout << "\nRecorrido In-Order: ";
			avl.inorden(avl.raiz);
			cout << "\nRecorrido Post-Order: ";
			avl.postorden(avl.raiz);
			cin.ignore();
			cin.get();
			break;
		case 4:
			system("cls");
			arn.construirArbolDesdeLista(lista);
			cout << "\nRepresentación gráfica del árbol rojo y negro:\n";
			arn.imprimir();
			
			cin.ignore();
			cin.get();
			break;
		}
	}

	return 0;
}