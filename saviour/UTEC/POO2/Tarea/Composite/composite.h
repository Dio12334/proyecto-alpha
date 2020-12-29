#ifndef COMPOSITE_H
#define COMPOSITE_H

#include<vector>
#include"component.h"
#include"leaf.h"

class Gerente: public Component{
  private:
      std::string nombre;
      std::vector<Component*> children;
  public:
      Gerente(std::string name): nombre(name){}
      void add(Component* comp){
        children.emplace_back(comp);
      }
      void remove(Component *comp){
        for(auto i = children.begin(); i != children.end();i++)
          if(*i == comp){
            delete *i;
            return;
          }
      }
      void execute() const override{
       std::cout<<this->nombre<<" manager de"<<std::endl;
       for(auto i: children)
          i->execute();
      }

};

#endif
