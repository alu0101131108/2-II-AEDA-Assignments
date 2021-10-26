template <class T>
void Node<T>::set_next(Node<T>* n)
{
  next = n;
}

template <class T>
void Node<T>::set_prev(Node<T>* p)
{
  prev = p;
}

template <class T>
void Node<T>::set_data(T dat)
{
  data = dat;
}

template <class T>
Node<T>* Node<T>::get_next()
{
  return next;
}

template <class T>
Node<T>* Node<T>::get_prev()
{
  return prev;
}

template <class T>
T Node<T>::get_data()
{
  return data;
}
