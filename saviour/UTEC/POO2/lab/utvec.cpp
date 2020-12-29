#include"utvec.h"

template<typename T>

utec::vector<T>::vector(){
	capacity = 1;
	vec = new T[capacity];
	tamano = 0;
}

template<typename T>

utec::vector<T>::vector(utec::vector<T>& other){
	capacity = other.capacity;
	tamano = other.tamano;
	vec = new T[capacity];
	for(auto i = 0; i < capacity; i++){
		*(vec +i) = other.*(vec + i);
	}
}

template<typename T>

utec::vector<T> utec::vector<T>::operator=(utec::vector<T>& other){
        capacity = other.capacity;
	vec = new T[capacity];
        for(auto i = 0; i < capacity; i++){
                *(vec + i) = other.*(vec + i);
        }
}

template<typename T>

utec::vector<T>::vector(std::size_t tam){
	capacity = tam;
	tamano = 0;
	vec = new T[capacity];

}

template<typename T>

utec::vector<T>::~vector(){
	tamano = 0;
	capacity = 0;
	delete [] vec;
}

template<typename T>

void utec::vector<T>::push_back(T elemento){
	if (tamano + 1 >= capacity){
        	capacity *= 2;
        	T * aux = new T[capacity];
        	for (auto i = 0; i < tamano; i++)
            		aux[i] = vec[i];
        	delete [] vec;
        	vec = aux;    
    	}
    	tamano++;
}

template<typename T>

void utec::vector<T>::pop_back(){
	
	if (tamano - 1 <= capacity / 4){
		capacity /= 2;
		T * aux = new T[capacity];
		for (auto i = 0; i < tamano - 1; ++i)
			aux[i] = vec[i];
		delete [] vec;
		vec = aux;	
	}
	tamano--;
	if (tamano == 0)
                return;

}

template<typename T>

void utec::vector<T>::insert(std::size_t pos, T elemento){
	if (tamano + 1 > capacity)
		capacity *= 2;
	T *aux = new T[capacity];
	for(auto i = 0; i != pos; i++){
		*(aux + i) = *(vec + i);
	}
	*(aux + pos) = elemento;
	for(auto i = pos; i < tamano; i++){
		*(aux + i + 1) = *(vec +i);
	}
	delete [] vec;
	vec = aux;
	tamano++;
}

template<typename T>

void utec::vector<T>::erase(std::size_t pos){
	if (pos > tamano || pos < 0 || tamano == 0)
		return ;
	T* aux = new T[capacity];
	std::size_t j = 0, i = 0;
	while (i < pos)
		aux[j++] = vec[i++];
	i++;
	while (i < tamano)
		aux[j++] = vec[i++];
	delete [] vec;
	vec = aux;
	--tamano;
}

template<typename T>

utec::vector<T> utec::vector<T>::operator+(const utec::vector<T>& other){

	utec::vector<T> temp(capacity + other.capacity);
	for(auto i = 0; i < tamano; i++){
		temp.push_back(*(vec + i));
	}
	for(auto i = 0; i < other.tamano; i++){
                temp.push_back(other.*(vec + i));
        }

	return temp;
}

