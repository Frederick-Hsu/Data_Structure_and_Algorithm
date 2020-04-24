#include "template_parameter.h"

#include <string>
#include <memory>

void access_template_parameter(void)
{
#if 0
    XCls<string, Lst> my_XCls;
    XCls<string, shared_ptr> p1;
    // XCls<string, unique_ptr> p2;
    XCls<string, weak_ptr> p3;
    XCls<long, auto_ptr> p4;
#endif
    Stack<int, deque<int>> my_stack;
}
