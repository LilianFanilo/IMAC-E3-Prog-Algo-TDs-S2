#include "node.hpp"

Node *create_node(int value)
{
    Node *new_node = new Node();
    new_node->value = value;
    return new_node;
}

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

void Node::insert(int value)
{
    if (value < this->value)
    {
        if (left == nullptr)
        {
            left = create_node(value);
        }
        else
        {
            left->insert(value);
        }
    }
    else if (value > this->value)
    {
        if (right == nullptr)
        {
            right = create_node(value);
        }
        else
        {
            right->insert(value);
        }
    }
}

int Node::height() const
{
    if (this->is_leaf() == true)
    {
        return 0;
    }
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return std::max(left_height, right_height) + 1;
}

void Node::delete_children()
{
    if (left != nullptr)
    {
        left->delete_children();
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const
{
    if (left != nullptr)
    {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right != nullptr)
    {
        right->display_infix();
    }
}

std::vector<Node const *> Node::prefix() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    if (left != nullptr)
    {
        auto left_nodes = left->prefix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right != nullptr)
    {
        auto right_nodes = right->prefix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
};

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
};

Node *&most_left(Node *&node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return most_left(node->left);
};

bool remove(Node *&node, int value)
{
    if (node == nullptr)
    {
        return false;
    }
    if (value < node->value)
    {
        return remove(node->left, value);
    }
    else if (value > node->value)
    {
        return remove(node->right, value);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr)
        {
            Node *temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node *temp = most_left(node->right);
            node->value = temp->value;
            remove(node->right, temp->value);
        }
        return true;
    }
}

void delete_tree(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}