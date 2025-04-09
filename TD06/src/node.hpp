#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <random>
#include <iterator>
#include <stack>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    // Exercice 2
    bool is_leaf() const;

    // Exercice 3
    void insert(int value);

    // Exercice 4
    int height() const;

    // Exercice 5
    void delete_children();

    // Exercice 6
    void display_infix() const;

    // Exercice 7
    std::vector<Node const *> prefix() const;
};

// Exercice 1
Node *create_node(int value);

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left);

void pretty_print_left_right(Node const &node);

// Exercice 9
Node *&most_left(Node *&node);

// Exercice 10
bool remove(Node *&node, int value);

// Exercice 11
void delete_tree(Node *node);