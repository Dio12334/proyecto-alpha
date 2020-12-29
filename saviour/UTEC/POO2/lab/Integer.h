#ifndef INTEGER_H
#define INTEGER_H

#include"lib.h"

class Integer{
        private:
                int value;
        public:
                Integer();
                Integer(int value);
                Integer(const Integer& other);
                Integer operator=(const Integer& other);
                Integer operator+(int value);
		Integer operator-(int value);
		Integer operator +=(int value);
		Integer operator -=(int value);
		Integer operator*(int value);
		Integer operator *=(int value);
		Integer operator/(int value);
                Integer operator^(int value);
                operator int();
                friend std::ostream& operator <<(std::ostream& os, const Integer&);
                friend std::istream& operator >>(std::istream& os, Integer&);
		bool operator >(int value);
		bool operator >=(int value);
		bool operator <(int value);
		bool operator <=(int value);
		bool operator ==(int value);
		bool operator !=(int value);
		~Integer();
};


#endif

