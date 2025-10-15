#include <iostream>
#include <string>

void vypocetBMI(double vah, double vys);
void vypocetBMR(double vah, double vys, std::string pohl, int vekovost);

int main()
{

    std::cout << "Zadejte výšku v metrech: ";
    double vyska;
    std::cin >> vyska;

    std::cout << "Zadej váhu: ";
    double vaha;
    std::cin >> vaha;

    std::cout << "Zadej pohlaví: ";
    std::string pohlavi;
    std::cin >> pohlavi;

    std::cout << "Zadej věk: ";
    int vek;
    std::cin >> vek;

    int vyber;
}

void vypocetBMI(double vah, double vys)
{
    double bmi = vah / (vys * vys);
    std::cout << "Tvoje BMI " << bmi << std::endl;
    if (bmi < 18.5)
    {
        std::cout << "Podvyzivenost" << std::endl;
    }
    else if (18.5 <= bmi <= 25)
    {
        std::cout << "Normalni vaha" << std::endl;
    }
    else if (25.1 <= bmi <= 30)
    {
        std::cout << "Nadvaha" << std::endl;
    }
    else if (30.1 <= bmi <= 40)
    {
        std::cout << "Obezita" << std::endl;
    }
    else
    {
        std::cout << "Morbidní obezita" << std::endl;
    }
}
void vypocetBMR(double vah, double vys, std::string pohl, int vekovost)
{
    double bmr;
    if (pohl == "Ž")
    {

        bmr = 655.0955 + (9.5634 * vah) + (1, 8496 * vys) - (4.6756 * vekovost);
    }
    else if (pohl == "M")
    {
        bmr = 66.473 + (13.7516 * vah) + (5.0033 * vys) - (6.755 * vekovost);
    }
    std::cout << "Tvoje BMR je: " << bmr << std::endl;
}