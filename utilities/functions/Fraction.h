#ifndef FRACTION_H
#define FRACTION_H

    #include <string>
    #include <iostream>

    class Fraction;

    class Fraction
    {
        friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
        friend void          operator>>(std::istream& in,        Fraction& frac);
    public:
        explicit Fraction(int num, int den = 1);
        Fraction(const Fraction& other);
        Fraction& operator=(const Fraction& other);
    public:
        operator double() const     /* conversion function */
        {
            return (static_cast<double>(m_numerator) / static_cast<double>(m_denominator));
        }
        Fraction operator+(const Fraction& frac);   /* non-explicit-one-argument ctor */
    private:
        int m_numerator;
        int m_denominator;
    };

#endif  /* FRACTION_H */