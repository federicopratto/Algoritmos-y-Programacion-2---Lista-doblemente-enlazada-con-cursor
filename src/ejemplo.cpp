
#include <iostream>
#include "Lista.h"

using namespace std;

int main() {

	Lista<float> notas;

	cout << "Ingrese las notas, separadas por espacios y 0 para terminar"<< endl;

	float nota;
	do {

		cin >> nota;
		notas.agregar(nota);

	} while (nota > 0);


	float promedio = 0;

	notas.iniciarCursor();
	while (notas.avanzarCursor()) {

		promedio += notas.obtenerCursor();
	}

	cout << "Promedio: " << promedio / notas.contarElementos() << endl;


	promedio = 0;

	notas.iniciarCursor();
	while (notas.retrocederCursor()) {

		promedio += notas.obtenerCursor();
	}

	cout << "Promedio: " << promedio / notas.contarElementos() << endl;

	return 0;
}