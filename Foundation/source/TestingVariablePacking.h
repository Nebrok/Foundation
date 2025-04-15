#pragma once
#include <iostream>
#include "ownLib/LibraryInclude.h"

struct Inefficient
{
	uint64_t funneh;
	uint16_t foo;
	uint32_t bar;
	uint32_t kek;
	uint64_t funneh2;
	uint16_t kik;
};

struct Efficient
{
	uint64_t funneh;
	uint64_t funneh2;
	uint32_t kek;
	uint32_t bar;
	uint16_t foo;
	uint16_t kik;
};


void RunPackingTest()
{
	KTools::Timer timer;

	const long long size = 1000000;

	std::cout << "Size of Inefficient (bytes): " << sizeof(Inefficient) << "\n";
	std::cout << "Size of Efficient (bytes): " << sizeof(Efficient) << "\n";

	std::cout << "\n";
	std::cout << "Testing creation of " << size << " of each struct.\n";
	std::cout << "\n";

	
	timer.StartClock();
	Inefficient* ineffArray = new Inefficient[size];
	Inefficient* ineffArray2 = new Inefficient[size];
	for (int i = 0; i < size; i++)
	{
		ineffArray[i] = Inefficient{ 20000000000, 32, 256, 1024, 2000000000, 16 };
	}
	for (int i = 0; i < size; i++)
	{
		ineffArray2[i] = ineffArray[i];
	}
	std::cout << "Inefficient packing time: \n";
	timer.StopClock();

	delete[] ineffArray;
	delete[] ineffArray2;

	timer.StartClock();
	Efficient* effArray = new Efficient[size];
	Efficient* effArray2 = new Efficient[size];
	for (int i = 0; i < size; i++)
	{
		effArray[i] = Efficient{ 20000000000,  2000000000, 256, 1024, 32, 16 };
	}
	for (int i = 0; i < size; i++)
	{
		effArray2[i] = effArray[i];
	}
	std::cout << "Efficient packing time: \n";
	timer.StopClock();

	delete[] effArray;
	delete[] effArray2;

}