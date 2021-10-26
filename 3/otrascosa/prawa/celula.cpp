#include "celula.hpp"


int Celula::getEstado() const{
    return estado;
}

void Celula::setEstado(int newEstado){
    estado = newEstado;
}

int Celula::getCambios() const{
    return cambioestado;
}

int Celula::actualizarEstado(int nvecinas){     // Retorna 1 o 0 para hacer estado = actualizarEstado()
    if(estado == 0){
        if(nvecinas == 3){     // Si una celúla muerta tiene 3 vecinas vivas pasa a estar viva
            cambioestado++;
            return 1;
        }
    }
    else{
        if(nvecinas != 2 && nvecinas != 3){    // Si una célula viva no tiene 2 o 3 vecinas vivas pasa a estar muerta
            cambioestado++;
            return 0;
        }
    }
}

int Celula::contarVecinas(Tablero& tablero_){
    int nvecinasvivas = 0;
    for(int j = coordenada.second - 1; j < coordenada.second + 2; j++){
        for(int i = coordenada.first - 1; i < coordenada.first + 2; i++){
          std::pair<int, int> coordenada_(i, j);
          if(tablero_.getCelula(coordenada_) != this)     // Compruebo que la célula a la que estoy viendo no es la propia célula de referencia
            if(tablero_.getCelula(coordenada_)->getEstado() == 1)
              nvecinasvivas++;
        }
    }
    return nvecinasvivas;
}

std::ostream& operator<<(std::ostream& os, const Celula& cell){
    if(cell.getEstado() == 0)
        os << " ";
    else
        os << "X";
    return os;
}
