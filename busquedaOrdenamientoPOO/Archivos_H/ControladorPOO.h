#pragma once
#ifndef CONTROLADOR_POO_H
#define CONTROLADOR_POO_H

#include "GestorArreglo.h"

/**
 * @file ControladorPOO.h
 * @brief Declaracion de la clase controladora del proyecto Orientado a Objetos.
 */

 /**
  * @class ControladorPOO
  * @brief Gestiona la interaccion con el usuario y dirige al GestorArreglo.
  */
class ControladorPOO {
private:
    GestorArreglo gestor; // Instancia de nuestro gestor de datos

    // Funciones internas de UI
    int pedirTamanio();
    bool pedirSiRepetir();
    int pedirValor();
    void mostrarMenuPrincipal(bool estaOrdenado);

public:
    ControladorPOO();
    ~ControladorPOO();

    /**
     * @brief Inicia el ciclo principal de la aplicacion interactiva.
     */
    void iniciar();
};

#endif