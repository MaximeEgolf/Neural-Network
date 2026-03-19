#include <iostream>
#include <array>

#include "Network/Layer.h"
#include "Utils/Utils.h"

int main()
{
    // Random Seed
    srand(time(NULL));

    // Input
    //std::array inputs = { 0.12, -0.51, 0.37, -0.20 };

    float* inputs = new float[4];
    inputs[0] = 0.12f;
    inputs[1] = -0.51f;
    inputs[2] = 0.37f;
    inputs[3] = -0.20f;

    Utils::Print1D(inputs, 4, "Inputs");

    //Layer layer1 = Layer(4, 2);
    //layer1.PrintWeights();
    //layer1.PrintBias();
    //float* outputs = layer1.CalculateOutputs(inputs);

    //Utils::Print1D(outputs, 2, "Outputs");
}