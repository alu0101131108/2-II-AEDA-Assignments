#ifndef TABLERO_
#define TABLERO_

#include "celula.hpp"

#include <iostream>
#include <utility> // Para usar pair
#include <vector>

class Celula;

class Tablero{
private:
    std::pair <int, int> dimension;     // Dimension NXM
    int turnos;
    std::vector <Celula*> vectorTablero;    // El tablero es un solo vector

public:
    Tablero(std::pair <int, int> NxM);

    void actualizarTablero();

    void imprimirTablero();

    Celula* getCelula(std::pair <int, int> coordenada_);

    void cambiosEstado();

};

#endif
