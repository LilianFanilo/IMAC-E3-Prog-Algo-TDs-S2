#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    /**
     * @brief Exercice 2 : Remplacer les display par des opérateurs <<
     */

    std::cout << "f1 = " << f1;
    // f1.display();
    std::cout << " f2 = " << f2;
    // f2.display();
    std::cout << std::endl;

    /**
     * @brief Exercice 1 : Remplacer les appels de fonctions par des opérateurs
     */

    // Fraction f3{add(f1, f2)};
    Fraction f3{f1 + f2};

    bool sameFractions{f1 == f2};
    bool notSameFractions{f1 != f2};
    bool F1IsLessThanF2{f1 < f2};
    bool F1IsLessOrEqualThanF2{f1 <= f2};
    bool F1IsGreaterThanF2{f1 > f2};
    bool F1IsGreaterOrEqualThanF2{f1 >= f2};

    std::cout << "add(f1, f2) = " << f3;
    // f3.display();

    std::cout << std::endl
              << "sub(f1, f2) = " << f1 - f2;
    // (sub(f1, f2)).display();
    // ((f1 - f2)).display();

    std::cout << std::endl
              << "mul(f1, f2) = " << f1 * f2;
    // (mul(f1, f2)).display();
    // ((f1 * f2)).display();

    std::cout << std::endl
              << "div(f1, f2) = " << f1 / f2;
    // ((f1 / f2)).display();

    std::cout << std::endl
              << "add(1/6, 2/6) = " << (Fraction{1, 6} + Fraction{2, 6});
    // (add({1, 6}, {2, 6})).display();

    /**
     * @brief Exercice 3 : initialiser les opérateurs de comparaison == et !=
     */

    if (sameFractions)
    {
        std::cout << std::endl
                  << "f1 et f2 sont egales";
    }

    if (notSameFractions)
    {
        std::cout << std::endl
                  << "f1 et f2 sont differentes";
    }

    /**
     * @brief Exercice 4 : initialiser les opérateurs de comparaison <, <=, >, >=
     */

    if (F1IsLessThanF2)
    {
        std::cout << std::endl
                  << "f1 est inferieure a f2";
    }

    if (F1IsLessOrEqualThanF2)
    {
        std::cout << std::endl
                  << "f1 est inferieure ou egale a f2";
    }

    if (F1IsGreaterThanF2)
    {
        std::cout << std::endl
                  << "f1 est superieure a f2";
    }

    if (F1IsGreaterOrEqualThanF2)
    {
        std::cout << std::endl
                  << "f1 est superieure ou egale a f2";
    }

    /**
     * @brief Exercice 6 : Conversion en float
     */

    float d1{static_cast<float>(f1)};
    std::cout << std::endl
              << "d1 = " << d1;

    /**
     * @brief Pour aller plus loin
     */

    Fraction f4{1, 2};
    unsigned int i{2};
    Fraction f5{f4 + i};

    std::cout << std::endl
              << "f5 = " << f5;

    return 0;
}