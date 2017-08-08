#ifndef CONSOLEQUIZ_QUESTION_HPP
#define CONSOLEQUIZ_QUESTION_HPP

#include <string>

class Question
{
public:
    Question(const std::string& filename);
    bool ask();
private:
    bool loadFromFile(const std::string& filename);
    std::string content;
    char rightAnswer;
};

#endif //CONSOLEQUIZ_QUESTION_HPP