#include"Integer.h"

Integer::Integer(){
        value = 0;
}
Integer::Integer(int value){
        this->value = value;
}
Integer::Integer(const Integer& other){
        this->value = other.value;
}
Integer Integer::operator=(const Integer& other){
        this->value = other.value;
}
Integer Integer::operator+(int value){
        return Integer(this->value + value);
}
Integer Integer::operator-(int value){
	return Integer(this->value - value);
}
Integer Integer::operator +=(int value){
	this->value += value;
}
Integer Integer::operator -=(int value){
	this->value -= value;
}
Integer Integer::operator*(int value){
	return Integer(this-> value * value);
}
Integer Integer::operator *=(int value){
	this->value *= value;
}
Integer Integer::operator/(int value){
	return Integer(this->value /value);
}
Integer Integer::operator^(int value){
        int temp = 1;
        for(int i = 0; i < value; i++){
                temp *= this->value;
        }
        return Integer(temp);
}
Integer::operator int(){
        return (int)this->value;
}
std::ostream& operator <<(std::ostream& os, const Integer& x){
        os<< x.value;
        return os;
}
std::istream& operator >>(std::istream& os, Integer& x){
        os>> x.value;
        return os;
}
bool Integer::operator >(int value){
	if(this->value > value)
		return true;
	return false;
}
bool Integer::operator >=(int value){
	if(this->value >= value)
		return true;
	return false;
}
bool Integer::operator <(int value){
	if(this->value < value)
		return true;
	return false;
}
bool Integer::operator <=(int value){
	if(this->value <= value)
		return true;
	return false;
}
bool Integer::operator ==(int value){
	if(this->value == value)
		return true;
	return false;
}
bool Integer::operator !=(int value){
	if(this->value != value)
		return true;
	return false;
}
Integer::~Integer(){}

