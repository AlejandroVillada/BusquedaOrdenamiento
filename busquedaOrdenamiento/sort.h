#pragma once
#ifndef SORT_H
#define SORT_H

// Agregamos el parámetro opcional 'mostrar' (por defecto false)
void ordenarBurbuja(int arreglo[], int n, bool mostrar = false);
void ordenarSeleccion(int arreglo[], int n, bool mostrar = false);
void ordenarInsercion(int arreglo[], int n, bool mostrar = false);
void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios, bool mostrar = false);
void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones, bool mostrar = false);

#endif