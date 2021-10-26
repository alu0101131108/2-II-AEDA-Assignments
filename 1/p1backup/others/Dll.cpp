template <class T>
void Dll<T>::insert_head(T item)
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
    cout << "Error: Dll failed, negative size." << endl;
    exit 1;
  }
  size++;
}

template <class T>
void Dll<T>::insert_tail(T item)
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
    cout << "Error: Dll failed, negative size." << endl;
    exit 1;
  }
  size++;
}

template <class T>
void Dll<T>::extract_head()
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
    cout << "Error: Dll failed, nothing to extract." << endl;
    exit 1;
  }
  size--;
}

template <class T>
void Dll<T>::extract_tail()
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
    cout << "Error: Dll failed, nothing to extract." << endl;
    exit 1;
  }
  size--;
}

template <class T>
void Dll<T>::add_next(T item, Node<T>* pnode)
{
  if (pnode == head)
    insert_head(item);
  else
  {
    Node<T>* aux = new Node<T>(item);
    pnode -> get_next() -> set_prev(aux);
    pnode -> set_next(aux);
    size++;
  }
}

template <class T>
void Dll<T>::add_prev(T item, Node<T>* pnode)
{
  if (pnode == tail)
    insert_tail(item);
  else
  {
    Node<T>* aux = new Node<T>(item);
    pnode -> get_prev() -> set_next(aux);
    pnode -> set_prev(aux);
    size++;
  }
}
