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
			Array1D inputs = Array1D<Type, 2>({ 0.7, 0.3 });
			TLogger<Array1D<Type, 2>>::Print(inputs, "Inputs");

			Layer layer = Layer<Type, 2, 4>();
			Array2D<Type, 4,2> weights = layer.GetWeights();
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

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(0));

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(1, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(1, 1)
					       + biases.GetAtIndex(1);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(1));

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(2, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(2, 1)
						   + biases.GetAtIndex(2);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(2));

			// -----------------------------------

			expectedOutput = inputs.GetAtIndex(0) * weights.GetAtIndex(3, 0)
						   + inputs.GetAtIndex(1) * weights.GetAtIndex(3, 1)
						   + biases.GetAtIndex(3);

			Assert::AreEqual(expectedOutput, outputs.GetAtIndex(3));
		}
	};
}
