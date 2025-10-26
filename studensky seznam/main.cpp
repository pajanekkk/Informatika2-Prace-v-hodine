#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Student
{
    int id;
    string jmeno;
    double prumer;
};
struct Node
{
    Student data;
    Node *dalsi;
};
string Trim(string s)
{
    s.erase(0, s.find_first_not_of(" \t\n\r"));
    s.erase(s.find_last_not_of(" \t\n\r") + 1);
    return s;
}
void prohod(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
Student parsujRadek(const string &radek)
{
    Student stud;
    string idString; // buffer pro ukladani id
    string jmenoString;
    string prumerString;
    stringstream ss(radek);
    getline(ss, idString, ',');
    getline(ss, jmenoString, ',');
    getline(ss, prumerString);
    idString = Trim(idString);
    jmenoString = Trim(jmenoString);
    prumerString = Trim(prumerString);

    int idPrevedeny = stoi(idString);
    double prumerPrevedeny = stod(prumerString);

    stud.id = idPrevedeny;
    stud.jmeno = jmenoString;
    stud.prumer = prumerPrevedeny;

    return stud;
}
void pridejStudentaNaKonec(Node **pHead, Student data)
{
    Node *novy = new Node;
    novy->data = data;
    novy->dalsi = nullptr;
    if (*pHead == nullptr)
    {
        *pHead = novy;
        return;
    }

    Node *aktualni = *pHead;
    while (aktualni->dalsi != nullptr)
    {
        aktualni = aktualni->dalsi;
    }
    aktualni->dalsi = novy;
}
void nactiStudentyZeSouboru(const std::string &nazevSouboru, Node **pHead)
{
    string radek;
    ifstream vstSoubor(nazevSouboru);
    while (getline(vstSoubor, radek))
    {
        cout << radek << endl;
        if (radek[0] == '#')
        {
            continue;
        }

        Student s = parsujRadek(radek);
        pridejStudentaNaKonec(pHead, s);
        // cout << s.id << " Test " << s.jmeno << " Test " << s.prumer << endl;
    }
}
void vypisSeznam(Node *head)
{
    Node *aktualni = head;
    if (head == nullptr)
    {
        cerr << "Seznam je prazdny" << endl;
    }
    else
    {
        while (aktualni != nullptr)
        {
            cout << "\e[1mID: \e[0m" << aktualni->data.id << " | " << "\e[1mJméno a Přijmení: \e[0m" << aktualni->data.jmeno << " | " << "\e[1mPrůměr: \e[0m" << aktualni->data.prumer << endl;
            aktualni = aktualni->dalsi;
        }
    }
}
void setridSeznamPodlePrumeru(Node *head)
{
    Node *vnejsi = head;
    while (vnejsi != nullptr)
    {
        Node *min = vnejsi;
        Node *vnitrni = vnejsi->dalsi;

        while (vnitrni != nullptr)
        {
            if (vnitrni->data.prumer < min->data.prumer)
            {
                min = vnitrni;
            }

            vnitrni = vnitrni->dalsi;
        }
        if (min != vnejsi)
        {
            prohod(&vnejsi->data.prumer, &min->data.prumer);
        }
        vnejsi = vnejsi->dalsi;
    }
}
void ulozStudentyDoSouboru(const std::string &nazevSouboru, Node **head)
{
    Student s;
    Node *aktualni = *head;

    string radek;
    ofstream vystSoubor(nazevSouboru);
    if (!vystSoubor.is_open())
    {
        cerr << "Soubor se nepodařilo otevřít" << endl;
        return;
    }
    while (aktualni != nullptr)
    {
        vystSoubor << aktualni->data.id << "," << aktualni->data.jmeno << "," << aktualni->data.prumer << endl;
        aktualni = aktualni->dalsi;
    }
}
void zrusSeznam(Node **pHead)
{
    Node *aktualni = *pHead;
    while (aktualni != nullptr)
    {
        delete aktualni;
        aktualni = aktualni->dalsi;
    }
    *pHead = nullptr;
}
int main()
{
    Node *head = nullptr;
    string vstupniSoubor = "studenti.txt";
    string vystSoubor = "stud_vystup.csv";
    string radek;

    nactiStudentyZeSouboru(vstupniSoubor, &head);
    setridSeznamPodlePrumeru(head);
    vypisSeznam(head);
    ulozStudentyDoSouboru(vystSoubor, &head);
    zrusSeznam(&head);
    if (head == nullptr)
        std::cout << "Pamet byla uvolnena, seznam je prazdny.\n";
    /*
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data.id << " test " << tmp->data.jmeno << " test " << tmp->data.prumer << endl;
        tmp = tmp->dalsi;
    }
    */

    return 0;
}