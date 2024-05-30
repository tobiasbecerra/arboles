#pragma once
#include <iostream>
using namespace std;

//CLASE NODO

template <typename T>
class Nodo {
public:
	T dato;
	Nodo* siguiente;
	Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

//CLASE LISTA

template <typename T>
class Lista {
public:
    Nodo<T>* cabeza;
	Lista() :cabeza(nullptr) {};

	//FUNCION AGREGAR ELEMENTOS A LA LISTA
	void agregarElementos() {
		int cantidadElementos;
		cout << "\n\tIngrese la cantidad de elementos que utilizará (enteros): ";
		cin >> cantidadElementos;

		for (int i = 0; i < cantidadElementos; i++) {
			T nuevoDato;
			cout << "\tIngrese el dato " << i + 1 << ": ";
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

	//FUNCION IMPRIMIR LISTA
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

			cout << "\tLa lista ingresada [";
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
				cout << "\t¿Desea ingresar otra lista? (s/n): ";
				cin >> respuesta2;
				if (respuesta2 == 'S' || respuesta2 == 's') {
					continue;
				}
				else {
					cout << "\tGracias por usar Generador de Arboles BLAS PASCAL";
					exit(0);
				}
			}
		} while (!listaCorrecta);
	}
};

template <typename T>
class ArbolBinarioBusqueda {
private:
	struct NodoABB {
		T dato;
		NodoABB* izquierda;
		NodoABB* derecha;
		NodoABB(T dato) : dato(dato), izquierda(nullptr), derecha(nullptr) {}
	};

	NodoABB* raiz;

	// Función auxiliar para insertar un elemento en el árbol
	NodoABB* insertarRecursivo(NodoABB* nodo, T dato) {
		if (nodo == nullptr) {
			nodo = new NodoABB(dato);
		}
		else if (dato < nodo->dato) {
			nodo->izquierda = insertarRecursivo(nodo->izquierda, dato);
		}
		else if (dato > nodo->dato) {
			nodo->derecha = insertarRecursivo(nodo->derecha, dato);
		}
		return nodo;
	}

public:
	ArbolBinarioBusqueda() : raiz(nullptr) {}

	// Función para construir el árbol a partir de la lista
	void construirArbolDesdeLista(Lista<T>& lista) {
		Nodo<T>* temp = lista.cabeza;
		while (temp != nullptr) {
			insertar(temp->dato);
			temp = temp->siguiente;
		}
	}

	// Función para insertar un elemento en el árbol
	void insertar(T dato) {
		raiz = insertarRecursivo(raiz, dato);
	}

	// Función para imprimir el árbol de manera gráfica
	void imprimirGrafico() {
		imprimirGraficoRecursivo(raiz, 0);
	}

private:
	// Función recursiva para imprimir el árbol de manera gráfica
	void imprimirGraficoRecursivo(NodoABB* nodo, int nivel) {
		if (nodo != nullptr) {
			imprimirGraficoRecursivo(nodo->derecha, nivel + 1);
			std::cout << std::string(4 * nivel, ' ') << nodo->dato << std::endl;
			imprimirGraficoRecursivo(nodo->izquierda, nivel + 1);
		}
	}
};