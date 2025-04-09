#include "main.hpp"

int main()
{
    /**
     * Exercice 1
     */

    std::string s{"Hello world IMAC"};
    size_t max{1024};
    size_t p{2};

    std::cout << folding_string_hash(s, max) << std::endl;
    std::cout << folding_string_ordered_hash(s, max) << std::endl;
    std::cout << polynomial_rolling_hash(s, p, max) << std::endl;

    const std::vector<int> expected_insect_counts{
        75,  // ClassicBee
        50,  // Ladybug
        100, // Butterfly
        20,  // Dragonfly
        400, // Ant
        150, // Grasshopper
        60,  // Beetle
        10,  // Wasp
        40,  // Caterpillar
        90,  // Spider
        5,   // GuimielBee
    };

    for (float proba : probabilities_from_count(expected_insect_counts))
    {
        std::cout << proba << std::endl;
    }
}