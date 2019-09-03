//
// Created by Ori Frenkel on 28/08/2019.
//

#include "GField.h"
#include "GFNumber.h"
#include <iostream>

/**
 * Gets input to create 2 GFNumbers, and print some arithmetic of the number and their factorization
 * @return - success code 0,
 */
int main2()
{
    GFNumber _a, _b;
    std::cin >>  _a >> _b;


    if(std::cin.fail())
    {
        exit(1);
    }

    std::cout << (_a + _b) << "\n";
    std::cout << (_a - _b) << "\n";
    std::cout << (_b - _a) << "\n";
    std::cout << (_a * _b) << "\n";



    delete[] _a.printFactors();
    delete[] _b.printFactors();


    return 0;
}