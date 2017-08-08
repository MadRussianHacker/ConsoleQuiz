#ifndef CONSOLEQUIZ_QUIZ_HPP
#define CONSOLEQUIZ_QUIZ_HPP


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

    enum State{MENU, START, CREDITS, EXIT};
    State state;
};

#endif //CONSOLEQUIZ_QUIZ_HPP