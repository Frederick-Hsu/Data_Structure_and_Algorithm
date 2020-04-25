#ifndef EXCEPTION_ERROR_HANDLING_H
#define EXCEPTION_ERROR_HANDLING_H

    #include <stdexcept>
    #include <string>

    using std::string;

    class out_of_stock;
    class isbn_mismatch;

    class out_of_stock : public std::runtime_error
    {
    public:
        explicit out_of_stock(const string& s);
    };

    class isbn_mismatch : public std::logic_error
    {
    public:
        explicit isbn_mismatch(const string& s);
        isbn_mismatch(const string& s, const string& lhs, const string& rhs);
        virtual ~isbn_mismatch() throw();
    public:
        const string left;
        const string right;
    };

#endif  /* EXCEPTION_ERROR_HANDLING_H */
