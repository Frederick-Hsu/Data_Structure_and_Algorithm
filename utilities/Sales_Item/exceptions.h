#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

    #include <stdexcept>
    using namespace std;

    /* hypothetical exception classes for a bookstore application */
    class out_of_stock : public runtime_error
    {
    public:
        explicit out_of_stock(const string& s) : runtime_error(s) {}
    };

    class isbn_mismatch : public logic_error
    {
    public:
        explicit isbn_mismatch(const string& s);
        isbn_mismatch(const string& s, const string& lhs, const string& rhs);
        virtual ~isbn_mismatch() throw() {}
    public:
        const string left, right;
    };

    void verify_how_user_defined_exception_works(void);

#if 0
    class bad_alloc : public exception
    {
    public:
        bad_alloc() throw();
        bad_alloc(const bad_alloc&) throw();
        bad_alloc& operator=(const bad_alloc&) throw();
        virtual ~bad_alloc() throw();
        virtual const char * what() const throw();
    };
#endif

    class Base
    {
    public:
        virtual double f1(double) throw();
        virtual int f2(int) throw (std::logic_error);
        virtual std::string f3() throw (std::logic_error, std::runtime_error);
    };

    class Derived
    {
    public:
        /* error: exception specification is less restrictive than Base::f1's */
        double f1(double) throw (std::underflow_error);
        /* ok: same exception specification as Base::f2 */
        int f2(int) throw (std::logic_error);
        /* ok: Derived::f3 is more restrictive */
        std::string f3() throw();
    };

    void recoup(int) throw (runtime_error);
    void (*pf1)(int) throw (runtime_error) = recoup;    /* OK: recoup is as restrictive as pf1 */
    void (*pf2)(int) throw (runtime_error, logic_error) = recoup;   /* OK: recoup is more restrictive than pf2 */
    // void (*pf3)(int) throw () = recoup;     /* Error: recoup is less restrictive than pf3 */
    void (*pf4)(int) = recoup;      /* OK: recoup is more restrictive than pf4 */

#endif  /* EXCEPTIONS_H */
