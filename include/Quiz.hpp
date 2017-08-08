#ifndef CONSOLEQUIZ_QUIZ_HPP
#define CONSOLEQUIZ_QUIZ_HPP

#include <vector>

class Quiz
{
public:
    int run();
private:
    void runMenu();
    void credits();
    void start();

    int random(int from, int to);
    bool wasBefore(int x);
    enum Category{PROGRAMMING, NETWORKING, HARDWARE, SECUIRITY};
    int categoryChoice();

    enum State{MENU, START, CREDITS, EXIT};
    State state;

    std::vector<int> before;

    unsigned int points, maxPoints;
};

#endif //CONSOLEQUIZ_QUIZ_HPP