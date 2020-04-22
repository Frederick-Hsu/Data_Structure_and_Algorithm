#include <iostream>

using namespace std;

#include "HugeNumber_Calculation.h"

int main(int argc, char* argv[])
{
    HugeNumber_Calculation hugenum("1234567890123456789");

    cout << print(hugenum) << endl;

    HugeNumber_Calculation hnum1("69586418569145687489169489418414848614187803200546306471699845"),
            hnum2("00094375155532058420857207814884859418548741651");
    HugeNumber_Calculation sum = hnum1 + hnum2;
    cout << print(sum) << endl;

    HugeNumber_Calculation bignum("657464849414789456587494156314752"), smallnum("3928948987456314587485");
    string difference = smallnum - bignum;
    cout << difference << endl;
    cout << bignum - smallnum << endl;

    HugeNumber_Calculation hnum_multiplier("6357510585269874184185169874695416587495212352002584652821"),
            hnum_multiplicand("48298541586532147896589498410698746398416415863");
    HugeNumber_Calculation product = hnum_multiplier * hnum_multiplicand;
    cout << print(product) << endl;

    return 0;
}
