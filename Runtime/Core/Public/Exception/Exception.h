#pragma once
#include"Containers\Containers.h"
class Exception
{
public:
	Exception(FString contents)
		:contents_(contents)
	{

	}

	const FString& What() { return contents_; }

private:
	FString contents_;
};