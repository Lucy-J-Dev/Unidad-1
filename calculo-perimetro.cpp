#include <iostream>
#include <limits> // Para numeric_limits
using namespace std;

// Función para leer un número válido (entero o decimal)
double leerNumero(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) { // Si la entrada no es un número
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada inválida
            cout << "Entrada invalida. Por favor ingrese un numero (entero o decimal)." << endl;
        } else {
            return valor; // Devuelve el número válido
        }
    }
}

int main() {
    double largo, ancho, perimetro;
    char opcion;

    do {
        // Pedir al usuario las dimensiones con validación
        largo = leerNumero("Ingrese el largo del rectangulo: ");
        ancho = leerNumero("Ingrese el ancho del rectangulo: ");

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
