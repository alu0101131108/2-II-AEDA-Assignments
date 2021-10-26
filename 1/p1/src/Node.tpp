#include <iostream>
#include <cassert>

template <class T>
class Node
{
  private:
    T data;
    Node<T> *next, *prev;

  public:
    Node(T dat): data(dat), next(NULL), prev(NULL)
    {}

    void set_next(Node<T>* n)
    {
      next = n;
    }
    void set_prev(Node<T>* p)
    {
      prev = p;
    }
    void set_data(T dat)
    {
      data = dat;
    }
    Node<T>* get_next()
    {
      return next;
    }
    Node<T>* get_prev()
    {
      return prev;
    }
    T get_data()
    {
      return data;
    }

};
