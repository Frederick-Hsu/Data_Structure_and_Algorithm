#include "testing.h"
#include "class_template/Queue.h"
#include "class_template/List.h"
#include "class_template/Screen.h"
#include "function_template/function_template.h"

#include <string>
#include <iomanip>

void instantiateClassTemplates(void)
{
    const size_t CNT = 10;

    Queue<int> qi;
    short s = 42;
    int i = 56;
    qi.push(s);
    qi.push(i);
    qi.push(10);
    std::cout << "Please enter numbers which you want to push into the queue: ";
    std::cin >> qi;

    std::cout << qi << std::endl;

    unsigned fib[CNT];
    fibonacci_series<CNT>(fib);

    qi += Queue<int>(fib, fib+CNT-1);
    cout << qi << endl;

    Queue<std::string> qs;
    qs.push("Hello");
}

void verify_list_structure(void)
{
    int numbers[] = {5, 7, 11, 13, 17, 19};
    List<int> primer_nums;
    primer_nums.append(2);
    primer_nums.assign(numbers, numbers + sizeof(numbers)/sizeof(int));
    primer_nums.insert(1, 2);
    cout << primer_nums << endl;

    primer_nums.remove(1);
    primer_nums.insert(1, 3);

    cout << primer_nums << endl;
    cout << "Append a new primer number at the end: ";
    cin >> primer_nums;
    cout << primer_nums << endl;
}

void instantiate_nontype_parameter_templates(void)
{
    Screen<24, 80> hp2621;      /* screen 24 lines by 80 characters */
}

void instantiate_object_from_other_iterators_range(void)
{
    vector<size_t>  fibonacci;
    fibonacci_series<25>(fibonacci);

    Queue<size_t> fib_queue(fibonacci.begin(), fibonacci.end());
    cout << fib_queue << endl;
    cout << "\n" << endl;

    vector<long double> fib_ratio;
    fibonacci_ratio_series<50>(fib_ratio);

    Queue<long double> fib_ratio_queue;
    fib_ratio_queue.assign(fib_ratio.begin(), fib_ratio.end());
    cout << fixed << setprecision(20) << fib_ratio_queue << endl;
}

void instantiateSpecificFnctTemplate(void)
{
    const char *cp1 = "hello", *cp2 = "world";
    int inum1 = 15, inum2 = 87;

    compare(cp1, cp2);
    compare(inum1, inum2);
}

void call_specialized_class_template(void)
{
    Queue<const char*> queue_char;
    queue_char.push("hi");
    queue_char.push("bye");
    queue_char.push("world");

    cout << queue_char.origQueue() << endl;

    Queue<const char*> quechar(queue_char);
    cout << quechar.origQueue() << endl;

    Queue<const char*> another_queue;   /* empty Queue */
    another_queue = queue_char;
    cout << another_queue.origQueue() << endl;
}
