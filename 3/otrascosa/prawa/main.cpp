#include "tablero.hpp"
#include "celula.hpp"

int main(){
    std::pair <int, int> dim;
    std::vector <std::pair <int, int>> coordenadasvivas;
    int nturnos, ncelulasinicio, fila, col;

    // Dimension de la malla y numero de iteraciones
    std::cout << "---JUEGO DE LA VIDA---\nMalla de dimension NxM" << std::endl;
    std::cout << "Introduce la dimension N de la malla: ";
    std::cin >> dim.first;
    std::cout << "Introduce la dimension M de la malla: ";
    std::cin >> dim.second;
    std::cout << "Introduce el numero de turnos que quieres que se desarrollen: ";
    std::cin >> nturnos;

    // Creacion del tablero (con todas las celulas muertas)
    Tablero tablero1(dim);

    // Se establece que celulas empiezan vivas
    std::cout << "Introduce el numero de células vivas con el que quieres empezar: ";
    std::cin >> ncelulasinicio;
    for(int i = 0; i < ncelulasinicio; i++){
        std::cout << "Introduce el numero de fila de la celula " << i + 1 << ": ";
        std::cin >> fila;
        std::cout << "Introduce el numero de columna de la celula " << i + 1 <<": ";
        std::cin >> col;

        tablero1.getCelula(std::make_pair(fila, col))->setEstado(1);
    }

    std::cout << "---TABLERO INICIAL---" << std::endl;
    tablero1.imprimirTablero();

    for(int i = 0; i < nturnos; i++){
        std::cout << "---TURNO " << i+1 << "---" << std::endl;
        tablero1.actualizarTablero();
        tablero1.imprimirTablero();
    }

    //tablero1.cambiosEstado(); // Modificacion

    return 0;
}
