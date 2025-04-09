#include "node.hpp"

// Function prototype for display_infix
void display_infix(const Node &node);

int main()
{
    std::vector<int> values = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};

    Node *root = create_node(5);
    for (int value : values)
    {
        root->insert(value);
    }

    display_infix(*root);
}