#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
void prohod(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tridiciFunkce(int *pole, int velikost, std::string algoritmus)
{
    if (algoritmus == "selection")
    {
        for (int i = 0; i < velikost - 1; i++)
        {
            int min_idx = i; // najdem index nejmensiho prvku ve zbyvajici casti;
            for (int j = i + 1; j < velikost; j++)
            {
                if (pole[j] < pole[min_idx])
                {
                    min_idx = j;
                }
            }
            if (min_idx != i)
            {
                prohod(&pole[min_idx], &pole[i]);
            }
        }
    }
}

void vypisPole(int *pole, int velikost)
{
    int n = 10;
    cout << "[";
    for (int i = 0; i < velikost && i < n; i++)
        cout << pole[i] << (i == velikost - 1 || i == n - 1 ? "" : ", ");
    if (velikost > n)
    {
        cout << "...";
    }
    cout << "]" << endl;
}

int main()
{
    int vel = 0;

    cout << "Zadej vel pole: ";
    cin >> vel;

    int *pole = new int[vel];

    srand(std::time(0));

    for (int i = 0; i <= vel; i++)
    {
        pole[i] = std::rand() % 1000;
    }

    vypisPole(pole, vel);
    auto start = std::chrono::high_resolution_clock::now();
    tridiciFunkce(pole, vel, "selection");
    vypisPole(pole, vel);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::cout << "Algoritmus trval: " << duration.count() << " ms" << std::endl;
}