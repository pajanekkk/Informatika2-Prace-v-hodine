#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>

using InnerMap = std::map<std::string, std::string>;
using Rules = std::map<std::string, InnerMap>;

Rules pravidla;
std::set<std::string> gold;

std::string trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
void parseRules(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Chyba: Soubor nelze otevřít: " + filename);
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t containPos = line.find(" bags contain ");
        if (containPos == std::string::npos)
            continue;
        std::string outerKey = line.substr(0, containPos);
        std::string contentsPart = line.substr(containPos + 14);
        contentsPart.pop_back();
        std::stringstream ssContents(contentsPart);
        std::string segment;
        while (std::getline(ssContents, segment, ','))
        {
            segment = trim(segment);
            std::stringstream ssSegment(segment);
            std::string sCount, adj, color;
            ssSegment >> sCount >> adj >> color;
            if (sCount == "no")
            {
                pravidla[outerKey]["other bags."] = "no";
            }
            else
            {
                std::string innerKey = adj + " " + color;
                pravidla[outerKey][innerKey] = sCount;
            }
        }
    }
}

void printRules()
{
    for (const auto &pair : pravidla)
    {
        const std::string &outer = pair.first;
        const InnerMap &contents = pair.second;
        std::cout << outer << " bags contain: ";
        for (const auto &contentPair : contents)
        {
            const std::string &inner = contentPair.first;
            const std::string &count = contentPair.second;
            std::cout << count << " " << inner << ", ";
        }
        std::cout << std::endl;
    }
}

bool canContainGold(const std::string &bagColor)
{
    const InnerMap &innerBags = pravidla[bagColor];
    for (const auto &pair : innerBags)
    {
        const std::string &innerBagsColor = pair.first;
        const std::string &count = pair.second;

        if (innerBagsColor == "shiny gold")
        {
            gold.insert(bagColor);
            return true;
        }
        if (innerBagsColor == "other bags.")
        {
            continue;
        }
        if (canContainGold(innerBagsColor))
        {
            gold.insert(bagColor);
            return true;
        }
    }
    return false;
}

int main()
{
    try
    {
        parseRules("rules.txt");
        printRules();

        // Check each bag if it can contain gold
        for (const auto &pair : pravidla)
        {
            canContainGold(pair.first);
        }

        // Print the result
        std::cout << "Number of bags that can contain shiny gold: " << gold.size() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}