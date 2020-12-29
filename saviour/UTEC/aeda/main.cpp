#include<iostream>
#include<vector>
template<template<typename ...>class Container,typename T, typename ...Types>

Container<T> filter(Container<T> cont, Types ...args){
  std::vector<T> VEC(cont.cbegin(), cont.cend());
  std::vector<T> vec2;
  for(auto value: {args...}){
    vec2.emplace_back(VEC[value]);
  }
	Container<T> cnt(vec2.cbegin(), vec2.cend());
	return cnt;
}

int main(){

std::vector vec = {1, 3, 4, 5, 6, 7};
auto r1 = filter(vec, 5, 2, 4);

for(auto val: r1){
  std::cout<<val<<" ";
}

return 0;
}
