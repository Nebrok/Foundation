#include <iostream>
#include "ownLib\Array.h"
#include "ownLib\List.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello World!" << "\n";

	KTools::List<int> testArr = *new KTools::List<int>();

	for (int i = 0; i < 31; i++)
	{
		testArr.Add(i);
	}

	std::cout << "Custom List Val Length: " << testArr.Count() << "\n";
	std::cout << "Custom List Val Length: " << testArr.Capacity() << "\n";
	std::cout << "Custom List ToString: " << testArr.ToString() << "\n";

	for (int i = 0; i < 10; i++)
	{
		testArr.Add(i + 100);
	}

	std::cout << "Custom List Val Length: " << testArr.Count() << "\n";
	std::cout << "Custom List Val Length: " << testArr.Capacity() << "\n";
	std::cout << "Custom List ToString: " << testArr.ToString() << "\n";

	for (int i = 0; i < 15; i++)
	{
		testArr.RemoveAt(0);
	}

	std::cout << "Custom List Val Length: " << testArr.Count() << "\n";
	std::cout << "Custom List Val Length: " << testArr.Capacity() << "\n";
	std::cout << "Custom List ToString: " << testArr.ToString() << "\n";
	
	return 0;
}