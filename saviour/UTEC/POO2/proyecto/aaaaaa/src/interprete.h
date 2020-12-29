#ifndef INTERPRETE_H
#define INTERPRETE_H

#include "structs.h"

class Interpreter{
    bool inGame;
    token_t theToken="";
    scope_t theScope="";
    fs::path thisDir;
    //IA_t* ia;
    
    fs::path checkLast();

public:
    Interpreter(fs::path);
    ~Interpreter();

    void init();
    bool setTeam(name_t teamName,std::string fna);
    bool writeInst(Action inst,pos_t coord,std::string fna);
    Content readInst(fs::path p);

};

#endif
