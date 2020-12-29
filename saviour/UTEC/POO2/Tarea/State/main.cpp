#include"context.h"
#include"cstate.h"

int main(){

  std::cout<<"Acciones del enemigo según el estado"<<std::endl;
  Context *enemigo = new Context(new Moverse);
  enemigo->act();
  enemigo->change_state(new Ataque);
  enemigo->act();  
  enemigo->change_state(new Defender);
  enemigo->act();
  return 0;
}
