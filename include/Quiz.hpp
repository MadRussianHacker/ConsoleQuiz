#ifndef CONSOLEQUIZ_QUIZ_HPP
#define CONSOLEQUIZ_QUIZ_HPP

#if defined( _WIN32 ) || defined( _WIN64 )
    #include <windows.h>
    #define SYS_CLEAR_COMMAND "cls"
#else
    #include <cstdio>
    #define SYS_CLEAR_COMMAND "clear"
#endif

class Quiz
{
public:
    int run();
private:
    void runMenu();
    void clear();
    enum State{MENU, CATEGORY_CHOICE, START, CREDITS, EXIT};
    enum Category{PROGRAMMING, NETWORKING, HARDWARE, SECUIRITY};
    State state;
    Category category;
};

#endif //CONSOLEQUIZ_QUIZ_HPP