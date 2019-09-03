//
// Created by Ori Frenkel on 27/08/2019.
//

#include "GField.h"
// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GField.
// --------------------------------------------------------------------------------------


// ------------------ Access methods ------------------------

/**
 * Access method for the Char(_p) value.
 * @return The char value
 */
long GField::getChar() const
{
    return _p;
}

/**
 * Access method for the Degree(_l) value.
 * @return The degree value
 */
long GField::getDegree() const
{
    return _l;
}

/**
* Access method for the order(p^l) value.
* @return The Order value
*/
long GField::getOrder() const
{
    return static_cast<long>(powl(_p, _l));
}

/**
 * Access method for the Char(_p) value.
 * @param p - The new value of the char to set.
 */
void GField::setChar(const long p)
{
    _p = p;
}
// ------------------ Other methods ------------------------

/**
 * Complexity - O(sqrt(n)) - O(n^(1/2))
 * @param p - number that we want to check whether or not is prime
 * @return - true if number p is prime, else - returning false
 */
const bool GField::isPrime(const long& p)
{
    long num = labs(p);

    // By definition 1 or lower number aren't a prime number
    if(num <= 1)
    {
        return false;
    }

    // 2 and 3 are prime numbers
    if (num <= 3)
    {
        return true;
    }

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

/**
 * overloading the print operator
 * @param output - output stream
 * @param obj - object that we want to print
 * @return - the output stream.
 */
std::ostream &operator << (std::ostream &output, GField const &obj)
{
    output << "GF(" << obj.getChar() << "**" << obj.getDegree() << ")" ;
    return output;

}

/**
 * Overloading the input operator.
 */
std::istream &operator >> (std::istream &input, GField &obj)
{
    long p, l;
    input >> p >> l ;
    obj.setChar(p);
    obj.setDegree(l);
    return input;
}

/**
 *
 * @param other - object that we want to make this object equals to.
 * @return this object after the operation '='
 */
GField& GField::operator = (const GField& other)
{
    _p = other.getChar();
    _l = other.getDegree();
    return *this;
}

/**
 *
 * @param other
 * @return
 */
bool GField::operator == (const GField &other) const
{
    return getOrder() == other.getOrder();
}

/**
 *
 * @param other - object of type GField
 * @return - true if the order or both object is different, otherwise, false
 */
bool GField::operator != (const GField &other) const
{
    return (!(GField::operator == (other)));
}

/**
 * Getting k, and return GFNumber type, of k, from the current field
 * @param k - number in Z
 * @return - GFNumber, k with the current field
 */
GFNumber GField::createNumber(const long &k) const
{
    GFNumber temp = GFNumber((k % (getOrder())), *this);
    return temp;
}


/**
 * made this function non-recursive to avoid stackOverFlow (working with long numbers)
 * @param first  - number of type GFNumber
 * @param second  - number of type GFNumber
 * @return - the greatest common divisor
 */
GFNumber GField::gcd(const GFNumber &first, const GFNumber &second) const
{
    assert(first.getField() == second.getField());
    assert(getOrder() == first.getField().getOrder() && getOrder() == second.getField().getOrder());
    assert(first.getNumber() != 0 && second.getNumber() != 0);
    long a = first.getNumber();
    long b = second.getNumber();
    {
        return GFNumber(GField::gcdHelper(a, b, first.getField().getOrder()), first.getField());
    }
}

/**
 * made this function non-recursive to avoid stackOverFlow (working with long numbers)
 * @param num1 - number of type long
 * @param num2 - number of type long
 * @param order - the field we want to do the calculation under.
 * @return - the greatest common divisor of num1 and num2 under the field (order)
 */
long GField::gcdHelper(long num1, long num2, const long order)
{
    while (num1 != num2)
    {
        if (num1 > num2)
        {
            num1 = GFNumber::modulo((num1 - num2), order);
        }
        else
        {
            num2 = GFNumber::modulo((num2 - num1), order);
        }
    }
    return num1;
}

/**
 * Access method for the Degree(_l) value.
 * @param l - The new value of the degree to set
 */
void GField::setDegree(const long  l)
{
    _l = l;
}




