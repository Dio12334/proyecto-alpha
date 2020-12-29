#include"grafo.h"
#include"grafo_nd.h"

int main(){
 
  Grafo_ND<int> grafo;


  Node<int>* node_1 = new Node<int>(0);
  grafo.add_node(node_1);
  Node<int>* node_2 = new Node<int>(1);
  grafo.add_node(node_2);
  Node<int>* node_3 = new Node<int>(2);
  grafo.add_node(node_3);
  Node<int>* node_4 = new Node<int>(3);
  grafo.add_node(node_4);
  Node<int>* node_5 = new Node<int>(4);
  grafo.add_node(node_5);

  grafo.add_edge(node_1, node_2);
  grafo.add_edge(node_1, node_3);
  grafo.add_edge(node_2, node_3);
  grafo.add_edge(node_2, node_4);
  grafo.add_edge(node_3, node_4);
  grafo.add_edge(node_3, node_5);
  grafo.add_edge(node_5, node_4);

  grafo.print_edges();
  grafo.bfs(node_1);
  return 0;


}
