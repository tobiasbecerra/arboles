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
	cout << "\tBIENVENIDO AL GENERADOR DE ARBOLES BLAS PASCAL" << endl;
	lista.imprimirLista();

	while (opc != 5) {

		system("cls");

		cout << "\n\t1. Generar �rbol binario." << endl;
		cout << "\n\t2. Generar �rbol binario de b�squeda." << endl;
		cout << "\n\t3. Generar AVL." << endl;
		cout << "\n\t4. Generar �rbol rojo y negro." << endl;
		cout << "\n\t5. Salir del generador." << endl;
		cout << "\nIngrese opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			system("cls");
			ab.construirArbolDesdeLista(lista);
			cout << "\nRepresentaci�n gr�fica del �rbol binario:\n";
			ab.imprimirGrafico();

			cin.ignore();
			cin.get();
			break;
		case 2:
			system("cls");
			abb.construirArbolDesdeLista(lista);
			cout << "\nRepresentaci�n gr�fica del �rbol binario de b�squeda:\n";
			abb.imprimirGrafico();
			cin.ignore();
			cin.get();
			break;
		case 3:
			system("cls");
			avl.construirArbolDesdeLista(lista);
			cout << "\nRepresentaci�n gr�fica del �rbol AVL:\n";
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
			cout << "\nRepresentaci�n gr�fica del �rbol rojo y negro:\n";
			arn.imprimir();
			
			cin.ignore();
			cin.get();
			break;
		}
	}

	return 0;
}