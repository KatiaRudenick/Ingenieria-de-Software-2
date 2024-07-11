#ifndef TEAPOT_HPP
#define TEAPOT_HPP

#pragma once

#include <algorithm>
#include <iostream>

class Teapot
{
public:
    Teapot(int capacidad) : capacidad(capacidad), cantidad_actual(0) {}
    ~Teapot() {}

    void llenar(int cantidad) {
        if (cantidad <= 0) {
            std::cerr << "La cantidad debe ser positiva." << std::endl;
            return;
        }
        cantidad_actual = std::min(cantidad, capacidad);
    }

    bool servir(int tamaño_taza) {
        if (tamaño_taza <= 0) {
            std::cerr << "El tamaño de la taza debe ser positivo." << std::endl;
            return false;
        }
        if (cantidad_actual >= tamaño_taza) {
            cantidad_actual -= tamaño_taza;
            return true;
        }
        return false;
    }

    int obtenerCantidadActual() const {
        return cantidad_actual;
    }

private:
    int capacidad;        
    int cantidad_actual;  
};

#endif
