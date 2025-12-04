#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <iterator>

using namespace std;

string nactiSoubor(const string &nazev)
{
    ifstream soubor(nazev);
    if (!soubor.is_open())
    {
        cerr << "CHYBA: Nelze otevrit soubor '" << nazev << "'." << endl;
        cerr << "Ujistete se, ze jste ho stahli (viz README.md)." << endl;
        return "";
    }

    // Využijeme iterátory pro načtení celého souboru naraz
    return string((istreambuf_iterator<char>(soubor)),
                  istreambuf_iterator<char>());
}

// funkce pro nalezeni slova robot + i, y, a, atd
void analyzujRoboty(const string &text)
{
    cout << "--- Analyza Robotu ---" << endl;
    regex reRoboty(R"(\bRobot\w*)");

    auto it = sregex_iterator(text.begin(), text.end(), reRoboty);
    auto konec = sregex_iterator();

    cout << "Pocet vyskytu slova s korenem 'Robot': " << distance(it, konec) << endl;
    cout << endl;
}
// funkce pro nalezeni prime reci (prvnit 5 vet)
void najdiPrimouRec(const string &text)
{
    cout << "--- Prima rec (prvnich 5) ---" << endl;

    regex reUvozovky(R"(\"([^\"]*)\")");

    auto it = sregex_iterator(text.begin(), text.end(), reUvozovky);
    auto konec = sregex_iterator();

    int pocitadlo = 0;
    for (; it != konec && pocitadlo < 5; ++it, ++pocitadlo)
    {
        // it->str(1) vraci obsah prvni zavorky (text uvnitr uvozovek)
        cout << pocitadlo + 1 << ". " << it->str(1) << endl;
    }
    cout << endl;
}

int main()
{
    cout << "Nacitam knihu..." << endl;
    string text = nactiSoubor("kniha.txt");

    if (text.empty())
    {
        return 1; // Konec programu, chyba
    }

    cout << "Kniha nactena. Velikost: " << text.length() << " znaku.\n"
         << endl;

    analyzujRoboty(text);
    najdiPrimouRec(text);

    return 0;
}