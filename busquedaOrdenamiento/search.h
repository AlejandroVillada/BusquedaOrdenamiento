#pragma once
#ifndef SEARCH_H
#define SEARCH_H

/**
 * @file search.h
 * @brief Declaracion de las funciones de busqueda secuencial y binaria.
 */

 /**
  * @brief Recorre el arreglo elemento por elemento de inicio a fin.
  * @param arreglo Puntero al arreglo de enteros.
  * @param n Tamano del arreglo (N).
  * @param valor El numero entero que se desea encontrar.
  * @return La posicion (indice) del valor, o -1 si no se encuentra.
  */
int busquedaSecuencial(int arreglo[], int n, int valor);

/**
 * @brief Corta el espacio de busqueda a la mitad repetidamente (requiere arreglo ordenado).
 * @param arreglo Puntero al arreglo de enteros.
 * @param n Tamano del arreglo (N).
 * @param valor El numero entero que se desea encontrar.
 * @return La posicion (indice) del valor, o -1 si no se encuentra.
 */
int busquedaBinaria(int arreglo[], int n, int valor);

#endif