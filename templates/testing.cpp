#include "testing.h"
#include "class_template/Queue.h"
#include "class_template/List.h"
#include "class_template/Screen.h"
#include "function_template/function_template.h"
#include "function_template/variadic_templates.h"
#include "generic_handle/utilizing_handle.h"

#include <string>
#include <iomanip>

void execute_test_items(void)
{
    verify_how_variadic_templates_work();
    cout << "\n" << endl;
    instantiate_object_from_other_iterators_range();
    cout << "\n" << endl;
    differentiate_pointer_and_reference();
    cout << "\n" << endl;
    calculate_data_size();

#if 0
    // instantiateClassTemplates();

    how_generic_handle_works();

    instantiateSpecificFnctTemplate();

    call_specialized_class_template();

    verify_list_structure();
#endif
}

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

    cout << "The fibonacci vector is shown as: " << endl;
    for (auto elem : fibonacci)     /* ranged-base for loop */
    {
        cout << elem << endl;
    }

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

void differentiate_pointer_and_reference(void)
{
    int x = 0;
    int* ptr = &x;
    cout << "ptr = " << ptr << ", *ptr = " << *ptr << endl;
    int& ref = x;   /* ref 代表 x. 现在ref, x 都是 0 */
    cout << "ref = " << ref << endl;

    int x2 = 5;
    ref = x2;       /* ref 不能重新代表其他对象。 现在 ref; x 都是 5 */
    cout << "ref = " << ref << endl;
    cout << "x = " << x << ", x2 = " << x2 << endl;

    int& r2 = ref;  /* 现在r2是5 (r2代表ref; 亦相当于代表x) */
    cout << "r2 = " << r2 << ", ref = " << ref << endl;
    cout << "x = " << x << endl;
}

void calculate_data_size(void)
{
    typedef struct Stag
    {
        int a;
        int b;
        int c;
        int d;
    } S;

    double golden_ratio = 0.618;
    double *ptr = &golden_ratio;
    double& ref = golden_ratio;

    cout << "sizeof(golden_ratio) = " << sizeof(golden_ratio) << endl;
    cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
    cout << "sizeof(ref) = " << sizeof(ref) << endl;

    cout << "ptr = " << ptr << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "golden_ratio = " << golden_ratio << endl;
    cout << "ref = " << ref << endl;
    cout << "&golden_ratio = " << &golden_ratio << endl;
    cout << "&ref = " << &ref << endl;

    S sval;
    S& ref_sval = sval;
    cout << "sizeof(sval) = " << sizeof(sval) << endl;
    cout << "sizeof(ref_sval) = " << sizeof(ref_sval) << endl;
    cout << "&sval = " << &sval << endl;
    cout << "&ref_sval = " << &ref_sval << endl;
}
