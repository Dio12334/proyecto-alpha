#ifndef GRAFO_H
#define GRAFO_H

#include"lib.h"
#include"node.h"

template<typename T>


class Grafo{
  protected:
      std::vector<Node<T>*> nodes;
  public:
      Grafo(){};
      void add_node(Node<T>* node){
        nodes.push_back(node);
      }

};

#endif
