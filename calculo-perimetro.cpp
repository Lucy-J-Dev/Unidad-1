#include <iostream>
#include <limits> // Para numeric_limits
using namespace std;

// Función para leer un número válido (entero o decimal, positivo)
double leerNumero(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) { // Si la entrada no es un número
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta lo que haya en el buffer
            cout << "❌ Entrada invalida. Por favor ingrese un numero (entero o decimal)." << endl;
        } 
        else if (valor <= 0) { // Validar que no sea negativo ni cero
            cout << "❌ El valor debe ser mayor que 0. Intente nuevamente." << endl;
        }
        else {
            return valor; // Número válido
        }
    }
}

// Función para leer la opción del usuario (s/S/n/N)
char leerOpcion(const string& mensaje) {
    char opcion;
    while (true) {
        cout << mensaje;
        cin >> opcion;

        if (opcion == 's' || opcion == 'S' || opcion == 'n' || opcion == 'N') {
            return opcion;
        } else {
            cout << "❌ Opcion invalida. Ingrese 's' para continuar o 'n' para salir." << endl;
        }
    }
}

int main() {
    double largo, ancho, perimetro;
    char opcion;

    do {
        // Pedir dimensiones del rectángulo
        largo = leerNumero("Ingrese el largo del rectangulo: ");
        ancho = leerNumero("Ingrese el ancho del rectangulo: ");

        // Calcular el perímetro
        perimetro = 2 * (largo + ancho);

        // Mostrar el resultado
        cout << "✅ El perimetro del rectangulo es: " << perimetro << endl;

        // Preguntar si desea continuar (valida solo s/S/n/N)
        opcion = leerOpcion("¿Desea calcular el perimetro de otro rectangulo? (s/n): ");

    } while (opcion == 's' || opcion == 'S');

    cout << "👋 Programa finalizado. ¡Gracias por usarlo!" << endl;
    return 0;
}
