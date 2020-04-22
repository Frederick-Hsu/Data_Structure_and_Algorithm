#include "CDummy.h"

#include <iostream>
using namespace std;

CDummy::CDummy()
{
}

CDummy::~CDummy()
{
}

CDummy::CDummy(const CDummy& orig)
{
}

void CDummy::work(int x)
{
    cout << "Inside the member function : CDummy::work(int) : x = " << x << endl;
}
