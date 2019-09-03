//
// Created by Ori Frenkel on 27/08/2019.
//

#include "GFNumber.h"
// --------------------------------------------------------------------------------------
// This file contains the implementation of the class GFNumber.
// --------------------------------------------------------------------------------------

// ------------------ Access constructor ------------------------

/**
 * Copy - constructor
 * @param other - the object that we want to copy.
 */
GFNumber::GFNumber(const GFNumber &other)
{
    _field = other.getField();
    _n = other.getNumber();
}

/**
 *  Constructor.
 * @param field - the GField that we working on.
 * @param n - number in the field (n belong to mod (field.getOrder())
 */
GFNumber::GFNumber(long n, GField field):_field(field), _n(modulo(n, _field.getOrder()))
{

}

// ------------------ Access methods ------------------------
/**
 * Access method for the number (_n) value;
 * @return the number (_n)
 */
long GFNumber::getNumber() const
{
    return _n;
}

/**
 * Access method for the field (_field) object;
 * @return the field object
 */
GField GFNumber::getField() const
{
    return _field;
}

/**
 * Access method for the field (_field) object, set the current _field to the given field.
 * @param newField - the field to set to.
 */
void GFNumber::setField(GField newField)
{
    _field = newField;
}

/**
 * set the current number - _n to the given number
 * @param number - the number to set to.
 */
void GFNumber::setNumber(const long number)
{
    _n = modulo(number, _field.getOrder());
}

// ------------------ operators methods ------------------------

/**
 * should be a reference example : (a = b) = c; if it wouldn't be a reference it won't work
 * @param other - object that we want to make this object equals to.
 * @return - this object after the operation '='
 */
GFNumber &GFNumber::operator = (const GFNumber &other)
{
    _field = other.getField();
    _n = other.getNumber();
    return *this;
}

/**
 * overloading the operator '+='
 * @param other - the number that we want to add to the current number (of type GFNumber)
 * @return - the current number (after adding to it the other number)
 */
GFNumber &GFNumber::operator += (const GFNumber &other)
{
    assert(_field == other.getField());
    _n = modulo((_n + other.getNumber()), _field.getOrder());
    return *this;
}


/**
 * of course cant return constant reference, because after the function ends it will point to junk
 * overloading the operator '+'
 * @param other - the number we want to add to our (this).
 * @return the result of adding the current number (this) to the other number (type GFNumber)
 */
GFNumber GFNumber::operator + (const GFNumber &other) const
{
    assert(_field == other.getField());
    return GFNumber(modulo((_n + other.getNumber()), _field.getOrder()), _field);
}

/**
 * overloading the operator '-='
 * @param other - the number that we want to subtract from current number (this)
 * @return - the current number (this) after subtraction
 */
GFNumber &GFNumber::operator -= (const GFNumber &other)
{
    assert(_field == other.getField());
    _n = (modulo((_n - other.getNumber()), _field.getOrder()));
    return *this;
}

/**
 * overloading the operator '-'
 * @param other - the number that we want to subtract from the current number
 * @return - the result of subtraction of current number (this) and other number
 */
GFNumber GFNumber::operator - (const GFNumber &other) const
{
    assert(_field == other.getField());
    long _fieldOrder = _field.getOrder();
    return GFNumber(modulo((_n - other.getNumber()), _fieldOrder), _field);
}

/**
 * overloading the operator '*'
 * @param other - the number of type GFNumber that we want to multiply by current number (this)
 * @return - the result of the multiplication
 */
GFNumber GFNumber::operator * (const GFNumber &other) const
{
    assert(_field == (other.getField()));
    return GFNumber(modulo((_n * other.getNumber()), _field.getOrder()), _field);
}

/**
 * overloading the operator '*='
 * @param other - the number that we want to multiply (of type GFNumber) by this number
 * @return - current number (this) after multiplication
 */
GFNumber &GFNumber::operator *= (const GFNumber &other)
{
    assert(_field == (other.getField()));
    _n = modulo(_n * other.getNumber(), _field.getOrder());
    return *this;
}

/**
 * overloading the operator '%='
 * @param other - the number (of type GFNumber) that want to do modulo on (this modulo other)
 * @return - current number (this) after modulo operation
 */
GFNumber &GFNumber::operator %= (const GFNumber &other)
{
    assert(_field == (other.getField()));
    _n = modulo(_n % other.getNumber(), _field.getOrder());
    return *this;
}

/**
 * overloading the operator '%'
 * @param other - the number (of type GFNumber) that want to do modulo on (this modulo other)
 * @return - the result of the operation this modulo other
 */
GFNumber GFNumber::operator % (const GFNumber &other) const
{
    assert(_field == (other._field));
    return GFNumber(modulo(_n % other.getNumber(), _field.getOrder()), _field);
}

/**
 * overloading the operator '=='
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return - true if this and other are the same, false otherwise
 */
bool GFNumber::operator == (const GFNumber &other) const
{
    if(_field == other.getField() && _n == other.getNumber())
    {
        return true;
    }
    return false;
}

/**
 * overloading the operator '!='
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return
 */
bool GFNumber::operator != (const GFNumber &other) const
{
    return (!(GFNumber::operator==(other)));
}

/**
 * overloading the operator '>'
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return - true if current number bigger than other number, false otherwise
 */
bool GFNumber::operator > (const GFNumber &other) const
{
    assert(_field == other.getField());
    if(_n > other.getNumber())
    {
        return true;
    }
    return false;
}

/**
 * overloading the operator '<'
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return - true if current number smaller than other number, false otherwise
 */
bool GFNumber::operator < (const GFNumber &other) const
{
    assert(_field == other.getField());
    if(_n < other.getNumber())
    {
        return true;
    }
    return false;
}

/**
 * overloading the operator '>='
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return - true if current number bigger or equals to other number, false otherwise
 */
bool GFNumber::operator >= (const GFNumber &other) const
{
    assert(_field == other.getField());
    if(_n >= other.getNumber())
    {
        return true;
    }
    return false;
}

/**
 * overloading the operator '<='
 * @param other - the number (of type GFNumber) that we want to check if the same as current num
 * @return - true if current number smaller or equals to other number, false otherwise
 */
bool GFNumber::operator <= (const GFNumber &other) const
{
    assert(_field == other.getField());
    if(_n <= other.getNumber())
    {
        return true;
    }
    return false;
}

/**
 * print GFNumber - number, char of the field, degree of the field
 * @param output - output stream
 * @param obj - object we want to print to output stream
 * @return ostream of the obj, printable
 */
std::ostream &operator << (std::ostream &output, GFNumber const &obj)
{
    output << obj.getNumber() << " GF(" << obj.getField().getChar() << "**" << \
              obj.getField().getDegree() << ")" ;
    return output;
}

/**
 * adding the functionality to input the GFNumber object
 * @param obj - object that we want to be able to input from the input stream
 * @return - input stream
 */
std::istream &operator >> (std::istream &input, GFNumber &obj)
{
    long _n, _p, _l;
    input >> _n >>  _p >> _l;
    obj.setField(GField(_p, _l));
    obj.setNumber(_n);
    return input;
}

/**
 * overloading the operator '+='
 * @param rparam - the number (of type long) that we want to add the the current number
 * @return current number (after adding to it the other number)
 */
GFNumber &GFNumber::operator += (const long &rparam)
{
    _n = modulo((_n + rparam), _field.getOrder());
    return *this;
}

/**
 * overloading the operator '+'
 * @param rparam - the number we want to add to (this) (type long)
 * @return - the result of adding the current number (this) to the other number (type long)
 */
GFNumber GFNumber::operator + (const long& rparam) const
{
    return GFNumber(modulo((_n + rparam), _field.getOrder()), _field);
}

/**
 * overloading the operator '-='
 * @param rparam the number that we want to subtract (of type long) from current number (this)
 * @return the current number (this) after subtraction
 */
GFNumber &GFNumber::operator -= (const long &rparam)
{
    _n = modulo((_n - rparam), _field.getOrder());
    return *this;
}

/**
 * overloading the operator '-'
 * @param rparam - the number that we want to subtract (of type long) from current number
 * @return - the result of subtraction of current number (this) and other number
 */
GFNumber GFNumber::operator - (const long &rparam) const
{
    const long tempRparam = modulo(rparam, _field.getOrder());
    return GFNumber(modulo((_n - tempRparam), _field.getOrder()), _field);
}

/**
 * overloading the operator '*='
 * @param rparam -  the number that we want to multiply (of type long) by this number
 * @return - current number (this) after multiplication
 */
GFNumber &GFNumber::operator *= (const long &rparam)
{
    const long tempRparam = modulo(rparam, _field.getOrder());
    _n = modulo((_n * tempRparam), _field.getOrder());
    return *this;
}

/**
 * overloading the operator '*'
 * @param rparam - the number (of type long) that we want to multiply by current number (this)
 * @return - the result of the multiplication
 */
GFNumber GFNumber::operator * (const long &rparam) const
{
    const long tempRparam = modulo(rparam, _field.getOrder());
    return GFNumber(modulo((_n * tempRparam), _field.getOrder()), _field);
}

/**
 * overloading the operator '%='
 * @param rparam - the number (of type long) that want to do modulo on (this modulo other)
 * @return - current number (this) after modulo operation
 */
GFNumber &GFNumber::operator %= (const long &rparam)
{
    assert(rparam != 0);
    const long tempRparam = modulo(rparam, _field.getOrder());
    _n = modulo(_n, modulo(tempRparam, _field.getOrder()));
    return *this;
}

/**
 * overloading the operator '%'
 * @param rparam - the number (of type long) that want to do modulo on (this modulo other)
 * @return - the result of the operation this modulo other
 */
GFNumber GFNumber::operator % (const long &rparam) const
{
    assert(rparam != 0);
    const long tempRparam = modulo(rparam, _field.getOrder());
    return GFNumber(modulo((_n % tempRparam), _field.getOrder()), _field);
}

// ------------------ Other methods ------------------------

/**
 * deleting the old array, and dynamically create new array (and copy the old array)
 * @param oldArr - the old array
 * @param newSize - the new array size that we want.
 * @return - same array with the new size (allocating new one and delete the old one)
 */
GFNumber* _allocateAndDeleteArr(GFNumber* oldArr, long newSize)
{
    GFNumber *arr = new GFNumber[newSize];
    // newSize - 2 is the last index of the old array.
    for(int i = 0; i < newSize - 1; i++)
    {
        arr[i] = oldArr[i];
    }
    delete[] (oldArr);
    return arr;
}

/**
 * brute force search for the prime factorization.
 * @return - array of the prime factor of the current (this) number
 */
GFNumber *GFNumber::_directSearchFactorization(long n, int *sizeOfArray) const
{
    GFNumber *newArr = nullptr;
    newArr = new GFNumber[1];
    long newSize = 0;
    long i = 2;
    while(i <= floorl(sqrtl(n)))
    {
        if((n % i) == 0)
        {
            newSize++;
            newArr = _allocateAndDeleteArr(newArr, newSize);
            *sizeOfArray = static_cast<int>(newSize);
            newArr[newSize - 1] = GFNumber(i, _field); //newSize - 1, is the last index in the array
            n = static_cast<long>(n / (floorl(i)));
        }
        else
        {
            i++;
        }
    }
    if( n > 1)
    {
        newSize++;
        newArr = _allocateAndDeleteArr(newArr, newSize);
        *sizeOfArray = static_cast<int>(newSize);
        newArr[newSize - 1] = GFNumber(n, _field); // newSize - 1, is the last index in the array
    }
    return newArr;
}

/**
 * Using this in pollardRhoHelper
 * @param x - number
 * @param field - the field the number is on.
 * @return - function of x according to the pseudo code of pollardRho
 */
long _functionX(const long x, const long field)
{
    return (((x * x) + 1) % field) ;
}

/**
 * rand on long numbers, the number will be min <= x <= max - works only on positive number
 * (unsigned long)
 * @param min - min bound to generate the random
 * @param max - max bound to generate the random
 * @return - a random number between min and max
 * Note : this code is take from stackoverflow, as we didn't learned about random_device nor mt19937
 */
long _lRand(const long min, const long max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long long> dis((unsigned long long int) min, \
                                                           (unsigned long long int) max);
    return static_cast<long>(dis(gen));
}

/**
 * implementing the pseudo code of pollardRho (as given in the exercise)
 * @param n - The number that we want to find one of its prime factors
 * @return - one of the prime factor of the number(or scalar*prime), -1 on failure
 */
long GFNumber::_pollardRhoHelper(const long n) const
{
    // The algorithm work only on positive and even (mod 2 = 0 ) numbers.
    if(n <= 0 || n % 2 == 0)
    {
        return -1;
    }

    long x = _lRand(1, n-2);
    long y = x;
    long p = 1;
    while(p == 1)
    {
        x = _functionX(x, n);
        y = _functionX(_functionX(y, n), n);
        p = GField::gcdHelper(labs(x - y), n, n);
    }
    if(p == n || p == 0)
    {
        return -1;
    }
    return p;

}

/**
 * using _pollardRhoHelper, find all of the prime factors of the current number
 * @return - an array of all the prime factors, in case of failure nullptr
 */
GFNumber *GFNumber::_pollardRho(long n, int* sizeOfArr) const
{
    GFNumber *firstArray = nullptr;
    firstArray = new GFNumber[1];
    int firstArraySize = 0;
    int secondArraySize = 0;
    long prime = -1;
    bool first = true;

    while(!GField::isPrime(n))
    {
        prime = _pollardRhoHelper(n); // the actual implementation of Pollard Rho Algorithm

        // case that pollard rho failed
        if((prime == -1 || prime == 0) && first)
        {
            //std::cout <<" scallar 1\n";
            *sizeOfArr = 0;
            return firstArray;
        }
        // pollard rho failed, but after succeed before
        else if(prime == -1 && first == false)
        {
            GFNumber *second_arr = nullptr;
            // continue from that point with brute force approach
            second_arr = _directSearchFactorization(n, &secondArraySize);
            firstArray = _mergeArrays(firstArray, firstArraySize, second_arr, secondArraySize);
            firstArraySize += secondArraySize;
            *sizeOfArr = firstArraySize;
            return firstArray;

        }
        else
        {
            if(GField::isPrime(prime))
            {
                firstArraySize++;
                firstArray = _allocateAndDeleteArr(firstArray, firstArraySize);
                firstArray[firstArraySize - 1] = GFNumber(prime, _field);
            }
            // case when Pollard Rho Helper return scalar * prime and not prime.
            else
            {
                // creating array of primes from the (scalar*prime) and merging it with current arr
                int sizeFactorizationArray = 0;
                GFNumber *factroizeThePrimeArray = _directSearchFactorization(prime, \
                                                    &sizeFactorizationArray);
                firstArray = _mergeArrays(firstArray, firstArraySize, factroizeThePrimeArray, \
                                          sizeFactorizationArray);
                firstArraySize += sizeFactorizationArray;
            }
            n = n / prime;
            first = false;
        }

    }
    firstArraySize++;
    firstArray = _allocateAndDeleteArr(firstArray, firstArraySize);
    firstArray[firstArraySize - 1] = GFNumber(n, _field);
    *sizeOfArr = firstArraySize;
    return firstArray;

}

/**
 * return an array of the prime factorization of the number (_n)
 * @param sizeOfArr - pointer to put inside the size of the array
 * @return - the array (its the user responsibility to delete the array)
 */
GFNumber *GFNumber::getPrimeFactors(int *sizeOfArr) const
{
    GFNumber *firstArray = nullptr;
    int firstArraySize = 0;
    bool needToMerge = false;
    GFNumber *secondArray = nullptr;
    int secondArraySize = 0;
    long n = _n;


    // edge cases:
    if(_n == 0 || _n == 1 || getIsPrime())
    {
        firstArray = new GFNumber[0];
        *sizeOfArr = 0;
        return firstArray;
    }

    // if the number is even, dividing by 2(= prime) until its no even
    if(GFNumber::isEven(_n))
    {
        needToMerge = true;
    }
    while(GFNumber::isEven(n))
    {
        secondArraySize++;
        n = n / 2;
    }
    // creating array of 2 - contains 2 numbers, the times we divided n with 2s
    if(needToMerge)
    {
        secondArray = new GFNumber[secondArraySize];
        for(long i = 0; i < secondArraySize; i++)
        {
            secondArray[i] = GFNumber(2, _field);
        }
    }

    // case when we got which factorization to 2*2...2*2
    if(n == 1 && needToMerge)
    {
        *sizeOfArr = secondArraySize;
        return secondArray;
    }

    firstArray = _pollardRho(n, &firstArraySize);
    // in case pollard rho failed on first attempt, continue with brute force
    if(firstArraySize == 0)
    {
        delete[] firstArray;
        firstArray = _directSearchFactorization(_n, &firstArraySize);
        *sizeOfArr = firstArraySize;
        return firstArray;
    }

    if(needToMerge)
    {
        firstArray = _mergeArrays(secondArray, secondArraySize, firstArray, firstArraySize);
        firstArraySize += secondArraySize;
    }
    *sizeOfArr = firstArraySize;
    return firstArray;
}

/**
* The built modulo doesn't working well on negative numbers
* @param number - the number
 * @param order - modulo
* @return (number % order)
*/
long GFNumber::modulo(const long number, const long order)
{
    if(number > 0)
    {
        return (number % order);
    }
    return ((number % order ) + order) % order;
}

/**
 *
 * @param firstArray - array of GFNumber
 * @param sizeFirst - The size of the firstArray (the number of objects it contain)
 * @param secondArray - array of GFNumber
 * @param sizeSecond - The size of the secondArray (the number of objects it contain)
 * @return - New array that contains both firstArray and secondArray numbers.
 */
GFNumber *GFNumber::_mergeArrays(GFNumber *firstArray, const long sizeFirst, GFNumber *secondArray,
                                 const long sizeSecond)
{
    GFNumber* mergedArray = new GFNumber[sizeFirst + sizeSecond];
    long i = 0;
    for(; i < sizeFirst; i++)
    {
        mergedArray[i] = firstArray[i];
    }


    for(int j = 0; i < (sizeSecond + sizeFirst); i++, j++)
    {
        mergedArray[i] = secondArray[j];
    }

    delete[] firstArray;
    delete[] secondArray;
    return mergedArray;

}

/**
 * Getting a number (n) and return true if it even number
 * @param n - number of type long
 * @return true if n is even, false otherwise
 */
const bool GFNumber::isEven(const long& n)
{
    if(n % 2 == 0)
    {
        return true;
    }
    return false;
}

/**
* print the factorization of the number, should be called after getPrimeFactors.
*/
GFNumber* GFNumber::printFactors() const
{
    std::string str;
    GFNumber *arr = nullptr;
    int sizeOfArr = 0;
    arr = getPrimeFactors(&sizeOfArr);

    str.append(std::to_string(_n) + "=");
    // edge case, the number itself is already a prime number
    if(sizeOfArr == 0)
    {
        str.append(std::to_string(_n) + "*1");
        std::cout << str << "\n";
        return arr;
    }
    bool first = true;

    for(int i = 0; i < sizeOfArr; i++)
    {
        if(first)
        {
            str.append(std::to_string(arr[i].getNumber()));
            first = false;
        }
        else
        {
            str.append("*" + std::to_string(arr[i].getNumber()));
        }
    }
    std::cout << str << "\n";
    return arr;
}

/**
 * Checking if the current GFNumber is prime
 * @return true if the current number is prime, false otherwise
 */
bool GFNumber::getIsPrime() const
{
    if(GField::isPrime(_n))
    {
        return true;
    }
    return false;
}










