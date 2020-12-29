#include<random>
#include<iostream>
template <typename T>
auto random(T first, T last) {
    std::random_device device;std::default_random_engine engine(device);
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> distribution(first, last);
        return distribution(engine);
    }
    else {
        std::uniform_real_distribution<T> distribution(first, last);
        return distribution(engine);
    }
}
int f1(int x, int cnt) {
    if (x <= 0){
        cnt = 1;
        return cnt;
    }
    else {

        auto i = random(0, x -1);

        return f1(i, cnt) + f1(x -1 -i, cnt);
    }
}

int main(){
  std::cout<<f1(10, 0)<<std::endl;
}
