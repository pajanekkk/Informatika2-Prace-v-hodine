#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream soubor("input.txt");
    string radek;
    int sum = 0;

    if (soubor.is_open())
    {
        while (getline(soubor, radek))
        {
            char prvni = 0, posledni = 0;
            for (char c : radek)
            {
                if (c >= '0' && c <= '9')
                {
                    if (!prvni)
                        prvni = c;
                    posledni = c;
                }
            }
            if (isdigit(prvni)) // pokud se nasla aspon jedna cislice
            {
                int val = (prvni - '0') * 10 + (posledni - '0');
                sum += val;
            }
        }
        cout << sum << endl;
    }
    else
    {
        cerr << "Nelze otevrit soubor" << endl;
    }
}