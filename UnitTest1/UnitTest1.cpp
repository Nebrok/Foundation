#include "pch.h"
#include "CppUnitTest.h"
#include "..\Foundation\source\ownLib\Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ArrayUnitTests1)
	{
	public:


	public:
		TEST_METHOD_INITIALIZE(ArrayUnitTests1Init)
		{

		}

		TEST_METHOD_CLEANUP(ArrayUnitTests1Cleanup)
		{

		}

		TEST_METHOD(ArrayTests_IntArrayInit)
		{
			KTools::Array<int> newIntArray{ 32 };
			Assert::IsTrue(&newIntArray != nullptr);
		}
	};
}
