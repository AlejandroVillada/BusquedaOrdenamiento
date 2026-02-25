/**
 * @file Main.cpp
 * @brief Controlador principal del proyecto Orientado a Objetos.
 * Despliega la interfaz de usuario e instancia el objeto GestorArreglo,
 * delegando asi toda la logica de datos y procesamiento.
 */
#include <iostream>
#include "GestorArreglo.h"

using namespace std;

int pedirTamanio() {
    int n;
    cout << "\n=== CONFIGURACION DE ARREGLO ===\n";
    cout << "Ingrese el tamanio (N): ";
    cin >> n;
    return n;
}

bool pedirSiRepetir() {
    int op;
    cout << "Desea numeros repetidos?\n1. Si (Aleatorios puros)\n2. No (Unicos 0..N)\nOpcion: ";
    cin >> op;
    return (op == 1);
}

int pedirValor() {
    int valor;
    cout << "Ingrese valor a buscar: ";
    cin >> valor;
    return valor;
}

void mostrarMenuPrincipal(bool estaOrdenado) {
    cout << "\n=== MENU ===\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)\n";
    cout << "3. Ordenar Arreglo\n";
    cout << "4. Salir\n";
    cout << "5. Re-generar Arreglo (Cambiar N o tipo)\n";
    cout << "6. Comparativa de Tiempos (Todos)\n";
    if (estaOrdenado) cout << "7. Desordenar arreglo actual\n";
    cout << "Seleccione opcion: ";
}

int main()
{
    int opcion;
    int metodo;
    int posicion, valor;
    bool mostrarPasos = false;

    GestorArreglo gestor;

    int n = pedirTamanio();
    bool repetir = pedirSiRepetir();

    gestor.configurar(n, !repetir);
    cout << "\nArreglo generado correctamente.\n";
    gestor.mostrar();

    do
    {
        mostrarMenuPrincipal(gestor.getEstaOrdenado());
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            gestor.mostrar();
            valor = pedirValor();
            posicion = gestor.busquedaSecuencial(valor);
            if (posicion != -1) cout << "Valor encontrado en pos: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;

        case 2:
            cout << "\nPara binaria, primero ordenamos (QuickSort silencioso)...\n";
            valor = pedirValor();
            posicion = gestor.busquedaBinaria(valor);
            if (posicion != -1) cout << "Valor encontrado en pos: " << posicion << endl;
            else cout << "Valor no encontrado.\n";
            break;

        case 3:
            cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
            cout << "1. Burbuja\n2. Seleccion\n3. Insercion\n4. QuickSort\n5. MergeSort\nSeleccione metodo: ";
            cin >> metodo;
            cout << "Desea ver el proceso paso a paso? (Lento para N grande)\n1. Si\n2. No\nOpcion: ";
            int opPasos;
            cin >> opPasos;
            mostrarPasos = (opPasos == 1);

            // PROTECCION CONTRA COLAPSO DE CONSOLA
            if (mostrarPasos && gestor.getN() > 50) {
                cout << "\n[!] Proteccion de consola: Ocultando pasos (Imprimir N > 50 trabaria tu equipo).\n";
                mostrarPasos = false;
            }

            if (gestor.getN() > 10000 && metodo >= 1 && metodo <= 3) {
                cout << "\n[!] Ordenando arreglo masivo. Esto tomara varios segundos, paciencia...\n";
            }

            if (metodo == 1) gestor.ordenarBurbuja(mostrarPasos);
            else if (metodo == 2) gestor.ordenarSeleccion(mostrarPasos);
            else if (metodo == 3) gestor.ordenarInsercion(mostrarPasos);
            else if (metodo == 4) gestor.ordenarQuickSort(mostrarPasos);
            else if (metodo == 5) gestor.ordenarMergeSort(mostrarPasos);
            else cout << "Metodo invalido.\n";

            cout << "\nArreglo ordenado:\n";
            gestor.mostrar();
            break;

        case 4:
            cout << "Saliendo...\n";
            break;

        case 5:
            n = pedirTamanio();
            repetir = pedirSiRepetir();
            gestor.configurar(n, !repetir);
            cout << "\nNuevo arreglo generado.\n";
            gestor.mostrar();
            break;

        case 6:
            if (gestor.getN() > 10000) cout << "\nCalculando... esto tomara tiempo por los metodos lentos.\n";
            gestor.compararTiempos();
            break;

        case 7:
            if (gestor.getEstaOrdenado()) {
                gestor.desordenar();
                cout << "\nArreglo revuelto nuevamente.\n";
                gestor.mostrar();
            }
            else {
                cout << "Opcion invalida.\n";
            }
            break;

        default: cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}