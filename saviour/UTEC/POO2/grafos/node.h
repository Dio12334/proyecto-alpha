#ifndef NODE_H
#define NODE_H

#include"lib.h"

template<typename T>
struct Node{

  T value;

  std::vector<Node<T>*> adj;

  Node<T>* father;
  Node<T>* left;
  Node<T>* right;

  Node(T value){
    this->value = value;
    father = left = right = nullptr;
  }

  void add_adj(Node<T>* node){
    adj.push_back(node);
  }

  void print_adj(){
    for(size_t i = 0; i < adj.size(); i++)
        std::cout<<adj[i]->value<<" ";
  
  std::cout<<std::endl;
  }
};

#endif
