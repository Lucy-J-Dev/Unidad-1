#include <iostream>
#include <iomanip>  // Para formatear la tabla
#include <limits>
#include <vector>
using namespace std;

// Estructura para guardar cada cálculo
struct Calculo {
    int numero;
    double largo;
    double ancho;
    double perimetro;
};

// Función para leer un número válido (positivo)
double leerNumero(const string& mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Entrada invalida. Por favor ingrese un numero valido." << endl;
        } 
        else if (valor <= 0) {
            cout << "❌ El valor debe ser mayor que 0. Intente nuevamente." << endl;
        } 
        else {
            return valor;
        }
    }
}

// Función para leer opción de salida (s/S/n/N)
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
    string nombre;
    double largo, ancho, perimetro;
    char opcion;
    vector<Calculo> historial;
    int contador = 1;

    // Mensaje de bienvenida
    cout << "==============================================" << endl;
    cout << "   👋 Bienvenido al programa Calculadora de Perimetros" << endl;
    cout << "==============================================" << endl;
    cout << "Este programa calcula el perimetro de un rectangulo." << endl;
    cout << "La formula usada es: P = 2 * (largo + ancho)" << endl;
    cout << "----------------------------------------------" << endl;

    // Capturar nombre del usuario
    cout << "Por favor ingrese su nombre: ";
    getline(cin, nombre);

    cout << "¡Hola, " << nombre << "! 😊 Vamos a comenzar..." << endl;

    do {
        cout << "----------------------------------------------" << endl;
        cout << "🔢 Calculo #" << contador << endl;
        cout << "----------------------------------------------" << endl;

        // Leer dimensiones
        largo = leerNumero("Ingrese el largo del rectangulo: ");
        ancho = leerNumero("Ingrese el ancho del rectangulo: ");

        // Calcular perímetro
        perimetro = 2 * (largo + ancho);

        // Mostrar resultado
        cout << "✅ " << nombre << ", el perimetro del rectangulo es: " << perimetro << "\n" << endl;

        // Guardar en historial
        historial.push_back({contador, largo, ancho, perimetro});
        contador++;

        // Preguntar si desea continuar
        opcion = leerOpcion("¿Desea calcular el perimetro de otro rectangulo? (s/n): ");
        cout << "\n";

    } while (opcion == 's' || opcion == 'S');

    // Mostrar informe final
    cout << "==============================================" << endl;
    cout << "📊 Informe de Calculos Realizados por " << nombre << endl;
    cout << "==============================================" << endl;

    if (historial.empty()) {
        cout << "No se realizaron calculos." << endl;
    } else {
        cout << left << setw(10) << "N°"
             << setw(15) << "Largo"
             << setw(15) << "Ancho"
             << setw(20) << "Perimetro" << endl;
        cout << string(60, '-') << endl;

        for (const auto& calc : historial) {
            cout << left << setw(10) << calc.numero
                 << setw(15) << calc.largo
                 << setw(15) << calc.ancho
                 << setw(20) << calc.perimetro << endl;
        }
    }

    cout << "\n👋 Gracias por usar el programa, " << nombre << ". ¡Hasta pronto!" << endl;
    return 0;
}
