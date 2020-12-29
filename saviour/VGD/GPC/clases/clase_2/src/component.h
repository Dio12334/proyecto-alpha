#ifndef COMPONENT_H
#define COMPONENT_H

#include"actor.h"

class Component{
  protected:
      //Actor al que pertenece
      class Actor* mOwner;
      //Orden de update del componente
      int mUpdateOrder;
  public:
      // miwntras menor el update ordrder, más temprano se updatea el esto
      Component(Actor* owner, int updateorder = 100);
      virtual ~Component();
      //updetea el componente en deltaTime
      virtual void Update(float deltaTime);
      int GetUpdateOrder() const {return mUpdateOrder;}
};

#endif
