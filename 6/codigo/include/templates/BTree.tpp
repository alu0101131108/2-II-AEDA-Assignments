#ifndef BTREE_
#define BTREE_

#include <queue>

template <class T>
class BTree
{
  protected:
    BNode<T>* root;

  public:
    BTree(): root(NULL)
    {}
    void printNode(BNode<T>* node)
    {
      if (node != NULL)
        std::cout << "[" << node ->  getData() << "] ";
      else
        std::cout << "[.] ";
    }
    void printTree()
    {
      int level = 0;
      std::queue<BNode<T>*> queue;
      queue.push(root);
      while (!queue.empty())
      {
        int nNodes = queue.size();
        std::cout << "Nivel " << level << ": ";
        while (nNodes > 0)
        {
          BNode<T>* temp_node = queue.front();
          printNode(temp_node);
          queue.pop();

          if (temp_node != NULL)
          {
            queue.push(temp_node -> getLeft());
            queue.push(temp_node -> getRight());
          }

          nNodes--;
        }
        std::cout << '\n';
        level++;
      }
      std::cout << "\n\n";
    }
};

template <class T>
class BTree_S : public BTree<T>
{
  public:
    BTree_S(): BTree<T>()
    {}
    BNode<T>* search(const T& data)
    {
      return searchBranch(BTree<T>::root, data);
    }
    BNode<T>* searchBranch(BNode<T>* node, const T& data)
    {
      if (node == NULL)
        return NULL ;
      if (data == node -> getData())
        return node ;
      if (data < node -> getData())
        return searchBranch(node -> getLeft(), data);
     return searchBranch(node -> getRight(), data);
    }
    void insert(const T& data)
    {
      insertBranch(BTree<T>::root, data);
    }
    void insertBranch(BNode<T>* &node, const T& data)
    {
      if (node == NULL)
        node = new BNode<T>(data);

      else if (data < node -> getData())
        insertBranch(node -> getLeft(), data);

      else
        insertBranch(node -> getRight(), data);
    }
    void deleteKey(const T& data)
    {
      deleteBranch(BTree<T>::root, data);
    }
    void deleteBranch(BNode<T>* &node, const T& data)
    {
      if (node != NULL)
      {
        if (data < (node -> getData()))
          deleteBranch(node -> getLeft(), data);
        else if (data > (node -> getData()))
          deleteBranch(node -> getRight(), data);
        else
        {
          BNode<T>* deleted = node;
          if (node -> getRight() == NULL)
            node = node -> getLeft();
          else if (node -> getLeft() == NULL)
            node = node -> getRight();
          else
            swap(deleted, node -> getLeft());
          delete(deleted);
        }
      }
    }
    void swap(BNode<T>* &oldNode, BNode<T>* &newNode)
    {
      if (newNode-> getRight() != NULL)
        swap(oldNode, newNode-> getRight());
      else
      {
        oldNode -> setData(newNode -> getData());
        oldNode = newNode;
        newNode = newNode -> getLeft();
      }
    }
    int depth(BNode<T>* node)
    {
      int prof = 0;
      while (node != NULL)
      {
        prof++;
        node = node -> getLeft();
      }
      return prof;
    }
    bool balanced(BNode<T>* root_)
    {
      int d = depth(root_);
      return balancedBranch(root_, d, 0);
    }
    bool balancedBranch(BNode<T>* root_, int d, int level)
    {
      if (root_ == NULL)
        return true;

      else if (root_ -> getLeft() == NULL && root_ -> getRight() == NULL)
        return (d == level + 1);

      else if (root_ -> getLeft() == NULL || root_ -> getRight() == NULL)
        return false;

      return balancedBranch(root_ -> getLeft(), d, level + 1) && balancedBranch(root_ -> getRight(), d, level + 1);
    }
    BNode<T>* getRoot()
    {
      return BTree<T>::root;
    }
};

#endif
