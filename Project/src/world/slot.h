#ifndef SLOT_H
#define SLOT_H

#include"../libs/lib.h"
#include"resources/resource.h"

struct Temperature{

	double Max = 0.0; //temperatura maxima
	double Min = 0.0; // temperatura minima
	double actual = 0.0; //temperatura actual

};

class Slot{

	private:
			Temperature Temp;
			float Height; // nivel del mar = 0
			int Illumination;
			bool Day_Night;
			std::vector<Resource*> Resources;
			
	public:

			Slot();
			void set_day();
			void set_night();
			void set_height(float height);
			float get_height();
			void set_illumination(int illumination);
			void add_resource(Resource* resource);
			~Slot();
};

#endif
