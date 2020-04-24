#include "variadic_templates.h"

#include <bitset>

void print_mutable_args()
{
}

void verify_how_variadic_templates_work(void)
{
    print_mutable_args(7.5, "hello", std::bitset<16>(377), 42);
}
