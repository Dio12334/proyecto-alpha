#ifndef STRATEGIAS_H
#define STRATEGIAS_H

#include"strategy.h"

class Dolar: public Strategy{
  public:
      void Do_thing(float data) const override{
        std::cout<<data/3.35<<std::endl;
      }
};

class Euro: public Strategy{
  public:
      void Do_thing(float data) const override{
        std::cout<<data/4.12<<std::endl;
      }
};

class Yen: public Strategy{
  public:
      void Do_thing(float data) const override{
        std::cout<<data/0.033<<std::endl;
      }
};

class Bolivar: public Strategy{
  public:
      void Do_thing(float data) const override{
        std::cout<<data/0.000015<<std::endl;
      }
};

#endif
