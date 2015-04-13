#ifndef SESSION_H
#define SESSION_H
#include "table.h"

class Session
{
public:
    Session();
    Session(int tables_range_begin);
    ~Session();

    std::vector<Table> table_list;
    Table next_table();
    void start_session();
    bool completed_session();
};

#endif // SESSION_H
