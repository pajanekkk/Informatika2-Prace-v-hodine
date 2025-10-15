#include <iostream>
#include <string>

void vypocetBMI(double vah, double vys);
void vypocetBMR(double vah, double vys, std::string pohl, int vekovost);

int main()
{
    double vyska;
    double vaha;
    std::string pohlavi;
    int vek;

    int volba;

    do
    {
        std::cout << "Zvol operaci(1 - BMI, 2 - BMR, 3 - Vypnuti): ";
        std::cin >> volba;

        switch (volba)
        {
        case 1:
            std::cout << "Zadejte výšku v metrech: ";
            std::cin >> vyska;

            std::cout << "Zadej váhu: ";
            std::cin >> vaha;

            vypocetBMI(vaha, vyska);

            break;

        case 2:
            std::cout << "Zadejte výšku v centimetrech: ";
            std::cin >> vyska;

            std::cout << "Zadej váhu: ";
            std::cin >> vaha;

            std::cout << "Zadej pohlaví(M/F): ";
            std::cin >> pohlavi;
            if (pohlavi != "M" && pohlavi != "F")
            {
                std::cout << "Špatně zadané pohlaví" << std::endl;
                break;
            }
            std::cout << "Zadej věk: ";
            std::cin >> vek;

            vypocetBMR(vyska, vaha, pohlavi, vek);
            break;

        case 3:
            std::cout << "Sbohem";
            break;

        default:
            std::cout << "Neplatna volba";
            break;
        }
    } while (volba != 3);
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
    if (pohl == "F")
    {

        bmr = 655.0955 + (9.5634 * vah) + (1.8496 * vys) - (4.6756 * vekovost);
    }
    else if (pohl == "M")
    {
        bmr = 66.473 + (13.7516 * vah) + (5.0033 * vys) - (6.755 * vekovost);
    }
    std::cout << "Tvoje BMR je: " << bmr << +" kcal/den" << std::endl;
}