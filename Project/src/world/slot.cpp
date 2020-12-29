#include"slot.h"

Slot::Slot(){
	Height = 0;
	Illumination = 0;
	Day_Night = true;
}

void Slot::set_day(){
	Day_Night = true;
}

void Slot::set_night(){
	Day_Night = false;
}

void Slot::set_height(float height){
	Height = height;
}

void Slot::set_illumination(int illumination){
	Illumination = illumination;
}

float Slot::get_height(){
	return Height;
}

void Slot::add_resource(Resource* resource){
	Resources.emplace_back(resource);
}

Slot::~Slot(){
//	for(auto res: Resources){
     // delete res;
 // }	
}

