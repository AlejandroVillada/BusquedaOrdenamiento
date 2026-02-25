#include "sort.h"
#include <iostream>
using namespace std;

// Empuja los valores mas grandes hacia el final del arreglo mediante intercambios adyacentes.
void ordenarBurbuja(int arreglo[], int n, bool mostrar)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                if (mostrar) cout << "[Burbuja] Intercambiando " << arreglo[j] << " con " << arreglo[j + 1] << endl;
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// Escanea la lista buscando el valor minimo para colocarlo al inicio, iteracion por iteracion.
void ordenarSeleccion(int arreglo[], int n, bool mostrar)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arreglo[j] < arreglo[min]) {
                min = j;
            }
        }
        if (mostrar && min != i) cout << "[Seleccion] Moviendo minimo " << arreglo[min] << " a posicion " << i << endl;
        temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
    }
}

// Acomoda cada elemento nuevo en su posicion correcta respecto a los anteriores.
void ordenarInsercion(int arreglo[], int n, bool mostrar)
{
    int i, j, clave;
    for (i = 1; i < n; i++) {
        clave = arreglo[i];
        j = i - 1;
        while (j >= 0 && arreglo[j] > clave) {
            if (mostrar) cout << "[Insercion] Desplazando " << arreglo[j] << " a la derecha" << endl;
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
    }
}

// Fragmenta la informacion basandose en un pivote central recursivamente.
void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios, bool mostrar)
{
    int i = izquierda, j = derecha;
    int pivote = arreglo[(izquierda + derecha) / 2];
    int temp;

    if (mostrar) cout << "[QuickSort] Pivote: " << pivote << " Rango: " << izquierda << "-" << derecha << endl;

    while (i <= j) {
        while (arreglo[i] < pivote) { i++; comparaciones++; }
        while (arreglo[j] > pivote) { j--; comparaciones++; }
        if (i <= j) {
            temp = arreglo[i]; arreglo[i] = arreglo[j]; arreglo[j] = temp;
            intercambios++; i++; j--;
        }
    }
    if (izquierda < j) quickSort(arreglo, izquierda, j, comparaciones, intercambios, mostrar);
    if (i < derecha) quickSort(arreglo, i, derecha, comparaciones, intercambios, mostrar);
}

// Funcion auxiliar que fusiona dos sub-arreglos instanciando memoria 100% dinamica.
void merge(int arreglo[], int izquierda, int medio, int derecha, int& comparaciones, bool mostrar)
{
    int i = izquierda, j = medio + 1, k = 0;
    int* temp = new int[derecha - izquierda + 1](); // Seguro dinamico

    while (i <= medio && j <= derecha) {
        comparaciones++;
        if (arreglo[i] <= arreglo[j]) temp[k++] = arreglo[i++];
        else temp[k++] = arreglo[j++];
    }
    while (i <= medio) temp[k++] = arreglo[i++];
    while (j <= derecha) temp[k++] = arreglo[j++];

    for (i = izquierda, k = 0; i <= derecha; i++, k++) arreglo[i] = temp[k];

    if (mostrar) cout << "[Merge] Fusionando rango " << izquierda << " a " << derecha << endl;
    delete[] temp;
}

// Divide el arreglo por la mitad recursivamente.
void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones, bool mostrar)
{
    int medio;
    if (izquierda < derecha) {
        medio = (izquierda + derecha) / 2;
        mergeSort(arreglo, izquierda, medio, comparaciones, mostrar);
        mergeSort(arreglo, medio + 1, derecha, comparaciones, mostrar);
        merge(arreglo, izquierda, medio, derecha, comparaciones, mostrar);
    }
}