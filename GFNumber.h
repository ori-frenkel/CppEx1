//
// Created by Ori Frenkel  on 27/08/2019.
//

#ifndef CPPEX1S_GFNUMBER_H
#define CPPEX1S_GFNUMBER_H

class GField; // forward declaration

#include "GField.h"
#include <cassert>
#include <random>

/**
 * This class represnt a number in Galua's field
 */
class GFNumber
{
private:
    GField _field; /**< The field the number is in. */
    long _n; /**< The number */

    /**
     *
     * @param firstArray - array of GFNumber
     * @param sizeFirst - The size of the firstArray (the number of objects it contain)
     * @param secondArray - array of GFNumber
     * @param sizeSecond - The size of the secondArray (the number of objects it contain)
     * @return - New array that contains both firstArray and secondArray numbers.
     */
    static GFNumber* _mergeArrays(GFNumber* firstArray, const long sizeFirst, \
                                  GFNumber *secondArray, const long sizeSecond);

    /**
     * brute force search for the prime factorization.
     * @return - array of the prime factor of the current (this) number
     */
    GFNumber* _directSearchFactorization(long n, int *sizeOfArray) const;

    /**
     * implementing the pseudo code of pollardRho (as given in the exercise)
     * @param n - The number that we want to find one of its prime factors
     * @return - one of the prime factor of the number(or scalar*prime), -1 on failure
     */
    long _pollardRhoHelper(const long n) const;

    /**
     * using _pollardRhoHelper, find all of the prime factors of the current number
     * @return - an array of all the prime factors, in case of failure nullptr
     */
    GFNumber* _pollardRho(long n, int *sizeOfArray) const;



public:
    /**
    * The built modulo doesn't working well on negative numbers
    * @param number - the number
     * @param order - modulo
    * @return (number % order)
    */
    static long modulo(long number, long order);

    /**
     * Getting a number (n) and return true if it even number
     * @param n - number of type long
     * @return true if n is even, false otherwise
     */
    static const bool isEven(const long& n);

    /**
     *  Constructor.
     * @param field - the GField that we working on.
     * @param n - number in the field (n belong to mod (field.getOrder())
     */
    GFNumber(long n = 0, GField field = GField());

    /**
     * Copy - constructor
     * @param other - the object that we want to copy.
     */
    GFNumber(const GFNumber& other);

    /**
     * Access method for the number (_n) value;
     * @return the number (_n)
     */
    long getNumber() const;

    /**
     * set the current number - _n to the given number
     * @param number - the number to set to.
     */
    void setNumber(const long number);

    /**
     * Access method for the field (_field) object;
     * @return the field object
     */
    GField getField() const;

    /**
     * Access method for the field (_field) object, set the current _field to the given field.
     * @param newField - the field to set to.
     */
    void setField(GField newField);

    /**
     * calculating and returning array of all of the prime factors
     * @param sizeOfArr - pointer to put in the size of the array (the number of GFNumber is array)
     * @return - an array of GFNumber that contains all of the prime factor of the number (_n)
     */
    GFNumber* getPrimeFactors(int *sizeOfArr) const;

    /**
     * Checking if the current GFNumber is prime
     * @return true if the current number is prime, false otherwise
     */
    bool getIsPrime() const;

    /**
    * print the factorization of the number, should be called after getPrimeFactors.
    */
    GFNumber* printFactors() const;

    // should be a reference example : (a = b) = c; if it wouldn't be a reference it won't work
    /**
     * @param other - object that we want to make this object equals to.
     * @return - this object after the operation '='
     */
    GFNumber& operator = (const GFNumber& other);

    /**
     * overloading the operator '+='
     * @param other - the number that we want to add to the current number (of type GFNumber)
     * @return - the current number (after adding to it the other number)
     */
    GFNumber& operator += (const GFNumber& other);

    /**
     * overloading the operator '+='
     * @param rparam - the number (of type long) that we want to add the the current number
     * @return current number (after adding to it the other number)
     */
    GFNumber& operator += (const long& rparam);

    /**
     * overloading the operator '+'
     * @param other - the number we want to add to our (this).
     * @return the result of adding the current number (this) to the other number (type GFNumber)
     */
    GFNumber operator + (const GFNumber& other) const;

    /**
     * overloading the operator '+'
     * @param rparam - the number we want to add to (this) (type long)
     * @return - the result of adding the current number (this) to the other number (type long)
     */
     GFNumber operator + (const long& rparam) const;

    /**
     * overloading the operator '-='
     * @param other - the number that we want to subtract from current number (this)
     * @return - the current number (this) after subtraction
     */
    GFNumber& operator -= (const GFNumber& other);

    /**
     * overloading the operator '-='
     * @param rparam the number that we want to subtract (of type long) from current number (this)
     * @return the current number (this) after subtraction
     */
    GFNumber& operator -= (const long& rparam) ;

    /**
     * overloading the operator '-'
     * @param other - the number that we want to subtract from the current number
     * @return - the result of subtraction of current number (this) and other number
     */
    GFNumber operator - (const GFNumber& other) const;

    /**
     * overloading the operator '-'
     * @param rparam - the number that we want to subtract (of type long) from current number
     * @return - the result of subtraction of current number (this) and other number
     */
    GFNumber operator - (const long& rparam) const;

    /**
     * overloading the operator '*='
     * @param other - the number that we want to multiply (of type GFNumber) by this number
     * @return - current number (this) after multiplication
     */
    GFNumber& operator *= (const GFNumber& other);

    /**
     * overloading the operator '*='
     * @param rparam -  the number that we want to multiply (of type long) by this number
     * @return - current number (this) after multiplication
     */
    GFNumber& operator *= (const long& rparam);

    /**
     * overloading the operator '*'
     * @param other - the number of type GFNumber that we want to multiply by current number (this)
     * @return - the result of the multiplication
     */
    GFNumber operator * (const GFNumber& other) const;

    /**
     * overloading the operator '*'
     * @param rparam - the number (of type long) that we want to multiply by current number (this)
     * @return - the result of the multiplication
     */
    GFNumber operator * (const long& rparam) const;

    /**
     * overloading the operator '%='
     * @param other - the number (of type GFNumber) that want to do modulo on (this modulo other)
     * @return - current number (this) after modulo operation
     */
    GFNumber& operator %= (const GFNumber& other);

    /**
     * overloading the operator '%='
     * @param rparam - the number (of type long) that want to do modulo on (this modulo other)
     * @return - current number (this) after modulo operation
     */
    GFNumber& operator %= (const long& rparam);

    /**
     * overloading the operator '%'
     * @param other - the number (of type GFNumber) that want to do modulo on (this modulo other)
     * @return - the result of the operation this modulo other
     */
    GFNumber operator % (const GFNumber& other) const;

    /**
     * overloading the operator '%'
     * @param rparam - the number (of type long) that want to do modulo on (this modulo other)
     * @return - the result of the operation this modulo other
     */
    GFNumber operator % (const long& rparam) const;

    /**
     * overloading the operator '=='
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return - true if this and other are the same, false otherwise
     */
    bool operator == (const GFNumber& other) const;

    /**
     * overloading the operator '!='
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return
     */
    bool operator != (const GFNumber& other) const;

    /**
     * overloading the operator '>'
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return - true if current number bigger than other number, false otherwise
     */
    bool operator > (const GFNumber& other) const;

    /**
     * overloading the operator '<'
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return - true if current number smaller than other number, false otherwise
     */
    bool operator < (const GFNumber& other) const;

    /**
     * overloading the operator '>='
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return - true if current number bigger or equals to other number, false otherwise
     */
    bool operator >= (const GFNumber& other) const;

    /**
     * overloading the operator '<='
     * @param other - the number (of type GFNumber) that we want to check if the same as current num
     * @return - true if current number smaller or equals to other number, false otherwise
     */
    bool operator <= (const GFNumber& other) const;

    /**
     * print GFNumber - number, char of the field, degree of the field
     * @param output - output stream
     * @param obj - object we want to print to output stream
     * @return ostream of the obj, printable
     */
    friend std::ostream& operator << (std::ostream& output, GFNumber const & obj);

    /**
     * adding the functionality to input the GFNumber object
     * @param obj - object that we want to be able to input from the input stream
     * @return - input stream
     */
    friend std::istream& operator >> (std::istream&, GFNumber &obj);

    /**
     * Destructor, free the prime factor array.
     */

    ~GFNumber() = default;

};


#endif //CPPEX1_GFNUMBER_H
