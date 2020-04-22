#ifndef AUTO_PTR_H
#define AUTO_PTR_H

    #include <stdexcept>
    using namespace std;

    void safely_allocate_memory();
    void test_auto_ptr_object();

    void recoup(int) throw (runtime_error);
    void no_problem() throw();

#endif  /* AUTO_PTR_H */
