#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "SysClear.hpp"
#include "Question.hpp"
#include "Quiz.hpp"

int Quiz::run(){
    srand(time(NULL));
    state = MENU;
    points = 0;
    maxPoints = 10;
    before.push_back(0);
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
    if(category==PROGRAMMING) askQuestions(10, "questions/programming/");
    if(category==NETWORKING) askQuestions(10, "questions/networking/");
    if(category==HARDWARE) askQuestions(10, "questions/hardware/");
    if(category==SECURITY) askQuestions(10, "questions/security");
    clear();
    judgeResults();
    std::cout<<"Points: "<<points<<"/"<<maxPoints<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));
    state = MENU;
}

void Quiz::askQuestions(int questionCount, const std::string& path){
    for(int i=0; i<10; ++i){
        int num = 0;
        while(wasBefore(num)) num = random(1, questionCount);
        before.push_back(num);
        std::string questionNumber = std::to_string(num);
        Question question(path+"q"+questionNumber+".txt");
        if(question.ask()) ++points;
        std::cout<<"Points: "<<points<<"/"<<maxPoints<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Quiz::judgeResults(){
    if(points==10) std::cout<<"You're the best!  :D \n";
    if(points==0) std::cout<<"Ohh.. maybe another time :( \n";
    if(points==5) std::cout<<"Not bad, not good :| \n";
    if(points!=10){
        if(points>5) std::cout<<"Not bad ;) \n";
    }
    if(points<5) std::cout<<"Try to do it better :/ \n";
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
    std::cout<<"\n\t Copyright 2017 by Michal Gibas \n (\"MadRussianHacker\") \n";
    std::cout<<"\t\t All rights reseved. \n\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    state = MENU;
    clear();
}

int Quiz::random(int from, int to){
    return (std::rand()%to)+from;
}

bool Quiz::wasBefore(int x){
    for(unsigned int i=0; i<before.size(); ++i)
        if(before[i]==x) return true;
    return false;
}