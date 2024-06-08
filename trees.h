#pragma once
#include <iostream>
#include <queue>
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

	// Recorrido Preorden
	void preorden(Nodo<T>* nodo) {
		if (nodo != nullptr) {
			cout << nodo->dato << " ";
			preorden(nodo->siguiente);
		}
	}

	// Recorrido Inorden
	void inorden(Nodo<T>* nodo) {
		if (nodo != nullptr) {
			inorden(nodo->siguiente);
			cout << nodo->dato << " ";
		}
	}

	// Recorrido Postorden
	void postorden(Nodo<T>* nodo) {
		if (nodo != nullptr) {
			postorden(nodo->siguiente);
			cout << nodo->dato << " ";
		}
	}

	// Función para iniciar el recorrido preorden
	void recorrerPreorden() {
		cout << "\nRecorrido PRE-ORDER --> ";
		preorden(cabeza);
		cout << endl;
	}

	// Función para iniciar el recorrido inorden
	void recorrerInorden() {
		cout << "\nRecorrido IN-ORDER --> ";
		inorden(cabeza);
		cout << endl;
	}

	// Función para iniciar el recorrido postorden
	void recorrerPostorden() {
		cout << "\nRecorrido POST-ORDER --> ";
		postorden(cabeza);
		cout << endl;
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

template <typename T>
class ArbolAVL {
private:
	struct NodoAVL {
		T dato;
		NodoAVL* izquierda;
		NodoAVL* derecha;
		int altura;

		NodoAVL(T dato) : dato(dato), izquierda(nullptr), derecha(nullptr), altura(1) {}
	};

	NodoAVL* raiz;


	int obtenerAltura(NodoAVL* nodo) {
		if (nodo == nullptr)
			return 0;
		return nodo->altura;
	}



	int obtenerBalance(NodoAVL* nodo) {
		if (nodo == nullptr)
			return 0;

		return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
	}


	NodoAVL* rotacionDerecha(NodoAVL* y) {
		NodoAVL* x = y->izquierda;
		NodoAVL* T2 = x->derecha;

		x->derecha = y;
		y->izquierda = T2;

		y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
		x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;

		return x;
	}

	NodoAVL* rotacionIzquierda(NodoAVL* x) {
		NodoAVL* y = x->derecha;
		NodoAVL* T2 = y->izquierda;

		y->izquierda = x;
		x->derecha = T2;

		x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
		y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;

		return y;
	}


	NodoAVL* insertarRecursivo(NodoAVL* nodo, T dato) {
		if (nodo == nullptr) {
			return new NodoAVL(dato);
		}
		if (dato < nodo->dato) {
			nodo->izquierda = insertarRecursivo(nodo->izquierda, dato);
		}
		else if (dato > nodo->dato) {
			nodo->derecha = insertarRecursivo(nodo->derecha, dato);
		}
		else {
			return nodo;
		}

		nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));

		int balance = obtenerBalance(nodo);


		if (balance > 1 && dato < nodo->izquierda->dato) {
			return rotacionDerecha(nodo);
		}

		// Caso Rotación Derecha
		if (balance < -1 && dato > nodo->derecha->dato) {
			return rotacionIzquierda(nodo);
		}

		return nodo;
	}


	void imprimirGraficoRecursivo(NodoAVL* nodo, int nivel) {
		if (nodo != nullptr) {
			imprimirGraficoRecursivo(nodo->derecha, nivel + 1);
			std::cout << std::string(4 * nivel, ' ') << nodo->dato << std::endl;
			imprimirGraficoRecursivo(nodo->izquierda, nivel + 1);
		}
	}

public:
	ArbolAVL() : raiz(nullptr) {}


	void construirArbolDesdeLista(Lista<T>& lista) {
		Nodo<T>* temp = lista.cabeza;
		while (temp != nullptr) {
			insertar(temp->dato);
			temp = temp->siguiente;
		}
	}

	void insertar(T dato) {
		raiz = insertarRecursivo(raiz, dato);
	}


	void imprimirGrafico() {
		imprimirGraficoRecursivo(raiz, 0);
	}
};

// CLASE ARBOL BINARIO
template <typename T>
class ArbolBinario {
private:
	struct NodoAB {
		T dato;
		NodoAB* izquierda;
		NodoAB* derecha;
		NodoAB(T dato) : dato(dato), izquierda(nullptr), derecha(nullptr) {}
	};

	NodoAB* raiz;

	// Función auxiliar para insertar un elemento en el árbol de forma secuencial usando una cola
	NodoAB* insertar(NodoAB* nodo, T dato) {
		if (nodo == nullptr)
			return new NodoAB(dato);

		queue<NodoAB*> q;
		q.push(nodo);

		while (!q.empty()) {
			NodoAB* actual = q.front();
			q.pop();

			if (actual->izquierda == nullptr) {
				actual->izquierda = new NodoAB(dato);
				return nodo;
			}
			else {
				q.push(actual->izquierda);
			}

			if (actual->derecha == nullptr) {
				actual->derecha = new NodoAB(dato);
				return nodo;
			}
			else {
				q.push(actual->derecha);
			}
		}
		return nodo;
	}

public:
	ArbolBinario() : raiz(nullptr) {}

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
		raiz = insertar(raiz, dato);
	}

	// Función para imprimir el árbol de manera gráfica
	void imprimirGrafico() {
		imprimirGraficoRecursivo(raiz, 0);
	}

private:
	// Función recursiva para imprimir el árbol de manera gráfica
	void imprimirGraficoRecursivo(NodoAB* nodo, int nivel) {
		if (nodo != nullptr) {
			imprimirGraficoRecursivo(nodo->derecha, nivel + 1);
			cout << string(4 * nivel, ' ') << nodo->dato << endl;
			imprimirGraficoRecursivo(nodo->izquierda, nivel + 1);
		}
	}
};