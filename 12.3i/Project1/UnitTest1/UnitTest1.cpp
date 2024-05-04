#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSwapElements)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			for (int i = 1; i <= 5; ++i)
				enqueue(first, last, i);

			D(first, last);

			int expected[] = { 2, 1, 4, 3, 5 };
			for (int i = 0; i < 5; ++i)
			{
				Assert::AreEqual(expected[i], dequeue(first, last));
			}
		}
	};
}
