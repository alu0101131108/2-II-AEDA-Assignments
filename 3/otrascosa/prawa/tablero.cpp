#include "tablero.hpp"

Tablero::Tablero(std::pair <int, int> NxM){
    // Lo siguiente se puede resumir en dimension = NxM y añadiendo los +2 en el main
    dimension.first = NxM.first + 2;
    dimension.second = NxM.second + 2;
     // Pasar de NxM a vectorTablero: dimension.first * j + i
    for(int j = 0; j < dimension.second; j++){       // Primero recorre por columna
        for (int i = 0; i < dimension.first; i++)     // Y por cada columna recorre una fila
            vectorTablero.push_back(new Celula(i, j));     // Así la coordenada se guarda correctamente
    }
}


void Tablero::actualizarTablero(){
    std::vector <int> vectorvecinas (dimension.first * dimension.second, 0);    // Constructor de std::vector en el que declaro vectorvecinas de tamaño NxM (el mismo tamaño que vectorTablero) y con todas las posiciones del vector en 0
    // Los bucles van de 1 hasta el límite - 1 porque tiene en cuenta las fronteras
    for(int j = 1; j < dimension.second - 1; j++)   // Primer bucle para contar vecinas de cada celula
        for (int i = 1; i < dimension.first - 1; i++){
            std::pair<int, int> coordenada_(i, j);
                    std::cout << coordenada_.first << " __ " << coordenada_.second << " __ " << dimension.first * j + i << " __ " << dimension.first * dimension.second << std::endl;
            vectorvecinas[dimension.first * j + i] = getCelula(coordenada_)->contarVecinas(*this);  // Pasar de NxM a vector unidimensional: dimension.first * j + i
        }
    for(int j = 1; j < dimension.second - 1; j++)   // Segundo bucle para actualizar el estado de cada celula
        for (int i = 1; i < dimension.first - 1; i++){
            std::pair<int, int> coordenada_(i, j);
            getCelula(coordenada_)->setEstado(getCelula(coordenada_)->actualizarEstado(vectorvecinas[dimension.first * j + i]));  // Pasar de NxM a vector unidimensional: dimension.first * j + i
        }
}

void Tablero::imprimirTablero(){
    for(int j = 1; j < dimension.second - 1; j++){
        std::cout << "| ";
        for (int i = 1; i < dimension.first - 1; i++){
            std::cout << *getCelula(std::pair<int, int> (i,j)) << " |";
        }
        std::cout << std::endl;
    }
}

Celula* Tablero::getCelula(std::pair <int, int> coordenada_){
    return vectorTablero[dimension.first*coordenada_.second + coordenada_.first];   // dimension.first * j + i
}

void Tablero::cambiosEstado(){
    std::pair <int, int> mascambios(0, 0);
    for(int j = 1; j < dimension.second - 1; j++){
        for(int i = 1; j < dimension.first - 1; i++){
            std::pair <int, int> coordenada_(i, j);
            if(getCelula(coordenada_)->getCambios() > getCelula(mascambios)->getCambios())
                coordenada_ = mascambios;
        }
    }

    std::cout << "La celula con mas cambios es la de la coordenada (" << mascambios.first << "," << mascambios.second << ").\n";
}
