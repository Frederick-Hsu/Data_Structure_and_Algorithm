#include "testing.h"
#include "Fraction.h"
#include "template_functor.h"

#include <string>
using namespace std;

void execute_test_items(void)
{
    access_conversion_functions();
    utilize_template_functor();
}

void access_conversion_functions(void)
{
    Fraction frac(3, 5);
    cout << frac << endl;

    double dval = 5 + frac;
    cout << dval << endl;

    // Fraction fracval = frac + 4;
}

void utilize_template_functor(void)
{
    Pair<int, string> elem(10, "Template functor");
    select1st< Pair<int, string> > item_part1;
    select2nd< Pair<int, string> > item_part2;

    const Pair<int, string>::first_type& first_elem = item_part1(elem);
    cout << first_elem << endl;

    const Pair<int, string>::second_type& sec_elem = item_part2(elem);
    cout << sec_elem << endl;
}

