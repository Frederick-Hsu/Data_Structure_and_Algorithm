#include <QCoreApplication>
#include "QShared_Ptr.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QShared_Ptr<int> my_smart_ptr(new int(5));

    return a.exec();
}
