#include <iostream>
#include <string>
#include "iter.hpp"

// Function to print int (non-const reference)
void printInt(int& x)
{
	std::cout << x << " ";
}

// Function to print const int
void printConstInt(const int& x)
{
	std::cout << x << " ";
}

// Function to increment int
void incrementInt(int& x)
{
	++x;
}

// Function to increment float
void incrementFloat(float& x)
{
	++x;
}

// Function template for printing any type
template <typename T>
void printElement(T& x)
{
	std::cout << x << " ";
}

int main(void)
{
	std::cout << "=== Test with int array ===" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	unsigned int intLen = 5;

	std::cout << "Original array: ";
	iter(intArray, intLen, printInt);
	std::cout << std::endl;

	std::cout << "After increment: ";
	iter(intArray, intLen, incrementInt);
	iter(intArray, intLen, printInt);
	std::cout << std::endl;

	std::cout << "\n=== Test with string array ===" << std::endl;
	std::string strArray[] = {"apple", "banana", "cherry"};
	unsigned int strLen = 3;

	std::cout << "String array: ";
	iter(strArray, strLen, printElement<std::string>);
	std::cout << std::endl;

	std::cout << "\n=== Test with const int array ===" << std::endl;
	const int constIntArray[] = {10, 20, 30, 40, 50};
	std::cout << "Const int array: ";
	iter(constIntArray, intLen, printConstInt);
	std::cout << std::endl;

	// Test with empty array
	std::cout << "\n=== Test with empty array ===" << std::endl;
	int emptyArray[] = {};
	iter(emptyArray, 0, printInt);
	std::cout << "(no output - empty array)" << std::endl;

	// Test with float array using function template
	std::cout << "\n=== Test with float array ===" << std::endl;
	float floatArray[] = {1.1f, 2.2f, 3.3f};
	std::cout << "Float array: ";
	iter(floatArray, 3, printElement<float>);
	std::cout << std::endl;

	// Test modifying float elements
	std::cout << "\n=== Test modifying float elements ===" << std::endl;
	float fArray[] = {1.5f, 2.5f, 3.5f};
	std::cout << "Before: ";
	iter(fArray, 3, printElement<float>);
	std::cout << std::endl;

	iter(fArray, 3, incrementFloat);
	std::cout << "After increment: ";
	iter(fArray, 3, printElement<float>);
	std::cout << std::endl;

	return 0;
}