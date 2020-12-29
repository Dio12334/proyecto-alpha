#ifndef UTVEC_H
#define UTVEC_H

#include"lib.h"

namespace utec{

	template<typename T>
	
	class vector{
		private:
			std::size_t tamano;
			std::size_t capacity;
			T *vec = nullptr;


		public:
			vector();
			vector(utec::vector<T>& other);
			utec::vector<T> operator=(utec::vector<T>& other);
			vector(std::size_t tam);
			~vector();
			void push_back(T elemento);
			void pop_back();
			void insert(std::size_t pos, T elemento);
			void erase(std::size_t pos);
			utec::vector<T> operator+(const utec::vector<T>& other);
	};


}

#endif
