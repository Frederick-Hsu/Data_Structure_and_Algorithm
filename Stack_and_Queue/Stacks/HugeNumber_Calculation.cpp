#include "HugeNumber_Calculation.h"

#include <cctype>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int digitCharToInt(char digit)
{
    int number = 0;
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

static string digitIntToStr(int digit)
{
    string num;
    switch (digit)
    {
    case 0:     num = "0";      break;
    case 1:     num = "1";      break;
    case 2:     num = "2";      break;
    case 3:     num = "3";      break;
    case 4:     num = "4";      break;
    case 5:     num = "5";      break;
    case 6:     num = "6";      break;
    case 7:     num = "7";      break;
    case 8:     num = "8";      break;
    case 9:     num = "9";      break;
    default:    num = "";       break;
    }
    return num;
}

HugeNumber_Calculation::HugeNumber_Calculation(const string& numberInStringFormat)
{
#if defined (DEBUG_INFO)
    cout << "HugeNumber_Calculation::HugeNumber_Calculation(const string&) constructor called." << endl;
#endif
    /* Firstly, ignore the prefix zeroes, such as "002569", you should discard "00",
     * get the effective number string "2569".
     */
    string::size_type index = 0;
    for (index = 0; index < numberInStringFormat.size(); ++index)
    {
        if (numberInStringFormat[index] != '0')
        {
            break;
        }
    }
    string effective_number_str = numberInStringFormat.substr(index);

    /* [NOTICE] : Storage order, you must pay more attention to the stack storage order
     * e.g.       6589024
     *
     *            |     |
     *            +-----+
     *            |  4  |   <--- Least significant digit
     *            +-----+
     *            |  2  |
     *            +-----+
     *            |  0  |
     *            +-----+
     *            |  9  |
     *            +-----+
     *            |  8  |
     *            +-----+
     *            |  5  |
     *            +-----+
     *            |  6  |   <--- Most significant digit
     *            +-----+
     *
     */
    for (string::size_type pos = 0; pos < effective_number_str.size(); ++pos)
    {
        if (isdigit(effective_number_str[pos]))
        {
            hugenum_stack.push(digitCharToInt(effective_number_str[pos]));
        }
        else
        {
            throw std::logic_error("The huge number you enter is not correct in format");
        }
    }
}

HugeNumber_Calculation::HugeNumber_Calculation(const HugeNumber_Calculation& orig) : hugenum_stack(orig.hugenum_stack)
{
#if defined (DEBUG_INFO)
    cout << "HugeNumber_Calculation::HugeNumber_Calculation(const HugeNumber_Calculation&) copy constructor called." << endl;
#endif
}

HugeNumber_Calculation& HugeNumber_Calculation::operator=(const HugeNumber_Calculation &orig)
{
#if defined (DEBUG_INFO)
    cout << "HugeNumber_Calculation::operator=(const HugeNumber_Calculation &orig) assign constructor called." << endl;
#endif
    /* You should clean up the old stack firstly */
    while (!hugenum_stack.empty())
    {
        hugenum_stack.pop();
    }
    hugenum_stack = orig.hugenum_stack;
    return *this;
}

HugeNumber_Calculation::~HugeNumber_Calculation()
{
#if defined (DEBUG_INFO)
    cout << "HugeNumber_Calculation::~HugeNumber_Calculation() destructor called." << endl;
#endif
    while (!hugenum_stack.empty())
    {
        hugenum_stack.pop();
    }
}

HugeNumber_Calculation::HugeNumber_Calculation()
{
}

size_t HugeNumber_Calculation::size() const
{
    return hugenum_stack.size();
}

string print(HugeNumber_Calculation hugenum)
{
    string num = "";
    while (!hugenum.hugenum_stack.empty())
    {
        int digit = hugenum.hugenum_stack.top();
        num += digitIntToStr(digit);
        hugenum.hugenum_stack.pop();
    }
    reverse(num.begin(), num.end());
    return num;
}

HugeNumber_Calculation operator+(HugeNumber_Calculation hugenum1, HugeNumber_Calculation hugenum2)
{
    stack<int> result_stack;

    int carry_flag = 0;
    while ( (!hugenum1.hugenum_stack.empty()) || (!hugenum2.hugenum_stack.empty()) )
    {
        int digit1 = 0, digit2 = 0;
        if (!hugenum1.hugenum_stack.empty())
        {
            digit1 = hugenum1.hugenum_stack.top();
            hugenum1.hugenum_stack.pop();
        }
        if (!hugenum2.hugenum_stack.empty())
        {
            digit2 = hugenum2.hugenum_stack.top();
            hugenum2.hugenum_stack.pop();
        }
        int sum = (digit1 + digit2 + carry_flag) % 10;
        result_stack.push(sum);
        carry_flag = (digit1 + digit2) / 10;
    }
    if (carry_flag != 0)
    {
        result_stack.push(carry_flag);
    }

    string calc_result = "";
    while (!result_stack.empty())
    {
        calc_result += digitIntToStr(result_stack.top());
        result_stack.pop();
    }
    return HugeNumber_Calculation(calc_result);
}

bool operator<(HugeNumber_Calculation hugenum1, HugeNumber_Calculation hugenum2)
{
    bool result = false;
    size_t len1 = hugenum1.size(), len2 = hugenum2.size();

    if (len1 < len2)
    {
        result = true;
    }
    else if (len1 == len2)
    {
        string numstr1 = print(hugenum1), numstr2 = print(hugenum2);
        for (unsigned index = 0; index < len1; ++index)
        {
            if ( digitCharToInt(numstr1[index]) < digitCharToInt(numstr2[index]))
            {
                result = true;
                break;
            }
            else if (digitCharToInt(numstr1[index]) == digitCharToInt(numstr2[index]))
            {
                continue;
            }
            else if (digitCharToInt(numstr1[index]) > digitCharToInt(numstr2[index]))
            {
                result = false;
                break;
            }
        }
    }
    else    /* len1 > len2 */
    {
        result = false;
    }
    return result;
}

bool operator==(HugeNumber_Calculation hugenum1, HugeNumber_Calculation hugenum2)
{
    bool result = false;
    size_t len1 = hugenum1.size(), len2 = hugenum2.size();

    if (len1 == len2)
    {
        string numstr1 = print(hugenum1), numstr2 = print(hugenum2);
        for (size_t index = 0; index < len1; ++index)
        {
            if (digitCharToInt(numstr1[index]) != digitCharToInt(numstr2[index]))
            {
                result = false;
                break;
            }
            else
            {
                result = true;
            }
        }
    }
    else
    {
        result = false;
    }
    return result;
}

string operator-(HugeNumber_Calculation hugenum1, HugeNumber_Calculation hugenum2)
{
    HugeNumber_Calculation bignumber, smallnumber;
    string sign = "";
    if (hugenum1 == hugenum2)
    {
        return "0";
    }
    else if (hugenum1 < hugenum2)
    {
        sign = "-";
        bignumber = hugenum2;
        smallnumber = hugenum1;
    }
    else    /* hugenum1 > hugenum2 */
    {
        bignumber = hugenum1;
        smallnumber = hugenum2;
    }

    int borrow_flag = 0;
    stack<int> difference_stack;
    while ((!bignumber.hugenum_stack.empty()) || (!smallnumber.hugenum_stack.empty()))
    {
        int digit1 = 0, digit2 = 0;
        if (!bignumber.hugenum_stack.empty())
        {
            digit1 = bignumber.hugenum_stack.top();
            bignumber.hugenum_stack.pop();
        }
        if (!smallnumber.hugenum_stack.empty())
        {
            digit2 = smallnumber.hugenum_stack.top();
            smallnumber.hugenum_stack.pop();
        }

        int current_difference_digit = 0;
        if (borrow_flag == 0)   /* no borrow 10 from higher bit */
        {
            if (digit1 < digit2)
            {
                current_difference_digit = digit1 + 10 - digit2;
                borrow_flag = 1;
            }
            else if (digit1 == digit2)
            {
                current_difference_digit = 0;
                borrow_flag = 0;
            }
            else    /* digit1 > digit2 */
            {
                current_difference_digit = digit1 - digit2;
                borrow_flag = 0;
            }
        }
        else if (borrow_flag == 1)  /* borrow 10 from higher bit */
        {
            if ((digit1 - 1) < digit2)
            {
                current_difference_digit = digit1 -1 + 10 - digit2;
                borrow_flag = 1;
            }
            else if ((digit2 - 1) == digit2)
            {
                current_difference_digit = 0;
                borrow_flag = 0;    /* clear the borrow flag */
            }
            else    /* digit1 - 1 > digit2 */
            {
                current_difference_digit = digit1 - 1 - digit2;
                borrow_flag = 0;    /* no need to borrow bit, clear the flag */
            }
        }
        difference_stack.push(current_difference_digit);
    }

    string calc_result = "";
    while (!difference_stack.empty())
    {
        calc_result += digitIntToStr(difference_stack.top());
        difference_stack.pop();
    }
    return (sign + calc_result);
}

static HugeNumber_Calculation reverseStackToHugeNumber(stack<int> istack)
{
    string numberStr = "";
    while (!istack.empty())
    {
        numberStr += digitIntToStr(istack.top());
        istack.pop();
    }
    return HugeNumber_Calculation(numberStr);
}

HugeNumber_Calculation operator*(HugeNumber_Calculation hugenum1, HugeNumber_Calculation hugenum2)
{
    stack<int> multiplier(hugenum1.hugenum_stack), multiplicand = hugenum2.hugenum_stack;

    vector<stack<int> > product_vec;

    int multiplicand_digit_size = 0;
    while (!multiplicand.empty())
    {
        stack<int> product;
        for (int n = 0; n < multiplicand_digit_size; ++n)
        {
            product.push(0);
        }
        multiplicand_digit_size++;
        int multiplicand_digit = multiplicand.top();
        multiplicand.pop();

        stack<int> multiplier_substitue(multiplier);
        int carry_flag = 0;
        while (!multiplier_substitue.empty())
        {
            int prod = (multiplicand_digit * multiplier_substitue.top() + carry_flag);
            product.push(prod % 10);
            carry_flag = prod / 10;
            multiplier_substitue.pop();
        }
        if (carry_flag != 0)
        {
            product.push(carry_flag);
        }

        product_vec.push_back(product);
    }

    HugeNumber_Calculation productOfHugeNumbers;
    for (unsigned pos = 0; pos < product_vec.size(); ++pos)
    {
        HugeNumber_Calculation temp_product = reverseStackToHugeNumber(product_vec[pos]);
        productOfHugeNumbers = productOfHugeNumbers + temp_product;
    }
    return productOfHugeNumbers;
}
