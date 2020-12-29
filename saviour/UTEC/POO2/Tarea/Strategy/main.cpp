#include"context.h"
#include"strategias.h"

int main(){


  //CLIENTEEE

    std::cout<<"70 soles a Dolares"<<std::endl;
    Context *cambio_dinero = new Context(new Dolar);
    cambio_dinero->dosomething(70);
    std::cout<<"70 soles a Yenes"<<std::endl;
    cambio_dinero->set_strategy(new Yen);
    cambio_dinero->dosomething(70);
    std::cout<<"70 soles a Euros"<<std::endl;
    cambio_dinero->set_strategy(new Euro);
    cambio_dinero->dosomething(70);
    std::cout<<"70 soles a Bolivares"<<std::endl;
    cambio_dinero->set_strategy(new Bolivar);
    cambio_dinero->dosomething(70);
    
  return 0;
}
