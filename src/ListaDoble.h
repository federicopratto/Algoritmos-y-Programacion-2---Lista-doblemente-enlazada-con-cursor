
#ifndef LISTADOBLE_H_
#define LISTADOBLE_H_

#include <string>
#include "Nodo.h"


template <class T>
class Lista {

private:


public:
	Nodo<T>* primero, *ultimo, *cursor;
	unsigned int tamanio;

	/*
	 * POST: Crea una nueva Lista vacia preparada para ser usada.
	 */
	Lista();


	/*
	 * POST: Devuelve si la lista no tiene elementos.
	 */
	bool estaVacia();


	/*
	 * POST: Devuelve la cantidad de elementos que contiene la lista.
	 */
	unsigned int contarElementos();


	/*
	 * POST: Agrega un nuevo elemento al final de la Lista.
	 */
	void agregarAlFinal(T elemento);


	/*
	 * PRE: posicion pertenece al intervalo [1, contarElementos() + 1]
	 * POST: Agrega un nuevo elemento en la posicion solicitada de la Lista.
	 */
	void agregar(unsigned int posicion, T elemento);


	/*
	 * PRE: posicion pertenece al intervalo [1, contarElementos()]
	 * POST: Reemplaza el elemento en la posicion solicitada de la Lista por nuevoElemento.
	 */
	void reemplazarElemento(unsigned int posicion, T nuevoElemento);


	/*
	 * PRE: posicion pertenece al intervalo [1, contarElementos()]
	 * POST: Devuelve el elemento en la posicion solicitada de la Lista.
	 */
	T obtener(unsigned int posicion);


	/*
	 * PRE: posicion pertenece al intervalo [1, contarElementos()]
	 * POST: Remueve el elemento en la posicion solicitada de la Lista.
	 */
	void remover(unsigned int posicion);


	/*
	 * POST: Deja el cursor de la Lista preparado para hacer un nuevo recorrido
	 * 		 sobre sus elementos.
	 */
	void iniciarCursor();


	/*
	 * PRE:	 Se ha iniciado un recorrido (invocando el método iniciarCursor())
	 * 		 y desde entonces no se han agregado o removido elementos de la Lista.
	 * POST: Mueve el cursor y lo posiciona en el siguiente elemento del recorrido.
	 *       El valor de retorno indica si el cursor quedó posicionado
	 *       sobre un elemento o no (en caso de que la Lista esté vacía o
	 *       no existan más elementos por recorrer.)
	 */
	bool avanzarCursor();


	/*
	 * PRE:	 Se ha iniciado un recorrido (invocando el método iniciarCursor())
	 * 		 y desde entonces no se han agregado o removido elementos de la Lista.
	 * POST: Mueve el cursor y lo posiciona en el elemento anterior del recorrido.
	 *       El valor de retorno indica si el cursor quedó posicionado
	 *       sobre un elemento o no (en caso de que la Lista esté vacía o
	 *       no existan más elementos por recorrer.)
	 */
	bool retrocederCursor();



	/*
	 * PRE:  El cursor está posicionado sobre un elemento de la Lista,
	 *       (fue invocado el método avanzarCursor() y devolvió true)
	 * POST: Devuelve el elemento en la posicion del cursor.
	 */
	T obtenerCursor();


	/*
	 * POST: Libera los recursos solicitados.
	 */
	~Lista();


private:

	/*
	 * PRE:  Posicion pertenece al intervalo [1, contarElementos()]
	 * POST: Devuelve el Nodo en la posicion indicada.
	 *
	 */
	Nodo<T>* obtenerNodo(unsigned int posicion);

};


template <class T>
Lista<T>::Lista() {

	this->primero = NULL;
	this->ultimo = NULL;
	this->cursor = NULL;
	this->tamanio = 0;
}


template <class T>
bool Lista<T>::estaVacia(){

	return (this->tamanio == 0);
}


template <class T>
unsigned int Lista<T>::contarElementos(){

	return this->tamanio;
}


template <class T>
void Lista<T>::agregarAlFinal(T elemento){

	this->agregar(this->contarElementos() + 1, elemento);
}


template <class T>
void Lista<T>::agregar(unsigned int posicion, T elemento){

	if(posicion < 1 || posicion > this->contarElementos() + 1){

		throw std::string("No se puede colocar un elemento en la posicion pedida de la Lista.");
	}

	Nodo<T>* nuevo = new Nodo<T>(elemento);

	if(posicion == 1){

		nuevo->cambiarSiguiente(this->primero);

		if(this->ultimo != NULL){

			this->primero->cambiarAnterior(nuevo);

		} else {

			this->ultimo = nuevo;
		}

		this->primero = nuevo;

	} else {

		Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
		Nodo<T>* siguiente = anterior->obtenerSiguiente();

		nuevo->cambiarAnterior(anterior);
		anterior->cambiarSiguiente(nuevo);
		nuevo->cambiarSiguiente(siguiente);

		if (posicion < this->contarElementos() + 1) {

			siguiente->cambiarAnterior(nuevo);

		} else {

			this->ultimo = nuevo;
		}
	}

	this->tamanio++;
	this->iniciarCursor();
}


template <class T>
void Lista<T>::reemplazarElemento(unsigned int posicion, T nuevoElemento){

	if(posicion < 1 || posicion > this->contarElementos()){

		throw std::string("No se puede reemplazar el elemento en la posicion pedida de la Lista.");
	}

	this->obtenerNodo(posicion)->cambiarDato(nuevoElemento);
}


template <class T>
T Lista<T>::obtener(unsigned int posicion){

	if(posicion < 1 || posicion > this->contarElementos()){

		throw std::string("No se puede obtener el elemento en la posicion pedida de la Lista.");
	}

	return (this->obtenerNodo(posicion)->obtenerDato());
}


template <class T>
void Lista<T>::remover(unsigned int posicion){

	if(posicion < 1 || posicion > this->contarElementos()){

		throw std::string("No se puede remover el elemento en la posicion pedida de la Lista.");
	}

	Nodo<T>* removido;

	if(posicion == 1){

		removido = this->primero;
		this->primero = removido->obtenerSiguiente();

		if(this->primero != NULL){

			this->primero->cambiarAnterior(NULL);

		} else {

			this->ultimo = NULL;
		}


	} else {

		removido = this->obtenerNodo(posicion);

		Nodo<T>* anterior = removido->obtenerAnterior();
		Nodo<T>* siguiente = removido->obtenerSiguiente();

		anterior->cambiarSiguiente(siguiente);

		if(posicion < this->contarElementos()){

			siguiente->cambiarAnterior(anterior);

		} else {

			this->ultimo = anterior;

		}
	}

	delete removido;
	this->tamanio--;
	this->iniciarCursor();
}


template <class T>
void Lista<T>::iniciarCursor(){

	this->cursor = NULL;
}


template <class T>
bool Lista<T>::avanzarCursor(){

	if(this->cursor == NULL){

		this->cursor = this->primero;

	} else {

		this->cursor = this->cursor->obtenerSiguiente();

	}

	return (this->cursor != NULL);
}


template <class T>
bool Lista<T>::retrocederCursor(){

	if(this->cursor == NULL){

		this->cursor = this->ultimo;

	} else {

		this->cursor = this->cursor->obtenerAnterior();
	}

	return (this->cursor != NULL);
}


template <class T>
T Lista<T>::obtenerCursor(){

	if(this->cursor == NULL){

		throw std::string("No se pudo obtener el cursor, ya que el mismo no esta sobre ningun elemento.");

	}

	return (this->cursor->obtenerDato());
}


template <class T>
Lista<T>::~Lista(){

	while(!this->estaVacia()){

		this->remover(1);
	}
}


template <class T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion){

	if(posicion < 1 || posicion > this->contarElementos()){

		throw std::string("No se puede obtener el Nodo en la posicion pedida de la Lista.");
	}

	Nodo<T>* actual;

	if(posicion <= (this->contarElementos() / 2)){

		actual = this->primero;
		for(unsigned int i = 1; i < posicion; i++){

			actual = actual->obtenerSiguiente();
		}

	} else {

		actual = this->ultimo;
		for(unsigned int i = this->contarElementos(); i > posicion; i--){

			actual = actual->obtenerAnterior();
		}

	}

	return actual;
}

#endif /* LISTADOBLE_H_ */
