#include "session.h"
#include <cstdlib>
#include <time.h>

int max_number_of_random_table_gen = 0;

//#ifdef WIN32
//#include <windows.h>
//#else
#include <unistd.h>
//#endif

void portableSleep(int sec) {
//#ifdef WINDOWS
//        Sleep(sec * 1000);
//#else
        sleep(sec);
//#endif
}


Session::Session(){

    for(int factor = 1; factor < 11; factor++){
        this->table_list.push_back(Table(factor));
    }
}

Session::Session(int tables_range_begin){

    for(int factor = tables_range_begin; factor < (tables_range_begin+amount_of_questions); factor++){
        this->table_list.push_back(Table(factor));
    }
}

Session::~Session(){

}

Table Session::next_table(){
    srand(time(NULL));
    Table table = this->table_list[rand() % amount_of_questions];
    if(!table.is_table_completed()){
        max_number_of_random_table_gen = 0;
        return table;
    }else{
        if(max_number_of_random_table_gen < 5){
            return this->next_table();
            max_number_of_random_table_gen++;
        }else{
            max_number_of_random_table_gen = 0;
        }
    }
}


bool Session::completed_session(){
    for(int table_index = 0; table_index < this->table_list.size(); table_index++){
        Table table = this->table_list[table_index];
        if(!table.is_table_completed()){
            return 0;
        }
    }
    return 1;
}

void Session::start_session(){
    while(this->completed_session() == 0){
        Table current_table = this->next_table();
        if(current_table.initialized){
            if(!current_table.is_table_completed()){
                if(current_table.ask_question()){
                    std::cout << "Correct, next question!" << std::endl;
                    portableSleep(1);
    //#ifdef Q_OS_OSX
                    std::cout << "\x1B[2J\x1B[H";
    //#else
    //                system("cls");
    //#endif
                }else{
                    std::cout << "Wrong, try better next time" << std::endl;
                    portableSleep(1);
    //#ifdef Q_OS_OSX
                    std::cout << "\x1B[2J\x1B[H";
    //#else
    //                system("cls");
    //#endif
                }

            }
            if(this->completed_session()== 1){
               std::cout << "Good job, you have completed the exercise";
               portableSleep(1);
               break;
            }
        }
    }
}
