#include "CppUnitTest.h"

#include "Utils/TLogger.h"
#include "Network/Layer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TLayer
{
	TEST_CLASS(TLayer)
	{
	public:
		typedef double Type;
		TEST_METHOD(CalculateOutput)
		{
			//			 Inputs
			// Columns 2
			// -------------------------
			//   { i(0), i(1) }

			//			Weights
			// Columns: 2
			// Rows: 4
			// -------------------------
			// { { w(0,0), w(0,1) },
			//   { w(1,0), w(1,1) },
			//   { w(2,0), w(2,1) },
			//   { w(3,0), w(3,1) } }

			//			Biases
			// Columns: 4
			// -------------------------
			//   { b(0), b(1), b(2), b(3) }

			//			Outputs
			// Columns: 4
			// -------------------------
			//   { i(0)*w(0,0) + i(1)*w(0,1) + b(0)
			//   , i(0)*w(1,0) + i(1)*w(1,1) + b(1)
			//   , i(0)*w(2,0) + i(1)*w(2,1) + b(2)
			//   , i(0)*w(3,0) + i(1)*w(3,1) + b(3) }


			Array1D inputs = Array1D<Type, 2>({ 0.7, 0.3 });
			TLogger<Array1D<Type, 2>>::Print(inputs, "Inputs");

			Layer layer = Layer<Type, 2, 4>();
			Array2D<Type, 2,4> weights = layer.GetWeights();
			TLogger<Array2D<Type, 4, 2>>::Print(weights, "Weights");

			Array1D<Type, 4> biases = layer.GetBiases();
			TLogger<Array1D<Type, 4>>::Print(biases, "Biases");

			layer.CalculateOutputs(inputs);

			Array1D<Type, 4> outputs = layer.GetOutputs();
			TLogger<Array1D<Type, 4>>::Print(layer.GetOutputs(), "Outputs");

			// -----------------------------------
			Type expectedOutput;
			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(0, 0) 
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(0, 1) 
						   + biases.GetAtIndex(0);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(0), 1e-4);

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(1, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(1, 1)
					       + biases.GetAtIndex(1);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(1), 1e-4);

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(2, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(2, 1)
						   + biases.GetAtIndex(2);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(2), 1e-4);

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(3, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(3, 1)
						   + biases.GetAtIndex(3);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(3), 1e-4);
		}
	};
}
