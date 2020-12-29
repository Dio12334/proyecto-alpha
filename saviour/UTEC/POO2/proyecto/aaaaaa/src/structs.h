#ifndef STRUCTS_H
#define STRUCTS_H

#include "types.h"

struct Content{
    Action action=Action::NULLACTION;
    Status status=Status::NULLSTATUS;
    Message message=Message::NULLMESSAGE;
    token_t token;
    scope_t scope="J-10";
};
struct Filename{
    size_t n=0;
    std::string name;
    std::string ext;

    std::string getName(){return name+"."+ext;}
    std::string inc(){return name+std::to_string(n++)+"."+ext;}
    Filename(std::string na,std::string ex):name(na), ext(ex){}
};

#endif
