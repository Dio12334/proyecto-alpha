#ifndef TYPES_H
#define TYPES_H

#include "lib.h"

namespace fs = std::experimental::filesystem;

typedef std::string pos_t;
typedef std::string name_t;
typedef std::string token_t;
typedef std::string scope_t;
typedef char myKey_t;

enum Field:myKey_t{
    NULLFIELD=-1,STATUS,ACTION,MESSAGE,SCOPE,TOKEN
};

enum Status:myKey_t{
    NULLSTATUS=-1,ACCEPTED,REJECTED
};

enum Action:myKey_t{
    NULLACTION=-1,HANDSHAKE,PLACEFLEET,ATTACK
};

enum Message:myKey_t{
    //PLACEFLEET MESSAGES
    NULLMESSAGE=-1,CONTINUE,COMPLETED,FULL,BUSY,OUTSIDE,
    //ATTACK MESSAGES
    FAILED,DAMAGED,DESTROYED,GAMEOVER,WINNER
};

//maping the enums from its values to string and viceversa
static std::unordered_map<Field,std::string> getFieldString={
    {Field::ACTION,"ACTION"},
    {Field::MESSAGE,"MESSAGE"},
    {Field::SCOPE,"SCOPE"},
    {Field::STATUS,"STATUS"},
    {Field::TOKEN,"TOKEN"}
};

static std::unordered_map<std::string,Field> getFieldKey={
    {"ACTION",Field::ACTION},
    {"MESSAGE",Field::MESSAGE},
    {"SCOPE",Field::SCOPE},
    {"STATUS",Field::STATUS},
    {"TOKEN",Field::TOKEN}
};

static std::unordered_map<Status,std::string> getStatusString={
    {Status::ACCEPTED,"ACCEPTED"},
    {Status::REJECTED,"REJECTED"}
};

static std::unordered_map<Action,std::string> getActionString={
    {Action::ATTACK,"ATTACK"},
    {Action::HANDSHAKE,"HANDSHAKE"},
    {Action::PLACEFLEET,"PLACEFLEET"}
};

static std::unordered_map<Message,std::string> getMessageString={
    {Message::BUSY,"BUSY"},
    {Message::COMPLETED,"COMPLETED"},
    {Message::CONTINUE,"CONTINUE"},
    {Message::DAMAGED,"DAMAGED"},
    {Message::DESTROYED,"DESTROYED"},
    {Message::FAILED,"FAILED"},
    {Message::FULL,"FULL"},
    {Message::GAMEOVER,"GAMEOVER"},
    {Message::OUTSIDE,"OUTSIDE"},
    {Message::WINNER,"WINNER"}
};


static std::unordered_map<std::string,Status> getStatusKey={
    {"ACCEPTED",Status::ACCEPTED},
    {"REJECTED",Status::REJECTED}
};

static std::unordered_map<std::string,Action> getActionKey={
    {"ATTACK",Action::ATTACK},
    {"HANDSHAKE",Action::HANDSHAKE},
    {"PLACEFLEET",Action::PLACEFLEET}
};

static std::unordered_map<std::string,Message> getMessageKey={
    {"BUSY",Message::BUSY},
    {"COMPLETED",Message::COMPLETED},
    {"CONTINUE",Message::CONTINUE},
    {"DAMAGED",Message::DAMAGED},
    {"DESTROYED",Message::DESTROYED},
    {"FAILED",Message::FAILED},
    {"FULL",Message::FULL},
    {"GAMEOVER",Message::GAMEOVER},
    {"OUTSIDE",Message::OUTSIDE},
    {"WINNER",Message::WINNER}
};
//end of maping

//auxiliar functions v: 
static std::vector<std::string> splitString(std::string str,char del='='){
    std::vector<std::string> vec;                                    
    std::stringstream input(str);                               
    std::string token;                                          
    while(getline(input,token,del))                    
        vec.push_back(token);                          
                                                           
    return vec;                                            
}                                                          

static Field FieldKey(std::string m){
    return getFieldKey.find(m)==getFieldKey.end()?Field::NULLFIELD : getFieldKey[m];
}

static Message MessageKey(std::string m){
    return getMessageKey.find(m)==getMessageKey.end()?Message::NULLMESSAGE : getMessageKey[m];
}

static Status StatusKey(std::string m){
    return getStatusKey.find(m)==getStatusKey.end()?Status::NULLSTATUS : getStatusKey[m];
}
static Action ActionKey(std::string m){
    return getActionKey.find(m)==getActionKey.end()?Action::NULLACTION : getActionKey[m];
}

//=================================================

static std::string FieldString(Field k){
    return getFieldString.find(k)==getFieldString.end()?"NULLFIELD" : getFieldString[k];
}

static std::string MessageString(Message k){
    return getMessageString.find(k)==getMessageString.end()?"NULLMESSAGE" : getMessageString[k];
}

static std::string StatusString(Status k){
    return getStatusString.find(k)==getStatusString.end()?"NULLSTATUS" : getStatusString[k];
}

static std::string ActionString(Action k){
    return getActionString.find(k)==getActionString.end()?"NULLACTION" : getActionString[k];
}
//end of functions


//maybe useful structs
//end of structs

#endif
