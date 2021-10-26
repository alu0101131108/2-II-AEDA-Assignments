#include "Dll.tpp"

template <class T>
class Stack
{
  private:
    Dll<T> main_dll;

  public:
    Stack()
    {}
    void push(T data)
    {
      main_dll.insert_head(data);
    }
    void pop()
    {
      assert(!empty());
      main_dll.extract_head();
    }
    T top()
    {
      assert(!empty());
      return main_dll.get_head() -> get_data();
    }
    bool empty()
    {
      return main_dll.get_size() == 0;
    }
    int get_size()
    {
      return main_dll.get_size();
    }
};
