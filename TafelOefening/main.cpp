#include <QCoreApplication>
#include "session.h"





int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Session s(1);

    s.start_session();

    return a.exec();
}


