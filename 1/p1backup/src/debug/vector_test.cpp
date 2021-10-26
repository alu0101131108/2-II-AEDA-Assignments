#include "./../Vector.tpp"

int main(){

  std::cout << "Se crea un vector a de tamaño 5, pos 0 = 'p' y pos 1 = 'n'." << std::endl;
  Vector<char> a(5);
  a[0] = 'p';
  a[1] = 'n';
  a.basic_type_print();

  std::cout << "Se crea un vector b de tamaño 10, se iguala al vector a, se inserta 'z' en pos = 4 y se hace un pushback de 'w'." << std::endl;
  Vector<char> b(10);
  b = a;
  b[4] = 'z';
  b.push_back('w');
  b.basic_type_print();

  std::cout << "Se crea un vector c, tamaño 5 con valores arbitrarios." << std::endl;
  Vector<int> c(5);
  c[0] = 1;
  c[2] = 3;
  c[3] = 2;
  c[4] = 8;
  c.basic_type_print();

  std::cout << "Se redimensiona a 8 y se establece el elemento pos 7 = 3." << std::endl;
  c.resize(8);
  c[7] = 3;
  c.basic_type_print();

  std::cout << "Se redimensiona a tamaño 3." << std::endl;
  c.resize(3);
  c.basic_type_print();

  return 0;
}
