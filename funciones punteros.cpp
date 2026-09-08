#include <iostream> 
using namespace std;

// 1) PASO POR VALOR (No modifica el original)

void incrementarPorValor(int x){
    x = x + 1; //solo cambia la copia local "x"
}

// 2) PASO POR REFERENCIA CON PUNTERO (Si modifica el original)

void incrementarPorPuntero(int *x){
    *x = *x + 1; //*x accede al valor real apuntado por la x
}

// 3) swap() clásico  con punteros

void swap(int *a, int *b){
    int temporal = *a; // guardamos el valor de "a" antes de pedir
    *a = *b;           // el valor de "b" pasa a la casilla de a
    *b = temporal;     // el valor original de a pasa a la casilla de b
}

// 4) Funcion que modifica un arreglo usando un puntero 

void duplicarValores (int *arreglo, int tamaño){
    for (int i = 0; i < tamaño; i++){
        arreglo [i] = arreglo [i] * 2; 
    }
}

// 5) Función que retorna un puntero (caso válido)

int* mayor(int *a, int *b){
    if (*a > *b){
        return a;
    }
    return b;
}

//----------------------------------------
// FUNCIÓN PRINCIPAL
//----------------------------------------
int main(){

    //--- Demostración 1: paso por valor vs. por puntero---
    int edad = 20;

    incrementarPorValor(edad);
    cout << "Despues de incrementarPorValor: " << edad << endl;

    incrementarPorPuntero(&edad);
    cout << "Despues de incrementarPorPuntero: " << edad << endl;
    
    cout << "----------------------------" << endl;


 // --- Demostración 2: swap() ---
    int x = 5, y = 9;
    cout << "Antes de swap -> x: " << x << ", y: " << y << endl;

    swap(&x,&y);
    cout << "Despues de swap -> x: " << x << ", y: " << y << endl;

    cout << "----------------------------" << endl;

    // --- Demostración 3: modificar un arreglo con punteros ---
    int numeros[5] = {1, 2, 3, 4, 5};

    cout <<"Arreglo original: ";
    for (int i = 0; i < 5; i++) cout << numeros[i] << " ";
    cout << endl;

    duplicarValores(numeros, 5); // el arreglo se pasa como puntero automáticamente

    cout << "Arreglo duplicado: ";
    for (int i = 0; i < 5; i++) cout << numeros[i] << " ";
    cout << endl;

    cout << "------------------------" << endl;

    // --- Demostración 4: Función que retorna un puntero ---
    int *p = mayor(&x, &y);
    cout << "El mayor entre x e y es: " << *p << endl;

    return 0;
}