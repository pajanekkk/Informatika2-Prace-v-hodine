#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::ifstream vstupniSoubor("data.txt");
    std::string radek;
    int patro = 0;
    int basementPos;

    if (vstupniSoubor.is_open())
    {
        while (std::getline(vstupniSoubor, radek))
        {
            std::cout << radek << std::endl;
        }

        for (int i = 0; i <= radek.length(); i++)
        {
            if (radek[i] == '(')
            {
                patro++;
            }
            else if (radek[i] == ')')
            {
                patro--;
            }
            if (patro == -1)
            {
                basementPos = i + 1;
            }
        }
        std::cout << "index " << basementPos << std::endl;

        vstupniSoubor.close();
    }
}