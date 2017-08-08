#ifndef CONSOLEQUIZ_QUIZ_HPP
#define CONSOLEQUIZ_QUIZ_HPP

#include <vector>
#include <string>

class Quiz
{
public:
    int run();
private:
    void runMenu();
    void credits();
    void start();

    int random(int from, int to);
    void askQuestions(int questionCount, const std::string& path);
    void judgeResults();
    bool wasBefore(int x);
    enum Category{PROGRAMMING, NETWORKING, HARDWARE, SECUIRITY};
    int categoryChoice();

    enum State{MENU, START, CREDITS, EXIT};
    State state;

    std::vector<int> before;

    unsigned int points, maxPoints;
};

#endif //CONSOLEQUIZ_QUIZ_HPP