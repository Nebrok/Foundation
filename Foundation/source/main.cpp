#include <iostream>
#include "ownLib\Array.h"
#include "ownLib\List.h"
#include "ownLib\Vector3.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello World!" << "\n";

	KTools::Vector3<int> testVector1 = *new KTools::Vector3<int>(1, 2, 3);
	KTools::Vector3<int> testVector2 = *new KTools::Vector3<int>(4, 5, 6);

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "Adding scalar to each vector...\n";

	testVector1 += 2;
	testVector2 += 4;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "Taking scalar from each vector...\n";

	testVector1 -= 2;
	testVector2 -= 4;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "Multiplying by scalar for each vector...\n";

	testVector1 *= 2;
	testVector2 *= 4;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "Dividing by scalar for each vector...\n";

	testVector1 /= 2;
	testVector2 /= 4;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "---------------------------\n";

	std::cout << "Adding first vector to second...\n";

	testVector2 += &testVector1;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";

	std::cout << "Taking first vector from second...\n";

	testVector2 -= testVector1;

	std::cout << "First testVector ToString: " << testVector1.ToString() << "\n";
	std::cout << "Second testVector ToString: " << testVector2.ToString() << "\n";




	return 0;
}