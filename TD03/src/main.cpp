#include <stack>
#include <utility>
#include <tuple>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

bool IsOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool is_floating(std::string const &s)
{
    return s.find('.') != std::string::npos;
}

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::vector<std::string> Expr_to_RPN(std::vector<std::string> const &s)
{
    std::stack<char> stack;
    std::vector<std::string> output;
    for (auto const &token : s)
    {
        if (token == "(")
        {
            stack.push('(');
        }
        else if (token == ")")
        {
            while (!stack.empty() && stack.top() != '(')
            {
                output.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.pop();
        }
        else if (IsOp(token[0]))
        {
            while (!stack.empty() && precedence(stack.top()) >= precedence(token[0]))
            {
                output.push_back(std::string(1, stack.top()));
                stack.pop();
            }
            stack.push(token[0]);
        }
        else
        {
            output.push_back(token);
        }
    }
    while (!stack.empty())
    {
        output.push_back(std::string(1, stack.top()));
        stack.pop();
    }
    return output;
}

int main()
{
    // Exercice 1 : notation polonaise inversée (NPI)
    std::string expr = "1 * 5 + 4 + (8 + 6) / (9 - 2)";
    std::vector<std::string> tokens = split_string(expr);
    std::vector<std::string> npi = Expr_to_RPN(tokens);

    for (auto const &token : npi)
    {
        std::cout << token << " ";
    }
}