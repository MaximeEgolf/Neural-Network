#pragma once

#include <iostream>
#include "CppUnitTestLogger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<typename T>
class TLogger
{
public:
	template <typename T>
	static void Print(T type)
	{
		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

		type.Print();

		std::cout.rdbuf(oldCout);
		Logger::WriteMessage(oss.str().c_str());
	}
};