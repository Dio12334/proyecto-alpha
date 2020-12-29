#include "interprete.h"


Interpreter::Interpreter(fs::path dir):inGame(true),thisDir(dir){}
Interpreter::~Interpreter(){}

void Interpreter::init(){
    while(inGame){
        if(fs::is_empty(thisDir/"out"))continue;

        for(auto it: fs::directory_iterator(thisDir/"out")){
            readInst(it);
            fs::remove(it);
        }
    }
}


bool Interpreter::setTeam(name_t teamName,std::string fna){
    std::ofstream file(thisDir/"in"/fna);
    if(!file.is_open())return false;
    file<<ActionString(Action::HANDSHAKE)<<"="<<teamName;
    file.close();
    return true;
}

bool Interpreter::writeInst(Action inst,pos_t coord,std::string fna){
    if(!theToken.size())return false;
    std::ofstream file(thisDir/"out"/fna);
    if(!file.is_open())return false;

    file<<FieldString(Field::TOKEN)<<"="<<theToken<<"\n";
    file<<ActionString(inst)<<"="<<coord;
}

Content Interpreter::readInst(fs::path p){
    Content resp;

    std::ifstream file(p);
    if(!file.is_open())return resp;

    std::string line;
    std::vector<std::string>command;

    while(std::getline(file,line)){
        std::cout<<line<<"\n";
        command=splitString(line);
        for(auto it: command)
            std::cout<<it<<"\n";

        
        if(command.size()==2){
            switch(FieldKey(command[0])){
                //case Field::ACTION:resp.action=ActionKey(command[1]);break;ACTION is never sended in this format
                case Field::MESSAGE: resp.message=MessageKey(command[1]);break;
                case Field::STATUS: resp.status=StatusKey(command[1]);break;
                case Field::SCOPE: resp.scope=theScope.size()?theScope:command[1];break;
                case Field::TOKEN: resp.token=theToken.size()?theToken:command[1];break;
                case Field::NULLFIELD: std::cout<<"Bad format: "<<FieldString(Field::NULLFIELD)<<"\n";break;
            }
        }else if(command.size()==1){//only the action field can be here
            resp.action=ActionKey(command[0]);
        }else{
            std::cout<<"Bad format: no meaningful line\n";
            continue;
        }
    }
    theToken=resp.token;
    theScope=resp.scope;

    return resp;
}
