#include"Vector.h"

int main(){
  Vector AB(233, 45, 98);
  Vector BC = AB;
  std::cout<<BC<<std::endl;
  std::cout<<"unitario: "<<BC.unitario()<<"\n";
  std::cout<<"AB + BC: "<<AB + BC<<std::endl;
  AB += BC;
  BC = Vector(0, 0, 6);
  AB = Vector(6, 0, 0);
  std::cout<<"Proyeccion AB a BC: "<< AB.proyeccion(BC)<<std::endl;
  return 0;
}
