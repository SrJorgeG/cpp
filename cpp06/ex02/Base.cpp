#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {}

// --- generate: randomly instantiates A, B, or C ---

Base* generate(void)
{
    int choice = std::rand() % 3;

    switch (choice)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A;
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B;
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C;
        default:
            return new A;
    }
}

// --- identify via pointer: uses dynamic_cast ---

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// --- identify via reference: uses dynamic_cast, pointer usage is forbidden ---

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown type" << std::endl;
}