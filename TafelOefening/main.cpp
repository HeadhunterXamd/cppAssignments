#include "session.h"

int main(int argc, char *argv[])
{
	// create a new session, this will start the sequence
    Session s(1);

    s.start_session();

    return 0;
}


