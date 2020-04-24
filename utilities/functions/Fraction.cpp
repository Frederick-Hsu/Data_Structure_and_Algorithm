#include "Fraction.h"

using namespace std;

Fraction::Fraction(int num, int den) : m_numerator(num), m_denominator(den)
{
}

Fraction::Fraction(const Fraction& other) : m_numerator(other.m_numerator), 
                                            m_denominator(other.m_denominator)
{
}

Fraction& Fraction::operator=(const Fraction& other)
{
    m_numerator = other.m_numerator;
    m_denominator = other.m_denominator;
    return *this;
}

std::ostream& operator<<(ostream& out, const Fraction& frac)
{
    out << frac.m_numerator << "/" << frac.m_denominator;
    return out;
}

void operator>>(istream& in, Fraction& frac)
{
    cout << "Please enter the numberator: ";
    in >> frac.m_numerator;
    cout << "and the denominator: ";
    in >> frac.m_denominator;
}

Fraction Fraction::operator+(const Fraction& frac)
{
    return Fraction((m_numerator * frac.m_denominator + m_denominator * frac.m_numerator),
                    (m_denominator * frac.m_denominator));
}