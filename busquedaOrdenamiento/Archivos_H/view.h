#pragma once
#ifndef VIEW_H
#define VIEW_H

/**
 * @file view.h
 * @brief Declaracion de las funciones para la interfaz de usuario en consola.
 */

 /**
  * @brief Despliega las opciones principales y anade dinamicamente la opcion de desordenar.
  * @param estaOrdenado Verdadero si el arreglo ya fue procesado, habilita la opcion 7.
  */
void mostrarMenu(bool estaOrdenado);

/**
 * @brief Imprime los elementos en consola de manera secuencial.
 * @param arreglo Puntero al arreglo de enteros.
 * @param n Tamano del arreglo (N).
 */
void mostrarArreglo(int arreglo[], int n);

/**
 * @brief Solicita al usuario el numero especifico que desea localizar.
 * @return El numero entero ingresado por el usuario.
 */
int pedirValor();

/**
 * @brief Despliega el sub-menu con los algoritmos de clasificacion disponibles.
 * @return El numero de la opcion seleccionada por el usuario.
 */
int mostrarMenuOrdenamiento();

/**
 * @brief Define la cantidad total de elementos que contendra el arreglo dinamico.
 * @return El tamano (N) ingresado por el usuario.
 */
int pedirTamanio();

/**
 * @brief Determina el comportamiento del generador aleatorio.
 * @return Verdadero si se permiten repetidos, Falso para unicos.
 */
bool pedirSiRepetir();

/**
 * @brief Activa o desactiva la impresion en consola de los pasos intermedios.
 * @return Verdadero si el usuario desea ver el proceso, Falso de lo contrario.
 */
bool pedirMostrarProceso();

#endif