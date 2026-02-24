#include <iostream>
#include "search.h"
#include "sort.h"
#include "view.h"
#include "utils.h" // Incluimos nuestras nuevas utilidades

using namespace std;

// Controlador principal. Actua como puente entre la interfaz de usuario y los algoritmos, gestionando ademas el ciclo de vida y el estado de la memoria del arreglo.
int main()
{
    int opcion;
    int metodo;
    int* arreglo = nullptr;
    int n = 0;
    int posicion, valor;
    int comparaciones = 0, intercambios = 0;
    bool mostrarPasos = false;

    // Nueva variable para controlar la aparicion de la Opcion 7
    bool estaOrdenado = false;

    n = pedirTamanio();
    bool repetir = pedirSiRepetir();
    generarArreglo(arreglo, n, !repetir);
    cout << "\nArreglo generado correctamente.\n";

    if (n <= 50) {
        mostrarArreglo(arreglo, n);
    }
    else {
        cout << "(El arreglo es mayor a 50 elementos, se oculta para no saturar la pantalla)\n";
    }

    do
    {
        // Pasamos la variable para que el menu sepa si mostrar la opcion 7 o no
        mostrarMenu(estaOrdenado);
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (n <= 50) mostrarArreglo(arreglo, n);
            valor = pedirValor();
            posicion = busquedaSecuencial(arreglo, n, valor);
            if (posicion != -1) cout << "Valor encontrado en pos: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;

        case 2:
            cout << "\nPara binaria, primero ordenamos (QuickSort silencioso)...\n";
            quickSort(arreglo, 0, n - 1, comparaciones, intercambios, false);
            estaOrdenado = true; // La busqueda binaria lo ordena!
            valor = pedirValor();
            posicion = busquedaBinaria(arreglo, n, valor);
            if (posicion != -1) cout << "Valor encontrado en pos: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;

        case 3:
            metodo = mostrarMenuOrdenamiento();
            mostrarPasos = pedirMostrarProceso();
            comparaciones = 0; intercambios = 0;

            if (metodo == 1) ordenarBurbuja(arreglo, n, mostrarPasos);
            else if (metodo == 2) ordenarSeleccion(arreglo, n, mostrarPasos);
            else if (metodo == 3) ordenarInsercion(arreglo, n, mostrarPasos);
            else if (metodo == 4) quickSort(arreglo, 0, n - 1, comparaciones, intercambios, mostrarPasos);
            else if (metodo == 5) mergeSort(arreglo, 0, n - 1, comparaciones, mostrarPasos);

            estaOrdenado = true; // Marcamos que el arreglo ya se ordeno

            if (n <= 50) {
                cout << "\nArreglo ordenado:\n";
                mostrarArreglo(arreglo, n);
            }
            else {
                cout << "\nArreglo ordenado (Oculto por tamanio grande).\n";
            }
            break;

        case 4:
            cout << "Saliendo...\n";
            break;

        case 5:
            n = pedirTamanio();
            repetir = pedirSiRepetir();
            generarArreglo(arreglo, n, !repetir);
            estaOrdenado = false; // Al regenerarlo, nace desordenado
            cout << "\nNuevo arreglo generado.\n";
            if (n <= 50) mostrarArreglo(arreglo, n);
            break;

        case 6:
            cout << "\n=== TIEMPOS DE EJECUCION (N=" << n << ") ===\n";
            medirTiempo(ordenarBurbuja, arreglo, n, "Burbuja");
            medirTiempo(ordenarSeleccion, arreglo, n, "Seleccion");
            medirTiempo(ordenarInsercion, arreglo, n, "Insercion");
            medirTiempoRec(quickSort, arreglo, n, "QuickSort");
            medirTiempoMerge(mergeSort, arreglo, n, "MergeSort");
            break;

        case 7:
            // Solo permitimos desordenar si efectivamente esta ordenado
            if (estaOrdenado) {
                desordenarArreglo(arreglo, n);
                estaOrdenado = false; // Ya no esta ordenado
                cout << "\nArreglo revuelto nuevamente.\n";
                if (n <= 50) mostrarArreglo(arreglo, n);
            }
            else {
                cout << "Opcion invalida.\n";
            }
            break;

        default: cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    delete[] arreglo;
    return 0;
}