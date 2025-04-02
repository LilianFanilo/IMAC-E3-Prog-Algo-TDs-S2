#include "main.hpp"

int main()
{
    // std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // if (is_sorted(array))
    // {
    //     std::cout << "Le tableau est trié" << std::endl;
    // }
    // else
    // {
    //     std::cout << "Le tableau n'est pas trié" << std::endl;
    // }

    /**
     * Ex 1 Bubble sort
     */

    std::vector<int> array_test{5, 9, 3, 4, 2, 6, 7, 8, 1};

    // bubble_sort(array_test);
    // for (size_t i = 0; i < array_test.size(); i++)
    // {
    //     std::cout << array_test[i] << ", ";
    // }

    // selection_sort(array_test);
    // for (size_t i = 0; i < array_test.size(); i++)
    // {
    //     std::cout << array_test[i] << ", ";
    // }

    merge_sort(array_test);
    for (size_t i = 0; i < array_test.size(); i++)
    {
        std::cout << array_test[i] << ", ";
    }
}