#ifndef TABLE_H
#define TABLE_H
#include "question.h"
#include <vector>

#define amount_of_questions 2

class Table
{
public:
    Table():initialized(false){}
    Table(int table_factor);
    ~Table();
    std::vector<Question> question_list;
    bool initialized;
    Question get_new_question();
    bool ask_question();
    bool is_table_completed();
    bool completed;
};

#endif // CLASSTABLE_H
