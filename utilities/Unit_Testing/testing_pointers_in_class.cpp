#include "testing_pointers_in_class.h"
#include "../Pointers_in_Class/HasPtr.h"
#include "../Sales_Item/ScreenPtr.h"
#include "../Sales_Item/Screen.h"
#include "../Sales_Item/GT_calculations.h"
#include "../Sales_Item/SmallInt.h"

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <random>
#include <ctime>

void testing_points_in_class()
{
    validate_smart_pointer();
    call_operator_plusplus();
    // copy_assign_pointer_member();
    // apply_function_object_onto_stdalgorithms();
    // apply_function_object_class();
    apply_function_adapter();
}

void copy_assign_pointer_member()
{
#if (MANAGE_POINTER_MEMBER_BY == PLAIN_POINTER)
    int obj = 0;
    HasPtr ptr1(&obj, 42);
    HasPtr ptr2(ptr1);

    ptr1.set_int(0);
    int value2 = ptr2.get_int();
    int value1 = ptr1.get_int();

    ptr1.set_ptr_val(100);
    int ptrvalue2 = ptr2.get_ptr_val();
    int ptrvalue1 = ptr1.get_ptr_val();

    int *ip = new int(50);      /* dynamically allocated int initialized to 50 */
    HasPtr ptr(ip, 10);         /* HasPtr points to same object as ip does. */
    delete ip;                  /* object pointed to by ip has been freed. */
    ptr.set_ptr_val(0);         /* disaster: The object to which HasPtr points was freed. */
#elif (MANAGE_POINTER_MEMBER_BY == REF_COUNT_SMART_POINTER)
    int obj = 25;
    HasPtr p1(&obj, 42);
    HasPtr p2(p1);
    HasPtr p3 = p1;
#elif (MANAGE_POINTER_MEMBER_BY == VALUE_SEMATICS_POINTER)

#endif
}

void validate_smart_pointer()
{
    // ScreenPtr p1;   /* Error: ScreenPtr has no default constructor */
    ScreenPtr ps(new Screen(4, 4));

    Screen myScree(5, 4);
    ScreenPtr p(&myScree);
    // p->display(cout);
}

void call_operator_plusplus()
{
    int array[10] = {1, 2, 3, 4, 5};
    CheckedPtr parr(array, array+(sizeof(array)/sizeof(int)));
    parr++;
    ++parr;

    parr.operator--(0);     /* call parr-- */
    parr.operator--();      /* call --parr */
    cout << parr[3] << endl;

    int i = -42;
    AbsInt absobj;
    unsigned int ui = absobj(i);
    cout << ui << endl;
}

void apply_function_object_onto_stdalgorithms()
{
    vector<string> words;
    string word;
    while (cin >> word)
    {
        words.push_back(word);
    }
    cout << count_if(words.begin(), words.end(), GT_calculations(6))
         << " words 6 characters or longer." << endl;
    for (size_t len = 0; len != 11; ++len)
    {
        cout << count_if(words.begin(), words.end(), GT_calculations(len))
             << " words " << len << " characters or longer."
             << endl;
    }
}

void apply_function_object_class()
{
    plus<int> intAdd;           /* function object that can add 2 int values */
    negate<int> intNegate;      /* function object that can negate an int value */
    int sum = intAdd(10, 20);
    cout << "current sum = " << sum << endl;
    sum = intAdd(50, intNegate(35));
    cout << "now the sum has changed to: " << sum << endl;

    vector<string> svec;
    string line, word;
    getline(cin, line);
    istringstream linestream(line);
    while (linestream >> word)
    {
        svec.push_back(word);
    }
    sort(svec.begin(), svec.end(), greater<string>());
    for (vector<string>::const_iterator it = svec.begin(); it != svec.end(); ++it)
    {
        cout << *it << " ";
    }
}

void apply_function_adapter()
{
    srand(time(0));
    vector<int> ivec;
    int total;
    cout << "How many random numbers do you want to generate: ";
    cin >> total;
    for (int cnt = 0; cnt < total; ++cnt)
    {
        ivec.push_back(rand()%1000);
    }
    for (int row = 0; row < total/5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            cout << ivec[static_cast<vector<int>::size_type>(column + row*5)] << "\t";
        }
        cout << endl;
    }
    vector<int>::difference_type amount = count_if(ivec.begin(),
                                                   ivec.end(),
                                                   bind2nd(less_equal<int>(), 37));
    cout << "There are " << amount << " random numbers, they are <= 37." << endl;

    amount = count_if(ivec.begin(), ivec.end(), not1(bind2nd(less_equal<int>(), 59)));
    cout << "There are " << amount << " random numbers, they are NOT <= 59" << endl;
}

int calc(int num)
{
    return (num + 3)*(num - 5);
}

void utilize_conversion_operator()
{
    SmallInt si(6);
    double dval = 3.1415;
    bool compare = (si >= dval);
    cout << "The compare result is: " << compare << endl;
    cout << "The value si = " << si << endl;

    SmallInt dsi = 3.541;
    int ival = static_cast<int>(dsi) + 3;
    cout << "The value ival = " << ival << endl;

    Integral intVal(8);
    SmallInt mySI(intVal);      /* OK: convert intVal to SmallInt and copy to mySI */
    int product = calc(mySI);   /* OK: convert mySI to int and call calc(int) */
    cout << "The product = " << product << endl;
    // product = calc(intVal);     /* Error: no conversion to int from Integral */
}
