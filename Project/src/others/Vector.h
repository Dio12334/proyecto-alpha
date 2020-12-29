#ifndef VECTOR_H
#define VETCOR_H

#include<iostream>
#include<cmath>

typedef long double  valor; 

struct Vector{
      valor x;
      valor y;
      valor z;

      Vector(){
        x = y = z = 0;
      }

      Vector(valor x, valor y, valor z): x(x), y(y), z(z){}

      Vector(valor modulo, valor angulo){
          z = 0;
          y = sin(angulo);
          x = cos(angulo);
      }
     
      Vector(valor modulo, valor alfa, valor beta, valor gamma){
        x = modulo*cos(alfa);
        y = modulo*cos(beta);
        z = modulo*cos(gamma);
      }

      valor Modulo(){
          return std::sqrt((x*x)+(y*y)+(z*z));
      }

      Vector operator/(const valor& numero){
        return Vector(x/numero, y/numero, z/numero);
      }
      
      Vector operator*(const valor& numero){
        return Vector(x*numero, y*numero, z*numero);
      }

      valor operator*(const Vector& vec){
        return (vec.x * x)+ (vec.y*y) +(vec.z*z);
      }

      Vector producto_cruz(const Vector& vec){
        return Vector( ((y*vec.z)-(z*vec.y)), -((x*vec.z)-(z*vec.x)), ((x*vec.y)-(y*vec.x)));
      }
      
      Vector operator+(const Vector& vec){
        return Vector(x+vec.x, y+vec.y, z+vec.z);
      }

      Vector operator-(const Vector& vec){
        return Vector(x-vec.x, y-vec.y, z-vec.z);
      }

      void operator =(const Vector& vec){
        x = vec.x;
        y = vec.y;
        z = vec.z;
      }
      void operator +=(const Vector& vec){
        x = vec.x + x;
        y = vec.y + y;
        z = vec.z + z;
      }

      void operator -=(const Vector& vec){
        x = x - vec.x;
        y = y - vec.y;
        z = z - vec.z;

      }

      bool operator==(const Vector& vec){
        return x == vec.x && y == vec.y && z == vec.z;
      }

      bool son_paralelos(const Vector& vec){
        return vec.x/x == vec.y/y && vec.y/y == vec.z/z;
      }

      Vector unitario(){
        return *this /Modulo();
      }

      Vector proyeccion( Vector& vec){
        valor a = (*this) * vec;
        return vec.unitario() * a/vec.Modulo();
      }
      ~Vector(){}
      
};



std::ostream& operator <<(std::ostream& os, const Vector& vec){
         os<<"X: "<<vec.x<<" Y: "<<vec.y<<" Z: "<<vec.z<<" ";
         return os;
       }


#endif
