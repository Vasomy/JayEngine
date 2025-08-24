#pragma once
#include"Math\Math.h"
struct FConstantBuffer
{
	FConstantBuffer& operator=(const FConstantBuffer& rhs) = default;
	FMat4 view;
	FMat4 proj;
	FMat4 projView;
};