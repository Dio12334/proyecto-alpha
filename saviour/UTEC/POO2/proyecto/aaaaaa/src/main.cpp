#include "interprete.h"


int main(){
    /*
    fs::path current=fs::current_path();
    fs::path out=current/"out";
    fs::path in=current/"in";
    fs::create_directories(out);
    fs::create_directories(in);
    
    Filename infile("newFile","in");
    Filename outfile("newFile","out");

    for(size_t i=0;i<20;i++){
        std::ofstream pi(in/infile.inc());
        std::ofstream po(out/outfile.inc());

        pi<<i;
        po<<i;

        pi.close();
        po.close();
        std::cout<<*fs::begin(fs::directory_iterator(in))++<<"\n";
        std::cout<<*fs::begin(fs::directory_iterator(out))++<<"\n";
    }


    for(auto &it:fs::directory_iterator(in))
        std::cout<<it<<"\n";

    for(auto &it:fs::directory_iterator(out))
        std::cout<<it<<"\n";
    

    for(auto &it:fs::directory_iterator(in))
        fs::remove(it);

    for(auto &it:fs::directory_iterator(out))
        fs::remove(it);
    */
    Interpreter lector(fs::current_path());
    std::thread athread([lector]()mutable{lector.init();});
    std::thread bthread([lector]()mutable{lector.setTeam("gooo","FirstPlayer.in");});
    //creo q los threads son inecesarios v: 
    bthread.join();
    athread.join();

    return 0;
}

