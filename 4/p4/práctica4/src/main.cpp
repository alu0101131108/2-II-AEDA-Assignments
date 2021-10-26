#include <iomanip>
#include "../include/templates/Tabla.tpp"
#include "../include/DNI.hpp"

enum funcionDispersion {SUMA, MODULO, PSEUDOALEATORIA};
enum funcionExploracion {LINEAL, CUADRATICA, DOBLEDISPERSION, REDISPEPRSION};

int main()
{
/////// INICIALZACIÓN DE PARÁMETROS //////////
  srand(time(NULL));
  int nCel, nClav, fDisp, fExp, opfExp = 0, nPruebas;
  float factor;
  std::cout << "Introducir los parámetros:\n> Número de Celdas.\n> Número de Claves.\n> Función de Dispersion:\n0 - Suma\n1 - Módulo\n2 - PseudoAleatoria.\n> Función de Exploración:\n0 - Lineal\n1 - Cuadrática\n2 - Doble Dispersión\n3 - Redispersión.\n";
  std::cin >> nCel;
  std::cin >> nClav;
  std::cin >> fDisp;
  std::cin >> fExp;
  if (fExp == 2)
  {
    std::cout << "Introducir la función de dispersión a utilizar en la técnica de exploración de Doble Dispersión.\n";
    std::cin >> opfExp;
  }
  std::cout << "Introducir factor de carga: ";
  std::cin >> factor;
  std::cout << "Introducir el número de pruebas para el experimento: ";
  std::cin >> nPruebas;

  Tabla<DNI> t1(nCel, nClav, fDisp, fExp, opfExp);
  std::vector<DNI> banco;
  int n = factor * nCel * nClav;

/////// CREACIÓN E INSERCIÓN DE CLAVES //////////
  for (int i = 0; i < 2 * n; i++)
    banco.push_back(DNI());

  int nClavesInsertadas = factor * 2 * n;

  for (int i = 0; i < nClavesInsertadas; i++)
    if (!t1.insertar(banco[i]))
      std::cout << "----------------ERROR AL INSERTAR----------------\n";

/////// EXPERIMENTO DE BÚSQUEDA //////////
  int contador = 0, b_minimo = 999999, b_maximo = 0, b_media = 0;
  for (int i = 0; i < nPruebas; i++)
  {
    t1.buscar(banco[rand() % nClavesInsertadas], contador);
    if (b_minimo > contador)
      b_minimo = contador;
    if (b_maximo < contador)
      b_maximo = contador;
    b_media += contador;
    contador = 0;
  }
  b_media = b_media / nPruebas;


/////// EXPERIMENTO DE INSERCIÓN //////////
  int i_minimo = 999999, i_maximo = 0, i_media = 0;
  for (int i = 0; i < nPruebas; i++)
  {
    t1.buscar(banco[nClavesInsertadas + rand() % (2 * n - nClavesInsertadas)], contador);
    if (i_minimo > contador)
      i_minimo = contador;
    if (i_maximo < contador)
      i_maximo = contador;
    i_media += contador;
    contador = 0;
  }
  i_media = i_media / nPruebas;

/////// MUESTEO DE VALORES //////////
  int wd = 30;
  std::string str_fDisp;
  switch (fDisp)
  {
    case 0:
    str_fDisp = "Módulo";
      break;
    case 1:
    str_fDisp = "Suma";
      break;
    case 2:
    str_fDisp = "Pseudoaleatoria";
      break;
    default:
    str_fDisp = "Módulo";
  }
  std::string str_fExp;
  switch (fExp)
  {
    case 0:
    str_fExp = "Lineal";
      break;
    case 1:
    str_fExp = "Cuadrática";
      break;
    case 2:
    str_fExp = "Doble Dispersión";
      break;
    case 3:
    str_fExp = "Redispersión";
      break;
    default:
    str_fExp = "Módulo";
  }
  std::cout << std::endl << "nCeldas" << std::setw(wd) << "nClaves" << std::setw(wd) << "Dispersión" << std::setw(wd) << "Exploración" << std::setw(wd) << "Carga" << std::setw(wd) << "Pruebas" << std::endl;
  std::cout << nCel << std::setw(wd - 1) << nClav << std::setw(wd + 5) << str_fDisp << std::setw(wd) << str_fExp << std::setw(wd) << factor << std::setw(wd) << nPruebas << std::endl << std::endl;
  std::cout << std::setw(1.3 * wd) << "Mínimo" << std::setw(wd) << "Medio" << std::setw(wd) << "Máximo" << std::endl;
  std::cout << "Búsquedas:" << std::setw(wd) << b_minimo << std::setw(wd) << b_media << std::setw(wd) << b_maximo << std::endl;
  std::cout << "Inserción:" << std::setw(wd) << i_minimo << std::setw(wd) << i_media << std::setw(wd) << i_maximo << std::endl << std::endl;


  return 0;
}
