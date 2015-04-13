#include "question.h"

Question::Question(std::string the_question, int answer)
{
    this->the_question = the_question;
    this->answer = answer;
    this->amount_guesses_right = 0;
}


Question::~Question()
{
    //delete *this;
}


bool Question::question_completed(){
    if(amount_guesses_right){
        return true;
    }
    return false;
}


void Question::correct_guess(){
    if(this->amount_guesses_right < 3){
        this->amount_guesses_right++;
    }
}


bool Question::check_answer(int user_answer){
    return (user_answer == this->answer);
}
