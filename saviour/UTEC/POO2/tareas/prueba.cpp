#include<iostream>
#include<algorithm>

int main(){
	int tam;
	std::cin>> tam;
	int arr[tam], el = 0, cnt = 0;

	while(std::cin>> el){
		arr[cnt] = el;
		cnt++;
	}
	std::sort(*arr, *(arr+tam-1));
	

}
