#ifndef GRAFO_ND_H
#define GRAFO_ND_H

#include"node.h"

template<typename T>

class Grafo_ND{
    private:
        std::vector<Node<T>*> nodes;
    public:
        Grafo_ND(){}

// " exist {{{1

        bool exist(Node<T>* node){
          for(size_t i = 0; i < nodes.size(); i++){
            if(node->value == nodes[i]->value)
               return true; 
          }
          return false;
        }

// " search {{{1

        size_t search(Node<T>* node){
          for(size_t i = 0; i < nodes.size(); i++){
            if(node->value == nodes[i]->value)
                return i;
          }
          return 0;
        }

// " add edge {{{1

        void add_edge(Node<T>* node_1, Node<T>* node_2){
          if(exist(node_1) && exist(node_2)){
              size_t i = search(node_1), j = search(node_2);

              nodes[i]->add_adj(nodes[j]);
              nodes[j]->add_adj(nodes[i]);
          }
          else
             std::cout<<"no se pudo crear la arista"<<std::endl;
             
        }  

// " add node {{{1

        void add_node(Node<T>* node){
          nodes.push_back(node);
        }

        void print_edges(){
          for(size_t i = 0; i < nodes.size(); i++){
            std::cout<<nodes[i]->value<<" ->";
            nodes[i]->print_adj();
          }
          
        }

// " bfs {{{1 

        void bfs(Node<T>* source){

          size_t s = search(source);

          bool visited[nodes.size()];

          for(size_t i = 0; i < nodes.size(); i++){
            visited[i] = false;
          }

          std::queue<Node<T>*> q;

          visited[s] = true;

          q.push(nodes[s]);
          
          while(!q.empty()){

            Node<T>* u = q.front();

            q.pop();

            std::cout<<u->value<<" ";

            for(size_t v = 0; v < u->adj.size(); v++){

              int j = search(u->adj[v]);

              if(visited[j] == false){

                visited[j] = true;

                q.push(u->adj[v]);
              }
            }
        }
      }

        
        
};

#endif
