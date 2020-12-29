#ifndef NUMBER_H
#define NUMBER_H

#include"lib.h"

template <typename T>

class Number{
        private:
                T value;
        public:
                Number();
                Number(int value);
                Number(const Number<T>& other);
                Number<T> operator=(const Number<T>& other);
                Number<T> operator+(int value);
                Number<T> operator-(int value);
                Number<T> operator +=(int value);
                Number<T> operator -=(int value);
                Number<T> operator*(int value);
                Number<T> operator *=(int value);
                Number<T> operator/(int value);
                Number<T> operator^(int value);
                operator int();
		template <typename U>
                friend std::ostream& operator <<(std::ostream& os, const Number<U>&);
		template <typename U>
                friend std::istream& operator >>(std::istream& os, Number<U>&);
                bool operator >(int value);
                bool operator >=(int value);
                bool operator <(int value);
                bool operator <=(int value);
                bool operator ==(int value);
                bool operator !=(int value);
		~Number();


};


#endif

