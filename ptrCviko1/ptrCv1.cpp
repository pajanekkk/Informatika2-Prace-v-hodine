#include <iostream>

using namespace std;

/*
void prehod(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a;
}

int main()
{
    int a = 5;
    int b = 3;

    prehod(&a, &b);

    printf("%d", a);
    printf("%d", b);

    return 0;
}
*/

int pole[10] = {9, 8, 3, 5, 22, 6, 1, 10, 4, 2};
void najdi_nejmensi_nejvetsi(int *pole, int velikost_pole, int *nejvetsi, int *nejmensi)
{
    while (true)
    {

        cout << "adresa: " << pole << ", hodnota: " << *pole << endl;
        pole++;
    }
}

int main()
{
    int nejmensi, nejvetsi;
    najdi_nejmensi_nejvetsi(pole, 10, &nejvetsi, &nejmensi);
    return 0;
}
