#ifndef CELULA_
#define CELULA_

#include "tablero.hpp"

#include <iostream>
#include <utility> // Para usar pair
#include <vector>


class Tablero;  // El compilador entiende que hay una clase tablero pero todavia no esta definida

class Celula{
private:
    int estado;
    int cambioestado = 0;
    std::pair <int, int> coordenada;    // Coordenadas (i,j)
public:
    Celula(){
        estado = 0;
    }
    Celula(int i, int j){
        estado = 0; // La célula empieza muerta
        coordenada.first = i;
        coordenada.second = j;
    }

    int getEstado() const;

    void setEstado(int newEstado);

    int getCambios() const;

    int actualizarEstado(int nvecinas);

    int contarVecinas(Tablero& tablero_);

    friend std::ostream& operator<<(std::ostream& os, const Celula& cell);
};

#endif