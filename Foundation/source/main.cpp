#include <iostream>
#include "ownLib\Array.cpp"


int main(int argc, char* argv[])
{
	std::cout << "Hello World!" << "\n";

	KTools::Array<int> testArr = *new KTools::Array<int>(4);

	testArr[1] = 2;

	std::cout << "Custom Array Val at index 1: " << testArr[1] << "\n";
	std::cout << "Custom Array Val Length: " << testArr.Length << "\n";

	return 0;
}