#include "iterators.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

void reversely_access_elements_from_container()
{
    srand(time(0));
    vector<int> vec;
    for (vector<int>::size_type index = 0; index != 20; ++index)
    {
        vec.push_back(rand() % 500);
    }
    cout << "This vector is shown as below: " << endl;
    for (vector<int>::size_type pos = 0; pos != 20; ++pos)
    {
        cout << vec[pos] << " ";
    }
    cout << "\n" << endl;

    cout << "Display the vector in reverse order: " << endl;
    for (vector<int>::reverse_iterator riter = vec.rbegin(); riter != vec.rend(); ++riter)
    {
        cout << *riter << " ";
    }
    cout << "\n" << endl;
#if 0
    cout << "sort the vector in 'normal' order: " << endl;
    sort(vec.begin(), vec.end());
    for (vector<int>::size_type pos = 0; pos != 20; ++pos)
    {
        cout << vec[pos] << " ";
    }
    cout << "\n" << endl;
#else
    cout << "sort the vector in reverse order: puts smallest element at the end of vec:" << endl;
    sort(vec.rbegin(), vec.rend());
    for (vector<int>::size_type pos = 0; pos != 20; ++pos)
    {
        cout << vec[pos] << " ";
    }
    cout << "\n" << endl;
#endif
}

void access_element_by_reverse_iterator()
{
    string line;    /* a word list delimitered by comma */
    getline(cin, line);
    /* find first element in a comma-separated list*/
    string::iterator comma = find(line.begin(), line.end(), ',');
    cout << string(line.begin(), comma) << endl;

    /* find last element in a comma-separated list */
    string::reverse_iterator rcomma = find(line.rbegin(), line.rend(), ',');
    cout << string(rcomma.base(), line.end()) << endl;
}