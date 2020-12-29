#include<iostream>
#include<cmath>

template<typename T, class ... Args>
double promedio(T m, Args const&... args){
        int numArgs = sizeof...(args)+1;

        if (numArgs == 0)
            return 0;

        float total=0;
        for (auto value : {args...})
        {
            total += value;

        }
        total += m;
        total= total/numArgs;
        return total;
}

template <typename T, class ... Args>

double coso_de_arriba( T& first, Args& ... args, double& prom, int& numArgs){

  if( numArgs == 0) return 0;

  return pow(first-prom, 2) + coso_de_arriba(args..., prom, numArgs-1);
}

template <typename T, class ... Args>

double standard_deviation(T first, Args... args){
  double prom = promedio(first, args...);
  int numArgs = sizeof...(args)+1;
  if(numArgs == 0) return 0;
  return sqrt(coso_de_arriba(args..., prom, numArgs)/numArgs);
}

int main(){

  std::cout<< standard_deviation(1, 3, 4, 1, 20)<<std::endl;
  return 0;
}
