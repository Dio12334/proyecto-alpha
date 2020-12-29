#ifndef GRAFO_D_H
#define GRAFO_D_H

#include"node.h"

template<typename T>

class Grafo_D{
    private:
        std::vector<Node<T>*> nodes;
    public:
        Grafo_D(){}

        bool exist(Node<T>* node){
          for(size_t i = 0; i < nodes.size(); i++){
            if(node->value == nodes[i]->value)
               return true; 
          }
          return false;
        }

        size_t search(Node<T>* node){
          for(size_t i = 0; i < nodes.size(); i++){
            if(node->value == nodes[i]->value)
                return i;
          }
          return 0;
        }

        void add_edge(Node<T>* node_1, Node<T>* node_2){
          if(exist(node_1) && exist(node_2)){
              size_t i = search(node_1), j = search(node_2);

              nodes[i]->add_adj(nodes[j]);
          }
          else
             std::cout<<"no se pudo crear la arista"<<std::endl;
             
        }  

        void add_node(Node<T>* node){
          nodes.push_back(node);
        }

        void print_edges(){
          for(size_t i = 0; i < nodes.size(); i++){
            std::cout<<nodes[i]->value<<" ->";
            nodes[i]->print_adj();
          } 
        } 

};


#endif
