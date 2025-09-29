#include <iostream>
using namespace std;

int main() {
    double largo, ancho, perimetro;
    char opcion;

    do {
        // Pedir al usuario las dimensiones
        cout << "Ingrese el largo del rectangulo: ";
        cin >> largo;

        cout << "Ingrese el ancho del rectangulo: ";
        cin >> ancho;

        // Calcular el perímetro
        perimetro = 2 * (largo + ancho);

        // Mostrar el resultado
        cout << "El perimetro del rectangulo es: " << perimetro << endl;

        // Preguntar si desea continuar
        cout << "¿Desea calcular el perimetro de otro rectangulo? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    cout << "Programa finalizado. ¡Gracias por usarlo!" << endl;

    return 0;
}
