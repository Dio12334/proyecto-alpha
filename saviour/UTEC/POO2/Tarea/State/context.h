#ifndef CONTEXT_H
#define CONTEXT_H

#include"state.h"

class Context{
  private:
      State *state;
  public:
      Context(State *state){
        this->state = state;
      }
      ~Context(){
        delete this->state;
      }
      void change_state(State* state){
        delete this->state;
        this->state = state;
      }
      void act(){
        this->state->do_this();
      }
};

#endif

