#include <iostream>
#include <ctime>

void tiskni_pole(int **pole, int radky, int sloupce)
{
    for (int i = 0; i < radky; i++)
    {
        for (int j = 0; j < sloupce; j++)
        {
            std::cout << pole[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int radky, sloupce;
    std::cin >> radky;
    std::cin >> sloupce;

    int **matice1 = nullptr;
    matice1 = new int *[radky];
    int **matice2 = nullptr;
    matice2 = new int *[radky];

    std::srand(std::time(0));

    for (int i = 0; i < radky; i++)
    {
        matice1[i] = new int[sloupce];
        for (int j = 0; j < sloupce; j++)
        {
            matice1[i][j] = std::rand() % 10;
        }
    }
    for (int i = 0; i < radky; i++)
    {
        matice2[i] = new int[sloupce];
        for (int j = 0; j < sloupce; j++)
        {
            matice2[i][j] = std::rand() % 10;
        }
    }
    tiskni_pole(matice1, radky, sloupce);
    std::cout << "BUBU##########" << std::endl;
    tiskni_pole(matice2, radky, sloupce);

    int **matSoucet = nullptr;
    matSoucet = new int *[radky];

    for (int i = 0; i < radky; i++)
    {
        matSoucet[i] = new int[sloupce];
        for (int j = 0; j < sloupce; j++)
        {
            matSoucet[i][j] = matice1[i][j] + matice2[i][j];
        }
    }
    std::cout << "Soucet #########" << std::endl;
    tiskni_pole(matSoucet, radky, sloupce);
}