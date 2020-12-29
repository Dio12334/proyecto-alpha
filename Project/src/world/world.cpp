#include"world.h"
#include"function.cpp"
// " World() {{{1 

World::World(int exp): lado(pow(2, exp) +1){
		
	for(size_t i = 0; i < lado; i++) 
				map[i] = new Slot*[lado];	
	for(size_t i = 0; i < lado; i++) 
        for(size_t j = 0; j < lado; j++) 
              map[i][j] = new Slot;

}

// " generate_height() {{{1

void World::generate_height(int lado_, int ymax, int xmax, float spread){
    
    float div = 1.5;
  //caso base
    if(lado_ == 2)
      return;

    int yini = ymax - lado_ +1, xini = xmax - lado_ +1, midy = midpoint(yini, ymax), midx = midpoint(xini, xmax);

  map[yini][midx]->set_height(average_2(map[yini][xini]->get_height(), map[yini][xmax]->get_height()));
  map[ymax][midx]->set_height(average_2(map[ymax][xini]->get_height(), map[ymax][xmax]->get_height()));   
  map[midy][xini]->set_height(average_2(map[yini][xini]->get_height(), map[ymax][xini]->get_height()));
  map[midy][xmax]->set_height(average_2(map[yini][xmax]->get_height(), map[ymax][xmax]->get_height()));
  map[midy][midx]->set_height(jitter(average_4(map[yini][midx]->get_height(), map[ymax][midx]->get_height(), map[midy][xini]->get_height(), map[midy][xmax]->get_height()),0 , spread/2));

  
  generate_height(lado_/2 +1, midy, midx, spread/div);
  generate_height(lado_/2 +1, midy, xmax, spread/div);
  generate_height(lado_/2 +1, ymax, midx, spread/div);
  generate_height(lado_/2 +1, ymax, xmax, spread/div);
}

void World::generate_height(){

  /*
   *MIDPOINT DISPLACEMENT ALGORITHM 2D

   *1 Agrega 4 valores aleatorios al mapa
   *2 Promedia las esos 4 valores en los puntos medios de las aristas del mapa
   *3 Promedia esas 4 aristas en el medio del mapa y se le suma un error
   *4 repetir para los nuevos sub-cuadrados creados

   * */
  float spread = 15, init = 10; 
  //agrega los 4 valores aleatorios  
	map[0][0]->set_height(random_number(0, init));
	map[0][lado-1]->set_height(random_number(0, init)); 
	map[lado-1][0]->set_height(random_number(0, init)); 
	map[lado-1][lado-1]->set_height(random_number(0, init)); 
  
  //promedia las aristas y el punto medio
  int midy = midpoint(0, lado-1), midx = midpoint(0, lado-1), ymax =lado-1, xmax = ymax;

  map[0][midx]->set_height(average_2(map[0][0]->get_height(), map[0][xmax]->get_height()));
  map[ymax][midx]->set_height(average_2(map[ymax][0]->get_height(), map[ymax][xmax]->get_height()));   
  map[midy][0]->set_height(average_2(map[0][0]->get_height(), map[ymax][0]->get_height()));
  map[midy][xmax]->set_height(average_2(map[0][xmax]->get_height(), map[ymax][xmax]->get_height()));
  map[midy][midx]->set_height(jitter(average_4(map[0][midx]->get_height(), map[ymax][midx]->get_height(), map[midy][0]->get_height(), map[midy][xmax]->get_height()),0 , spread));
  
  //llama la función para los 4 nuevos cuadrados creados
  generate_height(lado/2 +1, midy, midx, spread);
  generate_height(lado/2 +1, midy, xmax, spread);
  generate_height(lado/2 +1, ymax, midx, spread);
  generate_height(lado/2 +1, ymax, xmax, spread);
}

 
// erosion() {{{1

void World::erosion(){
  
  
}
// " generate_temperature() {{{1 

void World::generate_temperature(){
  
}
  
// " print_world() {{{1  

void World::print_world(){

	for(size_t i = 0; i < lado; i++){
					for(size_t j = 0; j < lado; j++){
            //std::cout<<map[i][j]->get_height()<<" ";
           //if(map[i][j]->get_height() <= 1)
           //   std::cout<<"~ ";
           if(map[i][j]->get_height() <= 2)
              std::cout<<"  ";//.
           else if(map[i][j]->get_height() <= 4)
               std::cout<<"  ";//,
           else if(map[i][j]->get_height() <= 6)
               std::cout<<"- ";
           else if(map[i][j]->get_height() <= 8)
               std::cout<<"_ ";
           else if(map[i][j]->get_height() <= 10)
               std::cout<<"+ ";
           else if(map[i][j]->get_height() <= 12)
               std::cout<<"^ ";
           else if(map[i][j]->get_height() <= 14)
               std::cout<<"n ";
           else if(map[i][j]->get_height() <= 16)
               std::cout<<"m ";
           else if(map[i][j]->get_height() <= 18)
               std::cout<<"ŋ ";
           else 
               std::cout<<"A ";
          }
					std::cout<<std::endl;
	}

}
  
// " ~World() {{{1

World::~World(){
	for(size_t i = 0; i < lado; i++) 
					for(size_t j = 0; j < lado; j++) 
									delete map[i][j];
	for(size_t i = 0; i < lado; i++)
					delete [] map[i];
	delete [] map;
	map = nullptr;
}

