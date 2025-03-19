#pragma once
#include <iostream>

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;

    void display();

    /**
     * @brief Exercice 5 : initialiser les opérateurs +=, -=, *=, /= pour les fractions
     */

    Fraction &operator+=(Fraction const &f);
    Fraction &operator-=(Fraction const &f);
    Fraction &operator*=(Fraction const &f);
    Fraction &operator/=(Fraction const &f);

    /**
     * @brief Exercice 6 : Conversion en float
     */

    operator float() const;
};

// Fraction add(Fraction const &f1, Fraction const &f2);
// Fraction sub(Fraction const &f1, Fraction const &f2);
// Fraction mul(Fraction const &f1, Fraction const &f2);
// Fraction div(Fraction const &f1, Fraction const &f2);

/**
 * @brief Exercice 1 : initialiser les opérateurs +, -, *, / pour les fractions
 */

Fraction operator+(Fraction const &f1, Fraction const &f2);
Fraction operator-(Fraction const &f1, Fraction const &f2);
Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);

/**
 * @brief Exercice 2 : Remplacer les display par des opérateurs <<
 */

std::ostream &operator<<(std::ostream &os, Fraction const &f);

/**
 * @brief Exercice 3 : initialiser les opérateurs de comparaison == et !=
 */

bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);

/**
 * @brief Exercice 4 : initialiser les opérateurs de comparaison <, <=, >, >=
 */

bool operator<(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);