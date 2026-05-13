#include "Serializer.hpp"
#include <iostream>
#include <cassert>

int main()
{
    Data original;
    original.id = 42;
    original.name = "test_data";
    original.value = 3.14;

    std::cout << "Original Data address: " << &original << std::endl;
    std::cout << "Original Data id: " << original.id << std::endl;
    std::cout << "Original Data name: " << original.name << std::endl;
    std::cout << "Original Data value: " << original.value << std::endl;
    std::cout << std::endl;

    // Serialize: pointer -> uintptr_t
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
    std::cout << std::endl;

    // Deserialize: uintptr_t -> pointer
    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered Data address: " << recovered << std::endl;
    std::cout << "Recovered Data id: " << recovered->id << std::endl;
    std::cout << "Recovered Data name: " << recovered->name << std::endl;
    std::cout << "Recovered Data value: " << recovered->value << std::endl;
    std::cout << std::endl;

    // Verify the pointer compares equal to the original
    assert(recovered == &original);
    std::cout << "✓ Pointer equality check passed: recovered == &original" << std::endl;

    return 0;
}