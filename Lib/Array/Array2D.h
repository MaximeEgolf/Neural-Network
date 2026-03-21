#pragma once
#include "Precompile/pch.h"

#include "Concept/Numeric.h"
#include "Interface/IPrint.h"

template <Numeric Type, uint8_t NumColumns, uint8_t NumRows>
class Array2D : public IPrint
{
public:
	Array2D();
	Array2D(std::initializer_list<std::initializer_list<Type>> someArgs);

	void SetAtIndex(uint8_t aColumnIndex, uint8_t aRowIndex, const Type& aType);
	const Type& GetAtIndex(uint8_t aColumnIndex, uint8_t aRowIndex) const;

	void Random();
	void Print(const char* aName = "") const override;
private:
	std::array<std::array<Type, NumRows>, NumColumns> m_Array;
};

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
Array2D<Type, NumColumns, NumRows>::Array2D()
{
	for (uint8_t row = 0; row < NumRows; row++)
	{
		for (uint8_t col = 0; col < NumColumns; col++)
		{
			SetAtIndex(row, col, static_cast<Type>(0));
		}
	}
}

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
Array2D<Type, NumColumns, NumRows>::Array2D(std::initializer_list<std::initializer_list<Type>> someArgs)
{
	uint8_t row = 0;
	for (const std::initializer_list list : someArgs)
	{
		uint8_t col = 0;
		for (const Type arg : list)
		{
			SetAtIndex(row, col, arg);
			col++;
		}
		row++;
	}
}

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
inline void Array2D<Type, NumColumns, NumRows>::SetAtIndex(uint8_t aRowIndex, uint8_t aColumnIndex, const Type& aType)
{
	m_Array[aColumnIndex][aRowIndex] = aType;
}

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
inline const Type& Array2D<Type, NumColumns, NumRows>::GetAtIndex(uint8_t aRowIndex, uint8_t aColumnIndex) const
{
	return m_Array[aColumnIndex][aRowIndex];
}

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
void Array2D<Type, NumColumns, NumRows>::Random()
{
	for (uint8_t row = 0; row < NumRows; row++)
	{
		for (uint8_t col = 0; col < NumColumns; col++)
		{
			Type random = (Type)(rand()) / (Type)(RAND_MAX);
			SetAtIndex(row, col, random);
		}
	}
}

template<Numeric Type, uint8_t NumColumns, uint8_t NumRows>
void Array2D<Type, NumColumns, NumRows>::Print(const char* aName) const
{
	std::cout << "---------------- " << aName << " ----------------" << std::endl;
	for (int row = 0; row < NumRows; row++) {
		std::cout << "{\t";
		for (int col = 0; col < NumColumns; col++) {
			std::cout << std::format("{:.2f}", static_cast<float>(GetAtIndex(row, col))) << "\t";
		}
		std::cout << "}," << std::endl;
	}
	std::cout << "---------------- " << aName << " ----------------\n" << std::endl;
}