#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display()
{
    std::cout << numerator << "/" << denominator;
}

Fraction add(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

Fraction sub(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction mul(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction div(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

/**
 * @brief Exercice 1 : initialiser les opérateurs +, -, *, / pour les fractions
 */

// Fraction operator+(Fraction const &f1, Fraction const &f2)
// {
//     Fraction temp{
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator};
//     temp = simplify(temp);
//     return temp;
// }

// Fraction operator-(Fraction const &f1, Fraction const &f2)
// {
//     Fraction temp{
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator};
//     temp = simplify(temp);
//     return temp;
// }

// Fraction operator*(Fraction const &f1, Fraction const &f2)
// {
//     Fraction temp{
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator};
//     temp = simplify(temp);
//     return temp;
// }

// Fraction operator/(Fraction const &f1, Fraction const &f2)
// {
//     Fraction temp{
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator};
//     temp = simplify(temp);
//     return temp;
// }

/**
 * @brief Exercice 2 : Remplacer les display par des opérateurs <<
 */

std::ostream &operator<<(std::ostream &os, Fraction const &f)
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

/**
 * @brief Exercice 3 : initialiser les opérateurs de comparaison == et !=
 */

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

/**
 * @brief Exercice 4 : initialiser les opérateurs de comparaison <, <=, >, >=
 */

bool operator<(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return (f1 < f2) || (f1 == f2);
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return !(f1 <= f2);
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 < f2);
}

/**
 * @brief Exercice 5 : initialiser les opérateurs +=, -=, *=, /= pour les fractions
 */

Fraction &Fraction::operator+=(Fraction const &f)
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator *= f.denominator;

    *this = simplify(*this);

    return *this;
}

Fraction &Fraction::operator-=(Fraction const &f)
{
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator *= f.denominator;

    *this = simplify(*this);

    return *this;
}

Fraction &Fraction::operator*=(Fraction const &f)
{
    numerator *= f.numerator;
    denominator *= f.denominator;

    *this = simplify(*this);

    return *this;
}

Fraction &Fraction::operator/=(Fraction const &f)
{
    numerator *= f.denominator;
    denominator *= f.numerator;

    *this = simplify(*this);

    return *this;
}

Fraction operator+(Fraction const &f1, Fraction const &f2)
{
    Fraction result{f1};
    result += f2;
    return result;
}

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    Fraction result{f1};
    result -= f2;
    return result;
}

Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    Fraction result{f1};
    result *= f2;
    return result;
}

Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    Fraction result{f1};
    result /= f2;
    return result;
}

/**
 * @brief Exercice 6 : Conversion en float
 */

Fraction::operator float() const
{
    return static_cast<float>(numerator) / denominator;
}

/**
 * @brief Pour Aller plus loin
 */

Fraction operator+(Fraction const &f, unsigned int const i)
{
    Fraction result{i, 1};
    return result += f;
}

Fraction operator+(unsigned int const i, Fraction const &f)
{
    Fraction result{i, 1};
    return result += f;
}