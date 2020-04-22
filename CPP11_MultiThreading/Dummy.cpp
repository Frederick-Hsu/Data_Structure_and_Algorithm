#include "Dummy.h"

#include <iostream>
using namespace std;

Dummy::Dummy() {}
Dummy::Dummy(const Dummy& other) {}
void Dummy::memberFnct(int x)
{
    cout << "Inside memberFnct: x = " << x << endl;
}