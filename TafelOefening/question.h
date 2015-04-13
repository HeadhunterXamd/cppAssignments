#ifndef QUESTION_H
#define QUESTION_H
#include<iostream>
#include <vector>

class Question
{
public:
    Question( std::string the_question, int answer);
    ~Question();
    bool question_completed();
    std::string the_question;
    int answer;
    int amount_guesses_right;
    bool check_answer(int user_answer);
    void correct_guess();
    bool completed;

};

#endif // QUESTION_H
