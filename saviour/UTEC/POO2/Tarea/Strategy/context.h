#ifndef CONTEXT_H
#define CONTEXT_H

#include"strategy.h"

class Context{
  private:
      Strategy *strategy;
  public:
      Context(){
        strategy = nullptr;
      }
      Context(Strategy *strategy){
        this->strategy = strategy;
      }
      ~Context(){
        delete this->strategy;
      }
      void set_strategy(Strategy* strategy){
        delete this->strategy;
        this->strategy= strategy;
      }
      void dosomething(float data){
        this->strategy->Do_thing(data);
      }


};

#endif
