#include "Node.tpp"

template <class T>
class Dll
{
  private:
    Node<T>* head;
    Node<T>* tail;
    int size;

  public:
    Dll(): head(NULL), tail(NULL), size(0)
    {}

    Dll(T item): head(NULL), tail(NULL), size(1)
    {
      insert_head(item);
    }

    Node<T>* get_head()
    {
      return head;
    }
    Node<T>* get_tail()
    {
      return tail;
    }
    int get_size()
    {
      return size;
    }
    void insert_head(T item)
    {
      Node<T>* aux = new Node<T>(item);
      if (size > 0)
      {
        head -> set_next(aux);
        aux -> set_prev(head);
        head = aux;
      }
      else if (size == 0)
      {
        head = aux;
        tail = aux;
      }
      else
      {
        std::cout << "Error: Dll failed, negative size." << std::endl;
      }
      size++;
    }
    void insert_tail(T item)
    {
      Node<T>* aux = new Node<T>(item);
      if (size > 0)
      {
        tail -> set_prev(aux);
        aux -> set_next(tail);
        tail = aux;
      }
      else if (size == 0)
      {
        head = aux;
        tail = aux;
      }
      else
      {
        std::cout << "Error: Dll failed, negative size." << std::endl;
      }
      size++;
    }
    void extract_head()
    {
      if (size > 1)
      {
        head = head -> get_prev();
        delete head -> get_next();
        head -> set_next(NULL);
      }
      else if (size == 1)
      {
        delete head;
        head = NULL;
        tail = NULL;
      }
      else
      {
        std::cout << "Error: Dll failed, nothing to extract." << std::endl;
      }
      size--;
    }
    void extract_tail()
    {
      if (size > 1)
      {
        tail = tail -> get_next();
        delete tail -> get_prev();
        tail -> set_prev(NULL);
      }
      else if (size == 1)
      {
        delete tail;
        head = NULL;
        tail = NULL;
      }
      else
      {
        std::cout << "Error: Dll failed, nothing to extract." << std::endl;
      }
      size--;
    }
    void add_next(T item, Node<T>* pnode)
    {
      if (pnode == head)
        insert_head(item);
      else
      {
        Node<T>* aux = new Node<T>(item);
        aux -> set_prev(pnode);
        aux -> set_next(pnode -> get_next());
        pnode -> get_next() -> set_prev(aux);
        pnode -> set_next(aux);
        size++;
      }
    }
    void add_prev(T item, Node<T>* pnode)
    {
      if (pnode == tail)
        insert_tail(item);
      else
      {
        Node<T>* aux = new Node<T>(item);
        aux -> set_next(pnode);
        aux -> set_prev(pnode -> get_prev());
        pnode -> get_prev() -> set_next(aux);
        pnode -> set_prev(aux);
        size++;
      }
    }
    void basic_type_print()
    {
      std::cout << "size: " << get_size() << std::endl;
      Node<T>* aux = tail;
      while(aux != NULL)
      {
        std::cout << aux -> get_data() << " ";
        aux = aux -> get_next();
      }
      std::cout << std::endl;
    }
};
