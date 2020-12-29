#ifndef WORLD_H
#define WORLD_H

#include"../libs/lib.h"
#include"slot.h"
#include"function.h"

class World{
	private:
					size_t  lado; 
					Slot ***map = new Slot**[lado]; 

  public:
					World(int exp); 
          void generate_height(int lado_, int ymax, int xmax, float spread);
					void generate_height();
          void erosion();
					void generate_temperature();
					void print_world();
					~World();
};

#endif
