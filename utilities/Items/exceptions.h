#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

    #include <stdexcept>
    using namespace std;

namespace BookStore
{
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

        const string left, right;
    };
}

#endif  /* EXCEPTIONS_H */
