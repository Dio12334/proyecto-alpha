#ifndef HASH_H
#define HASH_H

#include<list>

template<typename T>

class Hash_table{
	private:
					int tam;
					std::list<T> *table;
					void Hash(T element);

	public:
					Hash_table(int tamano);
					void insert(T element);
					void remove(T element);
					bool search(T elememt);

};

#endif
