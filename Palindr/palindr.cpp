#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string &s)
{
    int leva = 0;
    if (s.empty())
        return true;
    int prava = s.size() - 1;

    if (leva >= prava)
    {
        return true;
    }
    else if (<condition>)
    {
        /* code */
    }

    return true;
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << (isPalindrome(line) ? "true\n" : "false\n");
    }
    return 0;
}