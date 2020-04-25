#include "Generic_Algorithm_Basics.h"

#include <algorithm>
#include <numeric>

#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

void readonly_algorithm(void)
{
    vector<int> ivec;
    int num;
    while (cin >> num)
    {
        ivec.push_back(num);
    }
    /* sum the elements in vec starting the summation with the value 42 */
    int sum = accumulate(ivec.begin(), ivec.end(), 42);

    vector<string> svec;
    string word;
    while (cin >> word)
    {
        svec.push_back(word);
    }
    /* concatenate elements from v and store in strsum */
    string strsum = accumulate(svec.begin(), svec.end(), string(""));

    list<string> roster1;
    list<const char*> roster2;
    while (cin >> word)
    {
        roster1.push_back(word);
    }
    string line;
    while (getline(cin, line))
    {
        roster2.push_back(line.c_str());
    }
    list<string>::size_type cnt = 0;
    list<string>::iterator it = roster1.begin();
    /* look in roster1 for any name also in roster2 */
#if 1
    while ((it = find_first_of(it, roster1.end(), roster2.begin(), roster2.end())) != roster1.end())
#else
    while ((it = find_first_of(it, roster1.end(), svec.begin(), svec.end())) != roster1.end())
#endif
    {
        ++cnt;
        ++it;   /* we got a match, increment it to look in the rest of roster1 */
    }
    cout << "Found " << cnt << " names on both rosters" << endl;
}

void write_container_elements_algorithm(void)
{
    vector<int> ivec(10);
    fill(ivec.begin(), ivec.end(), 1);      /* reset each element to 1 */
    fill(ivec.begin(), ivec.begin() + ivec.size() / 2, 10);     /* set subsequence of the range to 10 */

    vector<int> vec;    /* empty vector */
    /* OK: back_inserter creates an insert iterator that adds elements to vec */
    fill_n(back_inserter(vec), 10, 0xFF);   /* appends 10 elements to vec. */
}

void write_into_target_iterators(void)
{
    list<int> ilst;
    fill_n(back_inserter(ilst), 10, 0x5E);

    vector<int> empty_ivec;
    /* copy elements from ilst to empty_ivec */
    copy(ilst.begin(), ilst.end(), back_inserter(empty_ivec));

    /* replace any element with the value of 0 by what user input */
    int num;
    cin >> num;
    replace(ilst.begin(), ilst.end(), 0x5E, num);

    vector<int> ivec;   /* create empty vector to hold the replacement */
    /* use back_inserter to grow destination as needed */
    replace_copy(ilst.begin(), ilst.end(), back_inserter(ivec), num, 0xFF);
}