#ifndef ACTOR_H
#define ACTOR_H

#include"component.h"
#include"game.h"
#include"lib.h"

class Actor{
  public:
      enum State{
        EActive,
        Epaused,
        Edead
      };

  private:
      //Actor's state
      State mstate;
      //posicion
      Vector mPosition;
      //no entendi que chucha es esto
      float mScale;
      //angulo de rotacion
      float mRotation; //in radians
      //componentes del actor
      std::vector<class Component*> mComponents;
      //juego al que pertenece
      class Game* mGame;

  public:
      Actor(class Game* game);
      virtual ~Actor();

      void Update(float deltaTime);
      void UpdateComponents(float deltaTime);

      //Getters/Setters
      

      void AddComponent(class Component* component);
      void RemoveComponent(class Component* component);

};

#endif
