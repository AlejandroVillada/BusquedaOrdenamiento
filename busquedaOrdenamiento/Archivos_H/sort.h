#pragma once
#ifndef SORT_H
#define SORT_H

/**
 * @file sort.h
 * @brief Declaracion de los algoritmos de ordenamiento iterativos y recursivos.
 */

 /**
  * @brief Empuja los valores mas grandes hacia el final del arreglo mediante intercambios adyacentes.
  * @param arreglo Puntero al arreglo de enteros.
  * @param n Tamano del arreglo (N).
  * @param mostrar Verdadero para imprimir el proceso paso a paso en consola.
  */
void ordenarBurbuja(int arreglo[], int n, bool mostrar = false);

/**
 * @brief Escanea la lista buscando el valor minimo para colocarlo al inicio iterativamente.
 * @param arreglo Puntero al arreglo de enteros.
 * @param n Tamano del arreglo (N).
 * @param mostrar Verdadero para imprimir el proceso paso a paso en consola.
 */
void ordenarSeleccion(int arreglo[], int n, bool mostrar = false);

/**
 * @brief Acomoda cada elemento nuevo en su posicion correcta desplazando los demas a la derecha.
 * @param arreglo Puntero al arreglo de enteros.
 * @param n Tamano del arreglo (N).
 * @param mostrar Verdadero para imprimir el proceso paso a paso en consola.
 */
void ordenarInsercion(int arreglo[], int n, bool mostrar = false);

/**
 * @brief Fragmenta la informacion basandose en un pivote central recursivamente.
 * @param arreglo Puntero al arreglo de enteros.
 * @param izquierda Indice inicial del rango a ordenar.
 * @param derecha Indice final del rango a ordenar.
 * @param comparaciones Referencia al contador de comparaciones para medir rendimiento.
 * @param intercambios Referencia al contador de intercambios para medir rendimiento.
 * @param mostrar Verdadero para imprimir el proceso paso a paso en consola.
 */
void quickSort(int arreglo[], int izquierda, int derecha, int& comparaciones, int& intercambios, bool mostrar = false);

/**
 * @brief Divide el arreglo recursivamente por la mitad y fusiona las sublistas de forma ordenada.
 * @param arreglo Puntero al arreglo de enteros.
 * @param izquierda Indice inicial del rango a ordenar.
 * @param derecha Indice final del rango a ordenar.
 * @param comparaciones Referencia al contador de comparaciones para medir rendimiento.
 * @param mostrar Verdadero para imprimir el proceso paso a paso en consola.
 */
void mergeSort(int arreglo[], int izquierda, int derecha, int& comparaciones, bool mostrar = false);

#endif