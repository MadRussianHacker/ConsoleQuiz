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
    void credits();
    void start();

    enum Category{PROGRAMMING, NETWORKING, HARDWARE, SECUIRITY};
    int categoryChoice();

    void clear();

    enum State{MENU, START, CREDITS, EXIT};
    State state;
};

#endif //CONSOLEQUIZ_QUIZ_HPP