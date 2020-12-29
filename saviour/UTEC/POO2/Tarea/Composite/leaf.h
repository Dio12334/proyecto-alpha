#ifndef LEAF_H
#define LEAF_H

#include<string>
#include"component.h"
#include<iostream>

class Empleado: public Component{
  private:
      std::string nombre;
  public:
      Empleado(std::string name): nombre(name){}
      void execute() const override{
        std::cout<<this->nombre<<": empleado"<<std::endl;
      }
};

#endif
