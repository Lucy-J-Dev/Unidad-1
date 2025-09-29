#include <iostream>
using namespace std;

int main() {
    // Variables para almacenar las dimensiones del rectángulo
    double largo, ancho, perimetro;

    // Pedir al usuario el largo y el ancho
    cout << "Ingrese el largo del rectangulo: ";
    cin >> largo;

    cout << "Ingrese el ancho del rectangulo: ";
    cin >> ancho;

    // Calcular el perimetro
    perimetro = 2 * (largo + ancho);

    // Mostrar el resultado
    cout << "El perimetro del rectangulo es: " << perimetro << endl;

    return 0;
}
