//
// Created by Ori Frenkel on 27/08/2019.
//

#ifndef CPPEX1S_GFIELD_H
#define CPPEX1S_GFIELD_H

class GFNumber; // forward declaration

#include <cmath>
#include <cassert>
#include <iostream>



/**
 * Represent a number in Galua's field
 */
class GField
{
private:
    long _p; /**< the char. Details. */
    long _l; /**< the degree. Details. */

public:

    // "if the constructor is one line, it can be in the header file" - according to the forum
    /**
     * This is 3 constructor -
     * 1. default one which  init  p=2 and l=1,
     * 2. One the receive  only p, and init l = 1
     * 3. One the receive both p and l
     * @param p - the char (should be a prime number) and abs(p) >= 2
     * @param l - the degree (l > 0)
     */
    GField(long p = 2, long l = 1):_p(labs(p)), _l(l)
    {
        assert(l > 0 && _p >= 2);
        assert(isPrime(_p));
    };

    /**
     * Copy - constructor
     * @param otherObject - the object we want to copy
     */
    GField(const GField &otherObject){_p = otherObject.getChar(); _l = otherObject.getDegree(); }

    /**
     * overloading the print operator
     * @param output - output stream
     * @param obj - object that we want to print
     * @return - the output stream.
     */
    friend std::ostream& operator << (std::ostream& output, GField const & obj);

    /**
     * Overloading the input operator.
     */
    friend std::istream& operator >> (std::istream&, GField &obj);

    /**
     *
     * @param other - object that we want to make this object equals to.
     * @return this object after the operation '='
     */
    GField& operator = (const GField& other);

    /**
     *
     * @param other - object of type GField
     * @return true if the degree of both object is the same, otherwise false
     */
    bool operator == (const GField& other) const;

    /**
     *
     * @param other - object of type GField
     * @return - true if the order or both object is different, otherwise, false
     */
    bool operator != (const GField& other) const;

    /**
     * Access method for the Char(_p) value.
     * @return The char value
     */
    long getChar() const;

    /**
     * Access method for the Char(_p) value.
     * @param p - The new value of the char to set.
     */
    void setChar(long p);

    /**
     * Access method for the Degree(_l) value.
     * @return The degree value
     */
    long getDegree() const;

    /**
    * Access method for the Degree(_l) value.
    * @param l - The new value of the degree to set
    */
    void setDegree(const long l);

    /**
    * Access method for the order(p^l) value.
    * @return The Order value
    */
    long getOrder() const;

    /**
    * Complexity - O(sqrt(n)) - O(n^(1/2))
    * @param p - number that we want to check whether or not is prime
    * @return - true if number p is prime, else - returning false
    */
    static const bool isPrime(const long& p);

    /**
    * @param first  - number of type GFNumber
    * @param second  - number of type GFNumber
    * @return - the greatest common divisor
    */
    GFNumber gcd(const GFNumber& first, const GFNumber& second) const;

    /**
     * made this function non-recursive to avoid stackOverFlow (working with long numbers)
     * @param num1 - number of type long
     * @param num2 - number of type long
     * @param order - the field we want to do the calculation under.
     * @return - the greatest common divisor of num1 and num2 under the field (order)
     */
    static long gcdHelper(long num1, long num2, long order);

    /**
     * Getting k, and return GFNumber type, of k, from the current field
     * @param k - number in Z
     * @return - GFNumber, k with the current field
     */
    GFNumber createNumber(const long& k) const;

    /**
     * Destructor - freeing all allocated Memory.
     */
    ~GField() = default;
};

#include "GFNumber.h" /* this include should be at the end off the GField class, otherwise
                         it would be recursive debilitation */

#endif //CPPEX1_GFIELD_H
