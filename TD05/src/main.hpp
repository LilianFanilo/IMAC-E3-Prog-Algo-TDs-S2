#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <random>
#include <iterator>

size_t folding_string_hash(std::string const &s, size_t max)
{
    size_t hash{};
    for (char c : s)
    {
        hash += c;
    }

    return hash % max;
};

size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    size_t hash{};
    int i{};

    for (char c : s)
    {
        hash += c * (i + 1);
        i++;
    }

    return hash % max;
};

size_t polynomial_rolling_hash(const std::string &s, size_t p, size_t max)
{
    int power{1};

    size_t hash{};

    for (char c : s)
    {
        power *= p;
        hash += c * power;
    }

    return hash % max;
};

enum class Insect
{
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::vector<Insect> insect_values{
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}};

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const &insect_probabilities,
    const unsigned int seed = std::random_device{}())
{
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex{std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine)};

    std::vector<std::pair<Insect, int>> observations{};
    observations.reserve(number_of_observations);

    for (size_t i{0}; i < number_of_observations; ++i)
    {
        size_t const random_insect_index{randInsectIndex()};
        Insect const random_insect{insect_values[random_insect_index]};

        // If we have already seen the same insect, increment the count on the last observation
        auto &previous_observation{observations.back()};
        if (previous_observation.first == random_insect)
        {
            previous_observation.second++;
            i -= 1;
        }
        else
        {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const &counts)
{
    std::vector<float> probabilities(counts.size(), 0.0f);
    int total_count = std::accumulate(counts.begin(), counts.end(), 0);

    for (size_t i = 0; i < counts.size(); ++i)
    {
        probabilities[i] = static_cast<float>(counts[i]) / total_count;
    }

    return probabilities;
}