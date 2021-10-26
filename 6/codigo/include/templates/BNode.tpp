#ifndef BNODE_
#define BNODE_

template <class T>
class BNode
{
  private:
    T data;
    BNode<T>* left;
    BNode<T>* right;

  public:
    BNode(const T & data_, BNode<T>* left_ = NULL, BNode<T>* right_ = NULL): data(data_), left(left_), right(right_)
    {}
    void setData(T data_)
    {
      data = data_;
    }
    T& getData()
    {
      return data;
    }
    BNode<T>*& getLeft()
    {
      return left;
    }
    BNode<T>*& getRight()
    {
      return right;
    }
};

#endif
