#ifndef SMALLINT_H
#define SMALLINT_H

    #include <cstddef>

    class SmallInt
    {
    public:
        SmallInt(int i = 0);
    public:
        operator int() const
        {
            return static_cast<int>(val);
        }
        friend SmallInt operator+(const SmallInt&, const SmallInt&);
    private:
        std::size_t val;
    };

    class Integral
    {
    public:
        Integral(int i = 0);
    public:
        operator SmallInt() const;
    private:
        std::size_t val;
    };

#endif  /* SMALLINT_H */
