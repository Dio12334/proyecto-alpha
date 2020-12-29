#include"world/world.h"
#include"world/world.cpp"
#include"world/slot.cpp"

int main(){

	int exp;
	std::cin>>exp;			
	World *mundo = new World(exp);	
	mundo->generate_height();
	mundo->print_world();

	return 0;
}
