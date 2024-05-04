#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

        TEST_METHOD(EnqueueTest)
        {
            Elem* first = NULL;
            Elem* last = NULL;
            enqueue(first, last, 5);
            Assert::AreEqual(first->info, 5);
            Assert::AreEqual(last->info, 5);
        }

        TEST_METHOD(DequeueTest)
        {
            Elem* first = NULL;
            Elem* last = NULL;
            enqueue(first, last, 5);
            Assert::AreEqual(dequeue(first, last), 5);
        }
		};
	}

