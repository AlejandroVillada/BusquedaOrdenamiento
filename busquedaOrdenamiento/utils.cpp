#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

// Prepara la estructura de datos. Para elementos unicos genera saltos aleatorios y los mezcla; de lo contrario, inyecta numeros al azar.
void generarArreglo(int*& arreglo, int n, bool unicos)
{
    if (arreglo != nullptr) {
        delete[] arreglo;
    }

    arreglo = new int[n];
    srand((unsigned int)time(NULL)); // Inicializar semilla general

    if (unicos) {
        vector<int> bolsa(n);
        int acumulador = 1;

        // Llenar con saltos aleatorios para separar los valores
        for (int i = 0; i < n; i++) {
            acumulador += (rand() % 25) + 1; // Saltos aleatorios entre 1 y 25
            bolsa[i] = acumulador;
        }

        // Revolver la bolsa
        unsigned int seed = (unsigned int)system_clock::now().time_since_epoch().count();
        shuffle(bolsa.begin(), bolsa.end(), default_random_engine(seed));

        for (int i = 0; i < n; i++) arreglo[i] = bolsa[i];
    }
    else {
        // Numeros repetidos con un rango mucho mayor (0 a 9999) para que esten separados
        for (int i = 0; i < n; i++) {
            arreglo[i] = rand() % 10000;
        }
    }
}

// Ejecuta el algoritmo solicitado tomando una marca de tiempo exacta antes y despues de la operacion para calcular su rendimiento.
void medirTiempo(void (*func)(int*, int, bool), int* arreglo, int n, string nombreAlgoritmo) {
    int* copia = new int[n];
    for (int i = 0; i < n; i++) copia[i] = arreglo[i];

    auto inicio = high_resolution_clock::now();
    func(copia, n, false);
    auto fin = high_resolution_clock::now();

    // Cambiado a nanoseconds
    auto duracion = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo " << nombreAlgoritmo << ": " << duracion.count() << " nanosegundos." << endl;

    delete[] copia;
}

// Version adaptada del medidor de tiempo especificamente para QuickSort por sus parametros extra.
void medirTiempoRec(void (*func)(int*, int, int, int&, int&, bool), int* arreglo, int n, string nombreAlgoritmo) {
    int* copia = new int[n];
    for (int i = 0; i < n; i++) copia[i] = arreglo[i];
    int comp = 0, inter = 0;

    auto inicio = high_resolution_clock::now();
    func(copia, 0, n - 1, comp, inter, false);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo " << nombreAlgoritmo << ": " << duracion.count() << " nanosegundos." << endl;
    delete[] copia;
}

// Version adaptada del medidor de tiempo especificamente para MergeSort.
void medirTiempoMerge(void (*func)(int*, int, int, int&, bool), int* arreglo, int n, string nombreAlgoritmo) {
    int* copia = new int[n];
    for (int i = 0; i < n; i++) copia[i] = arreglo[i];
    int comp = 0;

    auto inicio = high_resolution_clock::now();
    func(copia, 0, n - 1, comp, false);
    auto fin = high_resolution_clock::now();

    auto duracion = duration_cast<nanoseconds>(fin - inicio);
    cout << "Tiempo " << nombreAlgoritmo << ": " << duracion.count() << " nanosegundos." << endl;
    delete[] copia;
}

// Toma el arreglo actual y reordena sus elementos de forma aleatoria destruyendo cualquier orden previo.
void desordenarArreglo(int* arreglo, int n) {
    unsigned int seed = (unsigned int)system_clock::now().time_since_epoch().count();
    shuffle(arreglo, arreglo + n, default_random_engine(seed));
}