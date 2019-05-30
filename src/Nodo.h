
#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif


template <class T>
class Nodo {

private:

	T dato;
	Nodo<T>* siguiente, *anterior;

public:

	/*
	 * POST: Crea un nuevo nodo con un elemento en su interior.
	 */
	Nodo(T dato);


	/*
	 * POST: Devuelve el contenido almacenado en el Nodo.
	 */
	T obtenerDato();


	/*
	 * POST: Reemplaza el contenido del Nodo por el nuevo elemento ingresado.
	 */
	void cambiarDato(T nuevoDato);


	/*
	 * POST: Devuelve un puntero al Nodo siguiente
	 */
	Nodo<T>* obtenerSiguiente();


	/*
	 * POST: Reemplaza el siguiente al Nodo por nuevoSiguiente.
	 */
	void cambiarSiguiente(Nodo<T>* nuevoSiguiente);


	/*
	 * POST: Devuelve un puntero al Nodo anterior.
	 */
	Nodo<T>* obtenerAnterior();


	/*
	 * POST: Reemplaza el anterior al Nodo por nuevoAnterior.
	 */
	void cambiarAnterior(Nodo<T>* nuevoAnterior);


	/*
	 * POST: Libera los recursos solicitados.
	 */
	~Nodo();

};


template <class T>
Nodo<T>::Nodo(T dato) {

	this->dato = dato;
	this->siguiente = NULL;
	this->anterior = NULL;
}


template <class T>
T Nodo<T>::obtenerDato(){

	return this->dato;
}


template <class T>
void Nodo<T>::cambiarDato(T nuevoDato){

	this->dato = nuevoDato;
}


template <class T>
Nodo<T>* Nodo<T>::obtenerSiguiente(){

	return this->siguiente;
}


template <class T>
void Nodo<T>::cambiarSiguiente(Nodo<T>* nuevoSiguiente){

	this->siguiente = nuevoSiguiente;
}


template <class T>
Nodo<T>* Nodo<T>::obtenerAnterior(){

	return this->anterior;
}


template <class T>
void Nodo<T>::cambiarAnterior(Nodo<T>* nuevoAnterior){

	this->anterior = nuevoAnterior;
}


template <class T>
Nodo<T>::~Nodo(){

}

#endif /* NODO_H_ */
