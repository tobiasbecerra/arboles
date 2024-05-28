#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Nodo {
public:
	T dato;
	Nodo* siguiente;
	Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class Lista {
private:
	Nodo<T>* cabeza;
public:
	Lista() :cabeza(nullptr) {};

	void agregarElementos() {
		int cantidadElementos;
		cout << "\nIngrese la cantidad de elementos que utilizará (enteros): ";
		cin >> cantidadElementos;

		for (int i = 0; i < cantidadElementos; i++) {
			T nuevoDato;
			cout << "Ingrese el dato " << i + 1 << ": ";
			cin >> nuevoDato;

			Nodo<T>* nuevoNodo = new Nodo<T>(nuevoDato);
			if (cabeza == nullptr) {
				cabeza = nuevoNodo;
			}
			else {
				Nodo<T>* temp = cabeza;
				while (temp->siguiente != nullptr) {
					temp = temp->siguiente;
				}
				temp->siguiente = nuevoNodo;
			}
		}
	}

	void imprimirLista() {
		char respuesta;
		bool listaCorrecta = false;
		do {
			Nodo<T>* temp = cabeza;
			while (temp != nullptr) {
				Nodo<T>* siguiente = temp->siguiente;
				delete temp;
				temp = siguiente;
			}

			cabeza = nullptr;
			agregarElementos();
			temp = cabeza;

			cout << "La lista ingresada [";
			while (temp != nullptr) {
				cout << temp->dato << " -> ";
				temp = temp->siguiente;
			}
			cout << "], ¿es correcta? (s/n): ";
			cin >> respuesta;

			if (respuesta == 'S' || respuesta == 's') {
				listaCorrecta = true;
			}
			else {
				char respuesta2;
				cout << "¿Desea ingresar otra lista? (s/n): ";
				cin >> respuesta2;
				if (respuesta2 == 'S' || respuesta2 == 's') {
					continue;
				}
				else {
					cout << "Gracias por usar Generador de Arboles BLAS PASCAL";
					exit(0);
				}
			}
		} while (!listaCorrecta);
	}
};