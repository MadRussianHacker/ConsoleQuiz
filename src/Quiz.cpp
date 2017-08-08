#include <iostream>
#include "Quiz.hpp"

int Quiz::run(){
    state = MENU;
    runMenu();
    return 0;
}

void Quiz::runMenu(){
    clear();
    std::string errMsg="";
    int option;
    while(state==MENU){
        std::cout<<"\n IT CONSOLE QUIZ by MadRussianHacker \n";
        std::cout<<"-=-===-=-===-=-===-=-===-=-===-=-===-=- \n";
        std::cout<<"\n\n";
        std::cout<<"[1] START \n";
        std::cout<<"[2] CREDITS \n";
        std::cout<<"[3] EXIT \n";
        std::cout<<"\n"<<errMsg<<"\n\n";
        
        std::cin>>option;
        if(!std::cin.good()){
            errMsg="E: Not valid input";
            std::cin.clear();
            std::cin.sync();
            clear();
            continue;
        }
        switch(option)
        {
            case 1: errMsg="1"; break;
            case 2: errMsg="2"; break;
            case 3: state=EXIT; break;
            default: errMsg="E: Not valid number"; break;
        }
        std::cin.clear();
        std::cin.sync();
        clear();
    }
}

void Quiz::clear(){
    system(SYS_CLEAR_COMMAND);
}