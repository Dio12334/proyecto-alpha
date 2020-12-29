#include"composite.h"

int main(){
  
  Gerente *general = new Gerente("Juan");
  general->add(new Empleado("jose"));
  Gerente *finanzas = new Gerente("Gabriel");
  general->add(finanzas);
  finanzas->add(new Empleado("jojo"));
  general->execute();

  return 0;
}
