#include"function.h"

device dev;
float random_number(range low, range high){
  distribution dis(low, high);
  return dis(dev);
}

float jitter(int value, range low, range high){
  distribution dis(low, high);
  //srand (time(NULL));
  //int flag = rand() % 2;
 // if(flag)
    return value + dis(dev); 
  //return value - dis(dev);
}

int midpoint(int pos1, int pos2){
  return ((pos1+pos2)/2);
}

float average_2(float a, float b){
  return (a+b)/2.0;
}

float average_4(float a, float b, float c, float d){
  return (a+b+c+d)/4.0;
}
