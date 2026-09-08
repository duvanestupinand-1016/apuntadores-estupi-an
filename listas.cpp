#include <iostream>
using namespace std;
const int CAPACIDAD_MAXIMA = 10;

class ListaArreglo {
private:
    int datos[CAPACIDAD_MAXIMA];
    int tamano; // cantidad de elementos actualmente almacenados

public:
    ListaArreglo() {
        tamano = 0;
    }

    bool estaVacia() {
        return tamano == 0;
    }

    bool estaLlena() {
        return tamano == CAPACIDAD_MAXIMA;
    }

    // inserta valor en la posicion 'posicion' (0-indexada)
    // caso limite 1: lista llena -> no se debe insertar
    // caso limite 2: posicion invalida (posicion < 0 o posicion > tamano).

    bool insertar(int valor, int posicion) {
        if (estaLlena()) {
            cout << "error: la lista esta llena no se puede insertar." << endl;
            return false;
        }

        if (posicion < 0 || posicion > tamano) {
            cout << "error: posicion invalida (" << posicion << ")." << endl;
            return false;
        }

        // desplazar elementos hacia la derecha para abrir espacio
        for (int i = tamano; i > posicion; i--) {
            datos[i] = datos[i - 1];
        }

        datos[posicion] = valor;
        tamano++;
        return true;
    }

    // elimina el elemento en 'posicion'
    // caso limite 1: lista vacia -> no se puede eliminar
    // caso limite 2: posicion invalida (posicion < 0 o posicion >= tamano) -> no

    bool eliminar(int posicion) {
        if (estaVacia()) {
            cout << "error: la lista esta vacia, no se puede eliminar." << endl;
            return false;
        }

        if (posicion < 0 || posicion >= tamano) {
            cout << "error: posicion invalida(" << posicion << ")." << endl;
            return false;
        }

        // desplazar elementos hacia la izquierda para cerrar el espacio
        for (int i = posicion; i < tamano - 1; i++) {
            datos[i] = datos[i + 1];
        }

        tamano--;
        return true;
    }

    // busca 'valor' y retorna su posicion, o -1 si no existe
    int buscar(int valor) {
        for (int i = 0; i < tamano; i++) {
            if (datos[i] == valor) {
                return i;
            }
        }
        return -1;
    }

    // recorre e imprime todos los elementos de la lista
    void recorrer() {
        if (estaVacia()) {
            cout << "[ lista vacia ]" << endl;
            return;
        }

        cout << "[ ";
        for (int i = 0; i < tamano; i++) {
            cout << datos[i];
            if (i < tamano - 1) cout << ", ";
        }
        cout << " ] " << endl;
    }
};

int main() {
    ListaArreglo lista;

    cout << " --- insertando elementos --- " << endl;
    lista.insertar(10, 0);
    lista.insertar(20, 1);
    lista.insertar(15, 1); // queda: 10, 15, 20
    lista.recorrer();

    cout << " \n --- buscando el valor 15  --- " << endl;
    int pos = lista.buscar(15);
    cout << (pos != -1 ? " encontrado en la posicion " + to_string(pos)
                        : "no encontrado") << endl;

    cout << " \n --- eliminando la posicion 0 --- " << endl;
    lista.eliminar(0);
    lista.recorrer();

    cout << "\n ---casos limite (taller practico con IA ) ===" << endl;

    cout << "\n ---caso 1: lista vacia ( eliminar ) ---" << endl;
    ListaArreglo listavacia;
    listavacia.eliminar(0); // debe reportar error, no debe fallar

    cout << "\n ---casos 2: lista llena  (insertar ) ---" << endl;
    ListaArreglo listallena;

    for (int i = 0; i < CAPACIDAD_MAXIMA; i++) {
        listallena.insertar(i, i);
    }

    listallena.recorrer();
    listallena.insertar(99, 0); // debe reportar error; lista llena

    cout << "\n ---caso 3:  posicion invalida (insertar y eliminar ---" << endl;
    ListaArreglo listapruebas;
    listapruebas.insertar(1, 0);
    listapruebas.insertar(2, 1);
    listapruebas.insertar(50, -1);
    listapruebas.insertar(50, 10);
    listapruebas.eliminar(-1);
    listapruebas.eliminar(10);
    listapruebas.recorrer();

    return 0;
}