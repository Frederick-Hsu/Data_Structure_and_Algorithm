#include "testing.h"
#include "Vector.h"

#include <string>
#include <vector>
#include <iostream>
#include "Queue.h"

void execute_test_items(void)
{
    // verify_user_vector();
    validate_how_memory_allocator_works();
}

void verify_user_vector(void)
{
    Vector<int> fibonacci_vec;
    fibonacci_vec.push_back(1);
    fibonacci_vec.push_back(1);

    fibonacci_vec.push_back(2);
    fibonacci_vec.push_back(3);
    fibonacci_vec.push_back(5);
    fibonacci_vec.push_back(8);
}

void allocate_and_construct_objects(void)
{
    std::string names[] = {"Frederique", "Konstantin", "Yun-seo Koo", "Mike Merrick", "David Dai",
                           "Iraj Ehtezazi Alamdari"};

    std::allocator<std::string> alloc;
    std::size_t count = sizeof(names)/sizeof(std::string);
    std::size_t total_size_in_byte = 0;
    for (std::size_t index = 0; index < count; ++index)
    {
        total_size_in_byte += (names + index)->size();
    }

    std::string *sptr = alloc.allocate(total_size_in_byte);   /* allocate space to hold 2 strings */

    std::cout << *(names->begin()) << std::endl;
    std::cout << *((names + count - 1)->end() - 1) << std::endl;
    /* two ways to construct a string from a pair of iterators */
#if 1
    new (sptr) std::string(names->begin(), names->end());               /* construct directly in place */
#else
    alloc.construct(sptr, std::string(names->begin(), names->end()));   /* build and copy a temporary */
#endif
    for (std::size_t index = 0; index < count; ++index)
    {
        std::cout << *(sptr + index) << std::endl;
    }
    alloc.destroy(sptr);
}

void validate_how_memory_allocator_works(void)
{
    const size_t CNT = 60;
    vector<unsigned long> fibonacci_vec;
    fibonacci_vec.push_back(1);
    fibonacci_vec.push_back(1);

    for (size_t index = 2; index < CNT; ++index)
    {
        fibonacci_vec.push_back(fibonacci_vec[index-1] + fibonacci_vec[index-2]);
    }

    Queue<unsigned long> fibonacci_que;
    for (vector<unsigned long>::iterator it = fibonacci_vec.begin(); it != fibonacci_vec.end(); ++it)
    {
        fibonacci_que.push(*it);
    }
    cout << fibonacci_que << endl;
}
