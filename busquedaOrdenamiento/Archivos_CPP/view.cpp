#include <iostream>
using namespace std;
#include "view.h"

// Despliega las opciones principales y añade dinamicamente la opcion de desordenar si el arreglo ya fue procesado.
void mostrarMenu(bool estaOrdenado)
{
    cout << "\n=== MENU ===\n";
    cout << "1. Busqueda Secuencial\n";
    cout << "2. Busqueda Binaria (ordena automaticamente)\n";
    cout << "3. Ordenar Arreglo\n";
    cout << "4. Salir\n";
    cout << "5. Re-generar Arreglo (Cambiar N o tipo)\n";
    cout << "6. Comparativa de Tiempos (Todos)\n";

    // Opcion dinamica que pediste
    if (estaOrdenado) {
        cout << "7. Desordenar arreglo actual\n";
    }

    cout << "Seleccione opcion: "; // Lo dejamos al final limpio
}

// Imprime los elementos en consola de manera secuencial.
void mostrarArreglo(int arreglo[], int n)
{
    int i;

    cout << "\nArreglo: ";
    for (i = 0; i < n; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// Solicita al usuario el numero especifico que desea localizar.
int pedirValor()
{
    int valor;
    cout << "Ingrese valor a buscar: ";
    cin >> valor;
    return valor;
}

// Despliega el sub-menu con los algoritmos de clasificacion disponibles.
int mostrarMenuOrdenamiento()
{
    int opcion;

    cout << "\n=== METODOS DE ORDENAMIENTO ===\n";
    cout << "1. Burbuja\n";
    cout << "2. Seleccion\n";
    cout << "3. Insercion\n";
    cout << "4. QuickSort\n";
    cout << "5. MergeSort\n";
    cout << "Seleccione metodo: ";
    cin >> opcion;

    return opcion;
}

// Define la cantidad total de elementos que contendra el arreglo dinamico.
int pedirTamanio() {
    int n;
    cout << "\n CONFIGURACION DE ARREGLO \n";
    cout << "Ingrese el tamanio (N): ";
    cin >> n;
    return n;
}

// Determina el comportamiento del generador aleatorio para permitir o bloquear duplicados.
bool pedirSiRepetir() {
    int op;
    cout << "Desea numeros repetidos?\n1. Si (Aleatorios puros)\n2. No (Unicos 0..N)\nOpcion: ";
    cin >> op;
    return (op == 1);
}

// Activa o desactiva la impresion en consola de los pasos intermedios de los algoritmos.
bool pedirMostrarProceso() {
    int op;
    cout << "Desea ver el proceso paso a paso? (Lento para N grande)\n1. Si\n2. No\nOpcion: ";
    cin >> op;
    return (op == 1);
}