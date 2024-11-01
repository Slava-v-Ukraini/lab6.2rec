#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyUnitTests
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreate)
        {
            const int size = 10;
            int a[size];
            Create(a, size, 1, 10);

            // Check if all elements are within the specified range
            for (int i = 0; i < size; i++) {
                Assert::IsTrue(a[i] >= 1 && a[i] <= 10);
            }
        }

        TEST_METHOD(TestSum)
        {
            const int size = 5;
            int a[size] = { 1, 2, 3, 4, 5 };
            int result = Sum(a, size);

			//  сума 1 + 2 + 3 + 4 + 5 , повинно бути 15
            Assert::AreEqual(15, result);
        }

        TEST_METHOD(TestAverageOdd)
        {
            const int size = 5;
            int a[size] = { 1, 2, 3, 4, 5 };
            double result = AverageOdd(a, size);

            // сер арифм знач (1 + 3 + 5) / 3 = 3.0
            Assert::AreEqual(3.0, result, 0.001);

            // тестування з непарними значеннями
            int b[size] = { 2, 4, 6, 8, 10 };
            result = AverageOdd(b, size);
            Assert::AreEqual(0.0, result, 0.001);
        }
    };
}
