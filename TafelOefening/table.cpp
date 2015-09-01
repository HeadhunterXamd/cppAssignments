#include "table.h"
#include <cstdlib>

Table::Table(int table_factor)
{
    this->initialized = true;
    for(int i = 0; i < amount_of_questions; i++){
        std::string question = "What is " + std::to_string(i+1) + " x " + std::to_string(table_factor) + " = ? \n" ;

        question_list.push_back(Question(question, (i+1)*table_factor));
    }
    this->completed = false;
}

Table::~Table()
{
}

Question Table::get_new_question(){
    return question_list[rand() % amount_of_questions];
}

bool Table::is_table_completed(){
    for(int question = 0; question < this->question_list.size(); question++){
        Question q = this->question_list[question];
        if(!q.completed){
            return false;
        }
    }
    return true;
}

bool Table::ask_question(){
    int user_answer;
    Question current_question = this->get_new_question();
    if(!current_question.question_completed()){
        std::cout << current_question.the_question;
        std::cin >> user_answer;
        if(current_question.check_answer(user_answer)){
            current_question.correct_guess();
            return true;
        }else{
            current_question.amount_guesses_right = 0;
            return false;
        }
    }else{
        if(!this->is_table_completed()){
            ask_question();
        }else{
            ask_question();
        }
    }

}
