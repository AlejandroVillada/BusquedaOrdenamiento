#pragma once
#ifndef GESTOR_ARREGLO_H
#define GESTOR_ARREGLO_H

// Define la estructura del objeto GestorArreglo. Encapsula los datos y declara los metodos de busqueda, ordenamiento y medicion.
class GestorArreglo
{
private:
    int* arreglo;
    int n;
    bool estaOrdenado;

    // Metodos auxiliares de uso interno
    void quickSortRec(int* arr, int izquierda, int derecha, int& comp, int& inter, bool mostrar);
    void merge(int* arr, int izquierda, int medio, int derecha, int& comp, bool mostrar);
    void mergeSortRec(int* arr, int izquierda, int derecha, int& comp, bool mostrar);

public:
    GestorArreglo();
    ~GestorArreglo();

    void configurar(int tam, bool unicos);
    void desordenar();
    void mostrar();
    bool getEstaOrdenado();
    int getN();

    int busquedaSecuencial(int valor);
    int busquedaBinaria(int valor);

    void ordenarBurbuja(bool mostrar);
    void ordenarSeleccion(bool mostrar);
    void ordenarInsercion(bool mostrar);
    void ordenarQuickSort(bool mostrar);
    void ordenarMergeSort(bool mostrar);

    void compararTiempos();
};

#endif