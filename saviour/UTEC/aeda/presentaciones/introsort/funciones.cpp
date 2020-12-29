#include"funciones.h"


//" funciones array {{{1
void add_elements(int arr[], int n){
  srand(time(NULL));

  for(int i = 0; i < n; i++){
    arr[i] = (rand()%100) + 1;
  }
}

void print_arr(int arr[], int n){
  for(int i = 0; i < n; i++)
      std::cout<<arr[i]<<" ";
  std::cout<<std::endl;
}
// " partition {{{1
int* partition(int arr[], int low, int high){
  int pivot = arr[high];
  int i = (low - 1);

  for(int j = low; j <= high - 1; j++){
    if(arr[j] <= pivot){
      i++;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i+1], arr[high]);
  return (arr + i + 1);
}

// " heapsort {{{1
void heapify(int arr[], int n, int i){
  int largest = i;
  int l = 2*i + i;
  int r = 2*i + 2;
  if(l < n && arr[l] > arr[largest])
      largest = l;
  if(r < n && arr[r] > arr[largest])
      largest = r;
  if(largest != i){
    std::swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}


void heapsort(int arr[], int tamanio){
  for(int i = tamanio/2 - 1; i >= 0; i--)
    heapify(arr, tamanio, i);
  for(int i = tamanio-1; i >0; i--){
      std::swap(arr[0], arr[1]);
      heapify(arr, i , 0);
  }  
}
// " media of three {{{1
int* median_of_three(int* a, int* b, int* c){
  if(*a <*b && *b < *c)
    return (b);
  if(*a <*c && *c <= *b)
    return (c);
  if(*b <= *a && *a < *c)
    return (a);
  if(*b <*c && *c <= *a)
    return (c);
  if(*c <=*a && *a < *b)
    return (a);  
  if(*c <=*b && *b <= *a)
    return (b);
  
} 
// " insertion sort {{{1
void insertionsort(int arr[], int *begin, int *end) { 
    
    int left = begin - arr; 
    int right = end - arr; 
  
    for (int i = left+1; i <= right; i++) 
    { 
        int key = arr[i]; 
        int j = i-1; 
  
        while (j >= left && arr[j] > key) 
        { 
            arr[j+1] = arr[j]; 
            j = j-1; 
        } 
        arr[j+1] = key; 
   } 
  
   return; 
}

// " swapvalue {{{1
void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}
// " introsort  {{{1
void rec_introsort(int arr[],int* comienzo, int* fin, int limite_de_profundidad){

  int tamanio = fin-comienzo;
  //std::cout<<"profundidad: "<<limite_de_profundidad<<std::endl;
  if(tamanio < 16){
      insertionsort(arr, comienzo, fin);
      //std::cout<<"se hace insertion:"<<std::endl;
      //print_arr(arr,tamanio);
      return ;
  }
  else if(limite_de_profundidad == 0){
      heapsort(arr, tamanio);
      //std::cout<<"se hace heapsort:"<<std::endl;
      //print_arr(arr, tamanio);
      return;
  }
  else{
      int* pivot = median_of_three(comienzo, comienzo + tamanio/2, fin);
      swapValue(pivot, fin);
      int* p = partition(arr, comienzo-arr, fin-arr );
      rec_introsort(arr, comienzo, p-1, limite_de_profundidad - 1);
      rec_introsort(arr, p+1, fin, limite_de_profundidad - 1);
      //std::cout<<"se hace quicksort:"<<std::endl;
      //print_arr(arr,tamanio); 
  }
}

void introsort(int arr[], int* comienzo, int* fin){

  int limite_de_profundidad = 2 * log(fin-comienzo);
  //std::cout<<limite_de_profundidad<<std::endl;
  rec_introsort(arr,comienzo, fin, limite_de_profundidad);
}
