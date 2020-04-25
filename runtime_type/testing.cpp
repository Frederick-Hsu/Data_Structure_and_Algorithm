#include "testing.h"
#include "types.h"
#include "nested_type/Queue.h"
#include "union_type/TokenValue.h"

void execute_test_items(void)
{
    display_type_name();
    verify_how_to_instantiate_nested_type_objs();
    instantiate_union_type_objs();
}

void verify_how_to_instantiate_nested_type_objs(void)
{
    Queue<int> prime_numbers_que;
    prime_numbers_que.push(2);
    prime_numbers_que.push(3);
    prime_numbers_que.push(5);
    prime_numbers_que.push(7);
    prime_numbers_que.push(11);

    prime_numbers_que.pop();
    prime_numbers_que.push(13);
    prime_numbers_que.push(17);
    prime_numbers_que.pop();
    prime_numbers_que.push(23);
}

int foo(int val)
{
    static int si;
    enum LOC {a = 1024, b};

    class Bar
    {
    public:
        LOC locVal;
        int barVal;
        void fooBar(LOC l = a)
        {
            // barVal = val;   /* Error : val is local to foo */
            barVal = si;        /* OK : uses static local object */
            locVal = b;         /* OK : uses enumerator */
        }
    };
}
