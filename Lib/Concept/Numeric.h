#pragma once

#include "Precompile/pch.h"

template <typename Type>
concept Numeric = std::is_arithmetic_v<Type>;

template <typename Type>
concept Floating = std::is_floating_point_v<Type>;