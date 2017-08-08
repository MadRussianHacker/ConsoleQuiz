#include <iostream>
#include <thread>
#include "SysClear.hpp"
#include "Question.hpp"
#include "Quiz.hpp"

int Quiz::run(){
    state = MENU;
    while(1){
        switch(state)
        {
            case MENU: runMenu(); break;
            case EXIT: clear(); return 0; break;
            case START: start(); return 0; break;
            case CREDITS: credits(); break;
        }
    }
    return 0;
}

void Quiz::start(){
    int category = categoryChoice();
    if(category==PROGRAMMING){
        Question q("questions/programming/q1.txt");
        q.ask();
    }
    state = EXIT;
}

int Quiz::categoryChoice(){
    clear();
    std::string errMsg="";
    int option;
    while(1)
    {
        std::cout<<"\n Choose category: \n";
        std::cout<<"\n [1] PROGRAMMING  \n";
        std::cout<<" [2] NETWORKING \n";
        std::cout<<" [3] HARDWARE \n";
        std::cout<<" [4] SECUIRITY \n\n";
        std::cout<<"\n"<<errMsg<<"\n";
        std::cin>>option;
        if( (!std::cin.good()) || ((option>4)||(option<1)) ){
            errMsg="E: Not valid input";
            std::cin.clear();
            std::cin.sync();
            clear();
            continue;
        }
        std::cin.clear();
        std::cin.sync();
        clear();
        break;
    }
    return option-1;
}

void Quiz::runMenu(){
    clear();
    std::string errMsg="";
    int option;
    while(state==MENU){
        std::cout<<"\n           IT CONSOLE QUIZ            \n";
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
            case 1: state=START; break;
            case 2: state=CREDITS; break;
            case 3: state=EXIT; break;
            default: errMsg="E: Not valid number"; break;
        }
        std::cin.clear();
        std::cin.sync();
        clear();
    }
}

void Quiz::credits(){
    clear();
    std::cout<<"\n\t Copyright 2017 by Michal Gibas (\"MadRussianHacker\") \n";
    std::cout<<"\t\t All rights reseved. \n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    state = MENU;
    clear();
}