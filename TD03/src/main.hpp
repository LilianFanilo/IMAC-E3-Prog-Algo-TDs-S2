#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

void bubble_sort(std::vector<int> &vec)
{

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        // std::cout << vec[i] << std::endl;

        for (int j = 0; j < i; j++)
        {
            int first_number{vec[j]};
            int second_number{vec[j + 1]};

            std::cout << first_number << std::endl;
            std::cout << second_number << std::endl;

            if (j == i)
            {
                break;
            }

            if (first_number > second_number)
            {
                vec[j] = second_number;
                vec[j + 1] = first_number;
            }
        }
    }
};

// à continuer
void selection_sort(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        int first_number{vec[i]};
        int lowest_number{};

        for (size_t j = i + 1; j < vec.size(); j++)
        {

            int second_number{vec[j]};

            if (second_number < first_number)
            {
                lowest_number = second_number;
            }
        }

        vec[i] = lowest_number;
    }
};

size_t quick_sort_partition(std::vector<float> &vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> &vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> &vec)
{
    quick_sort(vec, 0, vec.size() - 1);
}

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right);

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (vec.size() % 2 == 0)
    {
        for (int i = left; i < vec.size() * 0.5 + 1; i++)
        {
            int first_number{i};
            int second_number{i + 1};

            for (size_t j = i; j < vec.size(); j++)
            {
                if (second_number < first_number)
                {
                    vec[i] = vec[j];
                }
            }

            std::cout << "g :" << vec[i] << ", " << std::endl;
        }

        for (int i = right; i > vec.size() * 0.5 + 1; i--)
        {
            int first_number{i};
            int second_number{i + 1};

            for (size_t j = i; j > vec.size(); j--)
            {
                if (second_number < first_number)
                {
                    vec[i] = vec[j];
                }
            }

            std::cout << "d :" << vec[i] << ", " << std::endl;
        }
    }
    // else
    // {
    //     for (size_t i = right; i < vec.size() * 0.5; i++)
    //     {
    //         /* code */
    //     }
    // }
};

void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}