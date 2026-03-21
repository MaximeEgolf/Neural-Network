#pragma once
#include "Precompile/pch.h"

#include "Concept/Numeric.h"
#include "Interface/IPrint.h"

#include "Array/Array1D.h"
#include "Array/Array2D.h"

template <Floating Type, uint8_t NumIns, uint8_t NumOuts>
class Layer: public IPrint
{
public:
	Layer();
	Array1D<Type, NumOuts> CalculateOutputs(const Array1D<Type, NumIns>& inputs);

	const Array2D<Type, NumIns, NumOuts>& GetWeights() const { return m_Weights; }
	const Array1D<Type, NumOuts>& GetBiases() const { return m_Biases; }
	const Array1D<Type, NumOuts>& GetOutputs() const { return m_Outputs; }

	void Print(const char* name = "") const override;
private:
	Array2D<Type, NumIns, NumOuts> m_Weights;
	Array1D<Type, NumOuts> m_Biases;
	Array1D<Type, NumOuts> m_Outputs;
};

template <Floating Type, uint8_t NumIns, uint8_t NumOuts>
Layer<Type, NumIns, NumOuts>::Layer()
{
	m_Biases.Random();
	m_Weights.Random();
}

template <Floating Type, uint8_t NumIns, uint8_t NumOuts>
Array1D<Type, NumOuts> Layer<Type, NumIns, NumOuts>::CalculateOutputs(const Array1D<Type, NumIns>& anArrayInput)
{
	for (uint8_t out = 0; out < NumOuts; out++) {

		Type output = m_Biases.GetAtIndex(out);
		for (uint8_t in = 0; in < NumIns; in++)
		{
			output += anArrayInput.GetAtIndex(in) * m_Weights.GetAtIndex(out, in);
		}
		m_Outputs.SetAtIndex(out, output);
	}

	return m_Outputs;
}

template <Floating Type, uint8_t NumIns, uint8_t NumOuts>
inline void Layer<Type, NumIns, NumOuts>::Print(const char* name) const
{
	m_Weights.Print("Weights");
	m_Biases.Print("Biases");
	m_Outputs.Print("Outputs / Inputs");
}