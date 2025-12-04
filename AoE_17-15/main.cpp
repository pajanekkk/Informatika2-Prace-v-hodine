#include <iostream>
#include <cstdint>

class Generator
{
private:
    long previous; // Using long to handle large numbers
    const long factor;
    const long criteria;
    static const long DIVISOR = 2147483647; // The divisor specified in the problem

public:
    Generator(long startValue, long generatorFactor, long validCriteria)
        : previous(startValue), factor(generatorFactor), criteria(validCriteria) {}

    long next()
    {
        do
        {
            previous = (previous * factor) % DIVISOR;
            return previous;
        } while (previous % criteria != 0);
    }

    // Get only the lowest 16 bits
    uint16_t getLower16Bits()
    {
        return previous & 0xFFFF; // Mask to get lowest 16 bits
    }
};

int main()
{
    // Starting values from puzzle input (replace with your values)
    Generator genA(512, 16807, 4); // Example starting value
    Generator genB(191, 48271, 8); // Example starting value

    int matches = 0;
    const int PAIRS_TO_CHECK = 40000000; // 40 million pairs

    for (int i = 0; i < PAIRS_TO_CHECK; i++)
    {
        genA.next();
        genB.next();

        if (genA.getLower16Bits() == genB.getLower16Bits())
        {
            matches++;
        }

        // Optional: Print progress every million iterations
        if ((i + 1) % 1000000 == 0)
        {
            std::cout << "Processed " << (i + 1) / 1000000 << " million pairs\n";
        }
    }

    std::cout << "Found " << matches << " matching pairs\n";
    return 0;
}