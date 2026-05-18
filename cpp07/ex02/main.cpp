#include <iostream>
#include <string>
#include <sstream>
#include "Array.hpp"

int main(void)
{
	// Test default constructor (empty array)
	std::cout << "=== Test default constructor ===" << std::endl;
	Array<int> emptyArr;
	std::cout << "Empty array size: " << emptyArr.size() << std::endl;

	// Test parameterized constructor with int
	std::cout << "\n=== Test with int array ===" << std::endl;
	Array<int> intArr(5);
	std::cout << "Int array size: " << intArr.size() << std::endl;
	std::cout << "Elements: ";
	for (unsigned int i = 0; i < intArr.size(); ++i)
	{
		std::cout << intArr[i] << " ";
	}
	std::cout << std::endl;

	// Modify elements
	for (unsigned int i = 0; i < intArr.size(); ++i)
	{
		intArr[i] = i * 10;
	}
	std::cout << "After modification: ";
	for (unsigned int i = 0; i < intArr.size(); ++i)
	{
		std::cout << intArr[i] << " ";
	}
	std::cout << std::endl;

	// Test copy constructor (deep copy)
	std::cout << "\n=== Test copy constructor ===" << std::endl;
	Array<int> intArrCopy(intArr);
	std::cout << "Copy size: " << intArrCopy.size() << std::endl;
	std::cout << "Copy elements: ";
	for (unsigned int i = 0; i < intArrCopy.size(); ++i)
	{
		std::cout << intArrCopy[i] << " ";
	}
	std::cout << std::endl;

	// Modify original, check copy is independent
	std::cout << "\n=== Test independence after copy ===" << std::endl;
	intArr[0] = 999;
	std::cout << "Original[0] = " << intArr[0] << std::endl;
	std::cout << "Copy[0] = " << intArrCopy[0] << " (should be 0)" << std::endl;

	// Test assignment operator (deep copy)
	std::cout << "\n=== Test assignment operator ===" << std::endl;
	Array<int> intArrAssign;
	intArrAssign = intArr;
	std::cout << "Assigned array size: " << intArrAssign.size() << std::endl;
	std::cout << "Assigned elements: ";
	for (unsigned int i = 0; i < intArrAssign.size(); ++i)
	{
		std::cout << intArrAssign[i] << " ";
	}
	std::cout << std::endl;

	// Modify original, check assignment is independent
	intArr[1] = 888;
	std::cout << "After modifying original[1] to 888:" << std::endl;
	std::cout << "Original[1] = " << intArr[1] << std::endl;
	std::cout << "Assigned[1] = " << intArrAssign[1] << " (should be 10)" << std::endl;

	// Test operator[] out of bounds exception
	std::cout << "\n=== Test out of bounds exception ===" << std::endl;
	try
	{
		std::cout << "Attempting to access index 100 in size 5 array..." << std::endl;
		int x = intArr[100];
		(void)x;
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "SUCCESS: Exception thrown as expected" << std::endl;
	}

	// Test with float
	std::cout << "\n=== Test with float array ===" << std::endl;
	Array<float> floatArr(3);
	for (unsigned int i = 0; i < floatArr.size(); ++i)
	{
		floatArr[i] = i * 1.5f;
	}
	std::cout << "Float array: ";
	for (unsigned int i = 0; i < floatArr.size(); ++i)
	{
		std::cout << floatArr[i] << " ";
	}
	std::cout << std::endl;

	// Test with string
	std::cout << "\n=== Test with string array ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "C++";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strArr.size(); ++i)
	{
		std::cout << strArr[i] << " ";
	}
	std::cout << std::endl;

	// Test const array
	std::cout << "\n=== Test const array ===" << std::endl;
	const Array<int> constArr(intArr);
	std::cout << "Const array size: " << constArr.size() << std::endl;
	std::cout << "Const array elements: ";
	for (unsigned int i = 0; i < constArr.size(); ++i)
	{
		std::cout << constArr[i] << " ";
	}
	std::cout << std::endl;

	// Test const access out of bounds
	std::cout << "\n=== Test const out of bounds ===" << std::endl;
	try
	{
		const int y = constArr[100];
		(void)y;
		std::cout << "ERROR: Should have thrown exception!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "SUCCESS: Const exception thrown as expected" << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}