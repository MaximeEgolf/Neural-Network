#include <iostream>
#include <cassert>
#include <array>

#include "Network/Layer.h"
#include "Utils/Array1D.h"
#include "Utils/Array2D.h"

#define INPUTS 2
#define INTER1 3
#define INTER2 3
#define OUTPUTS 2

typedef double Type;

int main()
{
	// Random Seed
	srand(time(NULL));

	// Input
	Array1D inputs = Array1D<Type, INPUTS>({0.12, -0.51});
	inputs.Print("Inputs");

	Layer layer1 = Layer<Type, INPUTS, INTER1>();
	layer1.CalculateOutputs(inputs);
	layer1.Print();
	//Layer layer2 = Layer<Type, INTER1, INTER2>();
	//Layer layer3 = Layer<Type, INTER2, OUTPUTS>();
	//layer3.CalculateOutputs(layer2.CalculateOutputs(layer1.CalculateOutputs(inputs)));
}