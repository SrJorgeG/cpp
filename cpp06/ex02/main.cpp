#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    for (int i = 0; i < 5; i++)
    {
        std::cout << "--- Test " << (i + 1) << " ---" << std::endl;

        Base* ptr = generate();

        std::cout << "identify(pointer): ";
        identify(ptr);

        std::cout << "identify(reference): ";
        identify(*ptr);

        delete ptr;
        std::cout << std::endl;
    }

    return 0;
}