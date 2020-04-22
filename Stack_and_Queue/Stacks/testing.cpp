#include "testing.h"
#include "genStack.h"
#include "genListStack.h"
#include "HugeNumber_Calculation.h"

#include <cstdlib>
#include <stdexcept>
#include <iostream>

static int digit2Int(char digit)
{
    int number;
    switch (digit)
    {
    case '0':   number = 0;     break;
    case '1':   number = 1;     break;
    case '2':   number = 2;     break;
    case '3':   number = 3;     break;
    case '4':   number = 4;     break;
    case '5':   number = 5;     break;
    case '6':   number = 6;     break;
    case '7':   number = 7;     break;
    case '8':   number = 8;     break;
    case '9':   number = 9;     break;
    default:    number = 0;     break;
    }
    return number;
}

static char digit2Char(int digit)
{
    char number;
    switch (digit)
    {
    case 0:     number = '0';   break;
    case 1:     number = '1';   break;
    case 2:     number = '2';   break;
    case 3:     number = '3';   break;
    case 4:     number = '4';   break;
    case 5:     number = '5';   break;
    case 6:     number = '6';   break;
    case 7:     number = '7';   break;
    case 8:     number = '8';   break;
    case 9:     number = '9';   break;
    default:    number = '\0';  break;
    }
    return number;
}

string addHugeNumbers(const string& hugenumber1, const string& hugenumber2)
{
#if 1
    LLStack<int> huge_stack1, huge_stack2;
#else
    Stack<int, 5> huge_stack1, huge_stack2;
#endif

    for (string::const_iterator cit = hugenumber1.begin(); cit != hugenumber1.end(); ++cit)
    {
        if (!isdigit(*cit))
        {
            throw logic_error("This char is not a digit.");
        }
        huge_stack1.push(digit2Int(*cit));
    }
    for (string::size_type pos = 0; pos != hugenumber2.size(); ++pos)
    {
        if (!isdigit(hugenumber2[pos]))
        {
            throw logic_error("This char is not a digit.");
        }
        huge_stack2.push(digit2Int(hugenumber2[pos]));
    }

    LLStack<int> sum_stack;
    int quotient = 0, remainder = 0;
    while ((!huge_stack1.isEmpty()) || (!huge_stack2.isEmpty()))
    {
        int num1 = 0;
        if (!huge_stack1.isEmpty())
            num1 = huge_stack1.pop();
        int num2 = 0;
        if (!huge_stack2.isEmpty())
            num2 = huge_stack2.pop();
        int addnum = num1 + num2 + quotient;
        quotient = addnum / 10;
        remainder = addnum % 10;
        sum_stack.push(remainder);
    }

    string sum = "";
    while (!sum_stack.isEmpty())
    {
        sum += digit2Char(sum_stack.pop());
    }
    return sum;
}

void test_HugeNumber_Calculation(void)
{
    /*
    HugeNumber_Calculation hugenum("1234567890123456789");

    cout << print(hugenum) << endl;

    HugeNumber_Calculation hnum1("6958"), hnum2("0009437");
    HugeNumber_Calculation sum = hnum1 + hnum2;
    cout << print(sum) << endl;
     */

#if 0
    HugeNumber_Calculation hnum1("6574"), hnum2("3928");
    string difference = hnum1 - hnum2;
    cout << difference << endl;

    cout << hnum2 - hnum1 << endl;
#else
    HugeNumber_Calculation hnum_multiplier("6357"), hnum_multiplicand("482");
    HugeNumber_Calculation product = hnum_multiplier * hnum_multiplicand;
    cout << print(product) << endl;
#endif
}
