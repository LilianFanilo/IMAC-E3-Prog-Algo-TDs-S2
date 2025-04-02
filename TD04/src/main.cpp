#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "main.hpp"

std::vector<std::string> split_string(std::string const &str)
{
    std::vector<std::string> v_text{};
    std::string text{};

    for (char word : str)
    {
        if (word == ' ')
        {
            v_text.push_back(text);
        }
        else
        {
            text += word;
        }
    }
}

int main()
{
    /**
     *  Exercice 1 (Vector and Algorithm)
     */

    // // Remplir un std::vector avec des nombres entiers aléatoires compris entre 0 et 100.
    // std::vector<int> v{
    //     0,
    //     10,
    //     96,
    //     96,
    //     96,
    //     86,
    //     37,
    //     100,
    //     53,
    //     53,
    // };
    // std::vector<int>::iterator end_iterator{v.end()};

    // // Utiliser les itérateurs et les méthodes begin et end pour afficher les valeurs du vecteur à l'aide d'une boucle for.
    // for (std::vector<int>::iterator it{v.begin()}; it != end_iterator; ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // // Chercher si un nombre saisi par l'utilisateur est présent dans le vecteur à l'aide de la fonction std::find et afficher un message adapté.
    // int user_input{};
    // std::cout << "Saisissez un nombre entre 0 et 100 :";
    // std::cin >> user_input;

    // auto it_search{std::find(v.begin(), v.end(), user_input)};

    // if (it_search != v.end())
    // {
    //     std::cout << "Nombre disponible : " << *it_search << std::endl;

    //     // Utiliser la fonction std::count pour compter le nombre d'occurrences d'un nombre entier dans le vecteur.
    //     long long int occurrences{std::count(v.begin(), v.end(), user_input)};

    //     std::cout << "Le nombre " << user_input << " a une occurrence de " << occurrences << std::endl;
    // }
    // else
    // {
    //     std::cout << "Nombre non disponible." << std::endl;
    // }

    // // Utiliser la fonction std::sort pour trier le vecteur.
    // std::sort(v.begin(), v.end());

    // std::cout << "Tri du tableau :" << std::endl;

    // for (int element : v)
    // {
    //     std::cout << element << " ";
    // }
    // std::cout << std::endl;

    // int sum{std::accumulate(v.begin(), v.end(), 0, [](int acc, int current_element)
    //                         { return acc + current_element; })};
    // std::cout << sum << std::endl;

    /**
     * Exercice 2 (String)
     */

    // Écrire une fonction (à l'aide des fonctions std::find et std::distance) qui prendre en paramètre une référence constante sur une std::string et qui retourne le nombre de lettres du premier mot de la phrase.
    std::string phrase{"Bonjour tout le monde"};

    auto const is_space = [](char letter)
    {
        return letter == ' ';
    };

    // Trouver le premier espace dans la phrase
    auto it = std::find_if(phrase.begin(), phrase.end(), is_space);

    // Calculer la longueur du premier mot
    int longueur = std::distance(phrase.begin(), it);

    std::cout << "Le premier mot a " << longueur << " lettres." << std::endl;

    // Écrire une fonction qui permet de découper la phrase en mots et de les stocker dans un std::vector de std::string.
    split_string(phrase);
}