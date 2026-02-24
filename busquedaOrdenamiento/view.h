#pragma once
#ifndef VIEW_H
#define VIEW_H

void mostrarMenu(bool estaOrdenado);
void mostrarArreglo(int arreglo[], int n);
int pedirValor();
int mostrarMenuOrdenamiento();

// Nuevas funciones
int pedirTamanio();
bool pedirSiRepetir(); // True = repetidos, False = unicos
bool pedirMostrarProceso();

#endif