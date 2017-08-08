#include <fstream>
#include <iostream>
#include <cstdio>
#include "SysClear.hpp"
#include "Question.hpp"

Question::Question(const std::string& filename){
    content = "";
    if(!loadFromFile(filename)){
        std::cerr<<"E: Can't open file: "<<filename;
        exit(-1);
    }
}

bool Question::ask(){
    clear();
    while(1){
        std::cout<<content<<"\n";
        char answer;
        std::cin>>answer;
        if(!std::cin.good()){
            std::cin.clear();
            std::cin.sync();
            clear();
            std::cout<<"\n E: Not valid input \n";
            continue;
        }
        if(answer==rightAnswer){
            clear();
            std::cout<<"Correct! \n";
            return true;
        }
        if((answer-32)==rightAnswer){
            clear();
            std::cout<<"Correct! \n";
            return true;
        }
        break;
    }
    clear();
    std::cout<<"Wrong! \n";
    return false;
}

bool Question::loadFromFile(const std::string& filename){
    std::ifstream file(filename.c_str());
    if(!file.is_open()) return false;
    std::string buffer;
    while(!file.eof()){
        getline(file, buffer);
        if(buffer.compare("<start>")==0){
            while(1){
                getline(file, buffer);
                if(buffer.compare("<end>")==0) break;
                content+=buffer+"\n";
            }//while
        }
        if(buffer.compare("<answer>")==0){
            getline(file, buffer);
            const char* tmp = buffer.c_str();
            rightAnswer = tmp[0];
        }
    }//while
    return true;
}