#include "./../Dll.tpp"

int main() {

  Dll<int> tigaiga;
  tigaiga.basic_type_print();
  tigaiga.insert_head(2);
  tigaiga.basic_type_print();
  tigaiga.insert_tail(4);
  tigaiga.basic_type_print();
  Node<int>* pointer = tigaiga.get_head();
  tigaiga.add_next(1, pointer);
  tigaiga.basic_type_print();
  tigaiga.add_next(0, pointer);
  tigaiga.basic_type_print();
  tigaiga.add_prev(3, pointer);
  tigaiga.basic_type_print();
  tigaiga.extract_tail();
  tigaiga.basic_type_print();
  tigaiga.extract_head();
  tigaiga.basic_type_print();

  return 0;
}
