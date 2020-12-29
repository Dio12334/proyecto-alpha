#include<iostream>
#include"funciones.h"

int main(){
  
  int arr[30];
  add_elements(arr, 30);

  std::cout<<"Antes del Introsort: "<<std::endl;
  print_arr(arr, 30);

  introsort(arr, arr, arr+30-1);
  std::cout<<"Despues del Introsort: "<<std::endl;
  print_arr(arr, 30);

  return 0;
}
