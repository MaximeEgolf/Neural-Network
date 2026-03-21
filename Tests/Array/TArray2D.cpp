#include "CppUnitTest.h"

#include "Utils/TLogger.h"
#include "Array/Array2D.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TArray
{
	TEST_CLASS(TArray2D)
	{
	public:
		typedef int Type;
		TEST_METHOD(DefaultConstructorSquareMatrix)
		{
			Array2D array = Array2D<Type, 3, 3>();

			Assert::AreEqual(0, array.GetAtIndex(0, 0));
			Assert::AreEqual(0, array.GetAtIndex(1, 1));
			Assert::AreEqual(0, array.GetAtIndex(2, 2));

			TLogger<Array2D<Type, 3, 3>>::Print(array);
		}

		TEST_METHOD(InitializerListConstructorSquareMatrix)
		{
			Array2D array = Array2D<Type, 3, 3>({{0,1,2},
												 {3,4,5}, 
												 {6,7,8}});

			Assert::AreEqual(0, array.GetAtIndex(0, 0));
			Assert::AreEqual(1, array.GetAtIndex(0, 1));
			Assert::AreEqual(2, array.GetAtIndex(0, 2));
			Assert::AreEqual(3, array.GetAtIndex(1, 0));
			Assert::AreEqual(4, array.GetAtIndex(1, 1));
			Assert::AreEqual(5, array.GetAtIndex(1, 2));
			Assert::AreEqual(6, array.GetAtIndex(2, 0));
			Assert::AreEqual(7, array.GetAtIndex(2, 1));
			Assert::AreEqual(8, array.GetAtIndex(2, 2));

			TLogger<Array2D<Type, 3, 3>>::Print(array);
		}

		TEST_METHOD(SetAtIndexSquareMatrix)
		{
			Array2D array = Array2D<Type, 3, 3>({{0,1,2},
												 {3,4,5},
												 {6,7,8}});

			array.SetAtIndex(0, 0, 8);
			array.SetAtIndex(0, 1, 7);
			array.SetAtIndex(0, 2, 6);
			array.SetAtIndex(1, 0, 5);
			array.SetAtIndex(1, 1, 4);
			array.SetAtIndex(1, 2, 3);
			array.SetAtIndex(2, 0, 2);
			array.SetAtIndex(2, 1, 1);
			array.SetAtIndex(2, 2, 0);

			Assert::AreEqual(8, array.GetAtIndex(0, 0));
			Assert::AreEqual(7, array.GetAtIndex(0, 1));
			Assert::AreEqual(6, array.GetAtIndex(0, 2));
			Assert::AreEqual(5, array.GetAtIndex(1, 0));
			Assert::AreEqual(4, array.GetAtIndex(1, 1));
			Assert::AreEqual(3, array.GetAtIndex(1, 2));
			Assert::AreEqual(2, array.GetAtIndex(2, 0));
			Assert::AreEqual(1, array.GetAtIndex(2, 1));
			Assert::AreEqual(0, array.GetAtIndex(2, 2));

			TLogger<Array2D<Type, 3, 3>>::Print(array);
		}

		TEST_METHOD(DefaultConstructorMatrix)
		{
			Array2D array = Array2D<Type, 2, 3>();

			Assert::AreEqual(0, array.GetAtIndex(0, 0));
			Assert::AreEqual(0, array.GetAtIndex(0, 1));
			Assert::AreEqual(0, array.GetAtIndex(1, 0));
			Assert::AreEqual(0, array.GetAtIndex(1, 1));
			Assert::AreEqual(0, array.GetAtIndex(2, 0));
			Assert::AreEqual(0, array.GetAtIndex(2, 1));

			TLogger<Array2D<Type, 2, 3>>::Print(array);
		}

		TEST_METHOD(InitializerListConstructorMatrix)
		{
			Array2D array = Array2D<Type, 2, 3>({{0,1},
												 {2,3},
												 {4,5}});

			Assert::AreEqual(0, array.GetAtIndex(0, 0));
			Assert::AreEqual(1, array.GetAtIndex(0, 1));
			Assert::AreEqual(2, array.GetAtIndex(1, 0));
			Assert::AreEqual(3, array.GetAtIndex(1, 1));
			Assert::AreEqual(4, array.GetAtIndex(2, 0));
			Assert::AreEqual(5, array.GetAtIndex(2, 1));


			TLogger<Array2D<Type, 2, 3>>::Print(array);
		}

		TEST_METHOD(SetAtIndexMatrix)
		{
			Array2D array = Array2D<Type, 2, 3>({{0,1},
												 {2,3},
												 {4,5} });

			array.SetAtIndex(0, 0, 5);
			array.SetAtIndex(0, 1, 4);
			array.SetAtIndex(1, 0, 3);
			array.SetAtIndex(1, 1, 2);
			array.SetAtIndex(2, 0, 1);
			array.SetAtIndex(2, 1, 0);

			Assert::AreEqual(5, array.GetAtIndex(0, 0));
			Assert::AreEqual(4, array.GetAtIndex(0, 1));
			Assert::AreEqual(3, array.GetAtIndex(1, 0));
			Assert::AreEqual(2, array.GetAtIndex(1, 1));
			Assert::AreEqual(1, array.GetAtIndex(2, 0));
			Assert::AreEqual(0, array.GetAtIndex(2, 1));

			TLogger<Array2D<Type, 2, 3>>::Print(array);
		}
	};
}