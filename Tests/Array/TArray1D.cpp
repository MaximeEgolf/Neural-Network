#include "CppUnitTest.h"

#include "Utils/TLogger.h"
#include "Array/Array1D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TArray
{
	TEST_CLASS(TArray1D)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Array1D array = Array1D<int, 5>();

			Assert::AreEqual(0, array.GetAtIndex(0));
			Assert::AreEqual(0, array.GetAtIndex(1));
			Assert::AreEqual(0, array.GetAtIndex(2));
			Assert::AreEqual(0, array.GetAtIndex(3));
			Assert::AreEqual(0, array.GetAtIndex(4));

			TLogger<Array1D<int, 5>>::Print(array);
		}

		TEST_METHOD(InitializerListConstructor)
		{
			Array1D array = Array1D<int, 5>({ 0,1,2,3,4 });

			Assert::AreEqual(0, array.GetAtIndex(0));
			Assert::AreEqual(1, array.GetAtIndex(1));
			Assert::AreEqual(2, array.GetAtIndex(2));
			Assert::AreEqual(3, array.GetAtIndex(3));
			Assert::AreEqual(4, array.GetAtIndex(4));

			TLogger<Array1D<int, 5>>::Print(array);
		}

		TEST_METHOD(SetAtIndex)
		{
			Array1D array = Array1D<int, 5>();

			array.SetAtIndex(0, 0);
			array.SetAtIndex(1, 1);
			array.SetAtIndex(2, 2);
			array.SetAtIndex(3, 3);
			array.SetAtIndex(4, 4);

			Assert::AreEqual(0, array.GetAtIndex(0));
			Assert::AreEqual(1, array.GetAtIndex(1));
			Assert::AreEqual(2, array.GetAtIndex(2));
			Assert::AreEqual(3, array.GetAtIndex(3));
			Assert::AreEqual(4, array.GetAtIndex(4));

			TLogger<Array1D<int, 5>>::Print(array);
		}
	};
}
