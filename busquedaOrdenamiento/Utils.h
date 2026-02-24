#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <string>

void generarArreglo(int*& arreglo, int n, bool unicos);

// Actualizamos las firmas para incluir el parámetro 'bool'
void medirTiempo(void (*func)(int*, int, bool), int* arreglo, int n, std::string nombreAlgoritmo);
void medirTiempoRec(void (*func)(int*, int, int, int&, int&, bool), int* arreglo, int n, std::string nombreAlgoritmo);
void medirTiempoMerge(void (*func)(int*, int, int, int&, bool), int* arreglo, int n, std::string nombreAlgoritmo);
void desordenarArreglo(int* arreglo, int n);
#endif