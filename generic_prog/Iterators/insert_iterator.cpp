#include "iterators.h"

#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void insert_container_through_inserter_iterator(void)
{
#if 0
    list<int> ilst;
    vector<int> ivec;
    int num;
    while (cin >> num)
    {
        ilst.push_back(num);
        ivec.push_back(num * num);
    }

    /* position an iterator into ilst */
    list<int>::iterator it = find(ilst.begin(), ilst.end(), 42);
    /* insert replaced copies of ivec at that point in ilst */
    replace_copy(ivec.begin(), ivec.end(), inserter(ilst, it), 100, 0);
#endif

    list<int> origin_ilst, 
        lst_to_be_inserted_front, 
        lst_to_be_inserted_back,
        lst_to_be_inserted;
    /* after this loop, origin_ilst contains : 3, 2, 1, 0 */
    for (list<int>::size_type i = 0; i != 4; ++i)
    {
        origin_ilst.push_front(i);
    }
    cout << "The origin list is: " << endl;
    for (list<int>::iterator it = origin_ilst.begin(); it != origin_ilst.end(); ++it)
    {
        cout << *it << endl;
    }

    copy(origin_ilst.begin(), origin_ilst.end(), front_inserter(lst_to_be_inserted_front));
    cout << "The list was inserted in front: " << endl;
    for (list<int>::iterator it = lst_to_be_inserted_front.begin(); it != lst_to_be_inserted_front.end(); ++it)
    {
        cout << *it << endl;
    }
    
    copy(origin_ilst.begin(), origin_ilst.end(), back_inserter(lst_to_be_inserted_back));
    cout << "The list was inserted at back: " << endl;
    for (list<int>::iterator it = lst_to_be_inserted_back.begin(); it != lst_to_be_inserted_back.end(); ++it)
    {
        cout << *it << endl;
    }

    copy(origin_ilst.begin(), origin_ilst.end(), inserter(lst_to_be_inserted, lst_to_be_inserted.begin()));
    cout << "The list was inserted in the specific position: " << endl;
    for (list<int>::iterator it = lst_to_be_inserted.begin(); it != lst_to_be_inserted.end(); ++it)
    {
        cout << *it << endl;
    }
}