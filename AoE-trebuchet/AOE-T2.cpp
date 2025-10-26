#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string cisla[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int prevedNaCislo(string retezec, int pozice)
{
    for (int i = 0; i < 9; i++)
    {
        if (retezec.find(cisla[i], pozice) == pozice)
        {
            return i + 1;
        }
    }
}

int main()
{

    ifstream soubor("input.txt");
    string radek;
    int soucet = 0;
    string cislice;
    int suma = 0;

    if (!soubor.is_open())
    {
        cerr << "Soubor se nepodarilo otevrit" << endl;
        return 0;
    }
    else
    {
        while (getline(soubor, radek))
        {
            for (char znak : radek)
            {
                if (isdigit(znak))
                {
                    cislice += znak;
                    break;
                }
            }
            for (int i = radek.length() - 1; i >= 0; i--)
            {
                if (isdigit(radek[i]))
                {
                    cislice += radek[i];
                    break;
                }
            }
            suma += stoi(cislice);
        }
        cout << suma << endl;
    }
}