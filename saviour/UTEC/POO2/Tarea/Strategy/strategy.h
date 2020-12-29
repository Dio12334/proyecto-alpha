#ifndef STRATEGY_H
#define STRATEGY_H

#include<string>
#include<iostream>
class Strategy{
  public:
      virtual ~Strategy(){}
      virtual void Do_thing(float data) const = 0;

};
#endif
