#include <iostream>
using namespace std;

int main() {

    int numero = 25;
    int *años; 
    años = &numero;

    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << "Contenido de años: " << *años << endl;
    
    *años= 100;
    cout << "Nuevo valor de años: " << numero << endl;
    cout << "Direccion de años: " << &años << endl;
    return 0;
}