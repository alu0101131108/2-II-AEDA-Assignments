#include "Dll.tpp"

template <class T>
class Queue
{
  private:
    Dll<T> main_dll;

  public:
    Queue()
    {}
    void push(T data)
    {
      main_dll.insert_tail(data);
    }
    void pop()
    {
      assert(!empty());
      main_dll.extract_head();
    }
    T front()
    {
      assert(!empty());
      return main_dll.get_head() -> get_data();
    }
    T back()
    {
      assert(!empty());
      return main_dll.get_tail() -> get_data();
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
