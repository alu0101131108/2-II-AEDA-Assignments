#include "./../Queue.tpp"

int main(){

  Queue<char> cola;
  std::cout << "¿Está vacía?: " << cola.empty() << std::endl;
  cola.push('a');
  cola.push('b');
  cola.push('c');
  cola.push('d');

  std::cout << "Entraron en la cola a, b, c y d en ese orden." << std::endl;
  std::cout << "Back: " << cola.back() << std::endl;
  std::cout << "Front: " << cola.front() << std::endl;
  std::cout << "Size: " << cola.get_size() << std::endl;

  std::cout << "Se hacen dos pop de la cola." << std::endl;
  cola.pop();
  cola.pop();
  std::cout << "Back: " << cola.back() << std::endl;
  std::cout << "Front: " << cola.front() << std::endl;
  std::cout << "Size: " << cola.get_size() << std::endl;
  std::cout << "¿Está vacía?: " << cola.empty() << std::endl;
  return 0;
}
