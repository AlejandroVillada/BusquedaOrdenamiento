/**
 * @file controlador.cpp
 * @brief Implementacion del flujo principal y logica de menus.
 */
#include <iostream>
#include "controlador.h"
#include "search.h"
#include "sort.h"
#include "view.h"
#include "utils.h"

using namespace std;

void iniciarPrograma() {
    int opcion;
    int metodo;
    int* arreglo = nullptr;
    int n = 0;
    int posicion, valor;
    int comparaciones = 0, intercambios = 0;
    bool mostrarPasos = false;
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

    do {
        mostrarMenu(estaOrdenado);
        cin >> opcion;

        switch (opcion) {
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
            estaOrdenado = true;
            valor = pedirValor();
            posicion = busquedaBinaria(arreglo, n, valor);
            if (posicion != -1) cout << "Valor encontrado en pos: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;
        case 3:
            metodo = mostrarMenuOrdenamiento();
            mostrarPasos = pedirMostrarProceso();
            comparaciones = 0; intercambios = 0;

            if (mostrarPasos && n > 50) {
                cout << "\n[!] Proteccion de consola: Ocultando pasos (Imprimir N > 50 trabaria tu equipo).\n";
                mostrarPasos = false;
            }
            if (n > 10000 && metodo >= 1 && metodo <= 3) {
                cout << "\n[!] Ordenando arreglo masivo. Esto tomara varios segundos, paciencia...\n";
            }

            if (metodo == 1) ordenarBurbuja(arreglo, n, mostrarPasos);
            else if (metodo == 2) ordenarSeleccion(arreglo, n, mostrarPasos);
            else if (metodo == 3) ordenarInsercion(arreglo, n, mostrarPasos);
            else if (metodo == 4) quickSort(arreglo, 0, n - 1, comparaciones, intercambios, mostrarPasos);
            else if (metodo == 5) mergeSort(arreglo, 0, n - 1, comparaciones, mostrarPasos);
            else cout << "Metodo invalido.\n";

            estaOrdenado = true;

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
            estaOrdenado = false;
            cout << "\nNuevo arreglo generado.\n";
            if (n <= 50) mostrarArreglo(arreglo, n);
            break;
        case 6:
            cout << "\n=== TIEMPOS DE EJECUCION (N=" << n << ") ===\n";
            if (n > 10000) cout << "Calculando... esto tomara tiempo por los metodos lentos.\n";
            medirTiempo(ordenarBurbuja, arreglo, n, "Burbuja");
            medirTiempo(ordenarSeleccion, arreglo, n, "Seleccion");
            medirTiempo(ordenarInsercion, arreglo, n, "Insercion");
            medirTiempoRec(quickSort, arreglo, n, "QuickSort");
            medirTiempoMerge(mergeSort, arreglo, n, "MergeSort");
            break;
        case 7:
            if (estaOrdenado) {
                desordenarArreglo(arreglo, n);
                estaOrdenado = false;
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
}