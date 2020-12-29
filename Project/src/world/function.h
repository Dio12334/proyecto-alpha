#ifndef FUNCTION_H
#define FUNCTION_H

#include"../libs/lib.h"

typedef float range;
typedef float number;
typedef std::random_device device;
typedef std::uniform_real_distribution<range> distribution;

float random_number(range low, range high);

#endif
