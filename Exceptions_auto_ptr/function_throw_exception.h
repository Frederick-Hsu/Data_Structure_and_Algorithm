#ifndef FUNCTION_THROW_EXCEPTION_H
#define FUNCTION_THROW_EXCEPTION_H

    #include <exception>
    #include <stdexcept>
    #include <string>
    using namespace std;

    class bad_alloc : public exception
    {
    public:
        bad_alloc() throw();
        bad_alloc(const bad_alloc&) throw();
        bad_alloc& operator=(const bad_alloc&) throw();
        virtual ~bad_alloc() throw();
        virtual const char* what() const throw();
    };

    class Base
    {
    public:
        virtual double f1(double) throw();
        virtual int f2(int) throw (logic_error);
        virtual string f3() throw (logic_error, runtime_error);
    };

    class Derived : public Base
    {
    public:
        /* Error: exception sepcification is less restrictive than Base::f1's
         *
        double f1(double) throw (underflow_error);
         */
        int f2(int) throw (logic_error);    /* same exception specification as Base::f2 */
        string f3() throw();    /* Derived f3 is more restrictive */
    };

    void compute(Base *pb) throw();
    // void (*pfnct)(int) throw (runtime_error);

    void recoup(int) throw (runtime_error);

#endif  /* FUNCTION_THROW_EXCEPTION_H */
