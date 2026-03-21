#pragma once
#include "Precompile/pch.h"

#include "Concept/Numeric.h"
#include "Interface/IPrint.h"

template <Numeric Type, uint8_t NumColumns>
class Array1D: public IPrint
{
public:
    Array1D();
	Array1D(std::initializer_list<Type> someArgs);

    void SetAtIndex(uint8_t aColumnIndex, const Type& aType);
    const Type& GetAtIndex(uint8_t aColumnIndex) const;

    void Random();
	void Print(const char* aName = "") const override;
private:
	std::array<Type, NumColumns> m_Array;
};

template<Numeric Type, uint8_t NumColumns>
Array1D<Type, NumColumns>::Array1D()
{
    for (uint8_t col = 0; col < NumColumns; col++)
    {
        SetAtIndex(col, static_cast<Type>(0));
    }
}

template<Numeric Type, uint8_t NumColumns>
Array1D<Type, NumColumns>::Array1D(std::initializer_list<Type> someArgs)
{
    uint8_t col = 0;
    for (const Type arg : someArgs)
    {
        SetAtIndex(col, arg);
        col++;
    }
}

template<Numeric Type, uint8_t NumColumns>
inline void Array1D<Type, NumColumns>::SetAtIndex(uint8_t aColumnIndex, const Type& aType)
{
    m_Array[aColumnIndex] = aType;
}

template<Numeric Type, uint8_t NumColumns>
inline const Type& Array1D<Type, NumColumns>::GetAtIndex(uint8_t aColumnIndex) const
{
    return m_Array[aColumnIndex];
}

template<Numeric Type, uint8_t NumColumns>
void Array1D<Type, NumColumns>::Random()
{
    for (uint8_t col = 0; col < NumColumns; col++)
    {
        Type random = (Type)(rand()) / (Type)(RAND_MAX);
        SetAtIndex(col, random);
    }
}

template<Numeric Type, uint8_t NumColumns>
void Array1D<Type, NumColumns>::Print(const char* aName) const
{
    std::cout << "---------------- " << aName << " ----------------" << std::endl;
    std::cout << "{\t";
    for (uint8_t col = 0; col < NumColumns; col++)
    {
        std::cout << std::format("{:.2f}", static_cast<float>(GetAtIndex(col))) << "\t";
    }
    std::cout << "}" << std::endl;
    std::cout << "---------------- " << aName << " ----------------\n" << std::endl;
}