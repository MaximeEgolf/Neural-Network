#pragma once

#include <iostream>
#include "CppUnitTestLogger.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<typename T>
concept Printable = requires(T t)
{
	t.Print();
};

template<Printable T>
class TLogger
{
public:
	template <typename T>
	static void Print(T type, const char* message = "")
	{
		std::ostringstream oss;
		std::streambuf* oldCout = std::cout.rdbuf(oss.rdbuf());

		type.Print(message);

		std::cout.rdbuf(oldCout);
		Logger::WriteMessage(oss.str().c_str());
	}
};