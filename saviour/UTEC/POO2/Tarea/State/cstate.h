#ifndef CSTATE_H
#define CSTATE_H

#include"state.h"
#include<iostream>

class Ataque: public State{
  public:
      void do_this() const override{
          std::cout<<"atacó"<<std::endl; 
      }
};

class Moverse: public State{
  public:
      void do_this() const override{
          std::cout<<"se movió"<<std::endl;
      }
};

class Defender: public State{
  public:
      void do_this() const override{
          std::cout<<"se defendió"<<std::endl;
      }
};



#endif
