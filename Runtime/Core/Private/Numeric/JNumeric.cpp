#include"Numeric\JNumeric.h"
#include"Containers\JArray\JArray.h"

#include<iostream>
struct FNumericHelper
{
	FNumericHelper();
};

struct FTypeInfo
{
	size_t size;
	bool isSigned;
};
TArray<FTypeInfo> gTypeInfos;

FNumericHelper gNumericHelper = FNumericHelper();

void AddTypeInfo(EBaseType type, size_t size, bool isSigned)
{
	gTypeInfos[static_cast<int>(type)] = { size,isSigned };
}



size_t GetBaseTypeSize(EBaseType type)
{
	return gTypeInfos[(int)type].size;
}

bool IsSigned(EBaseType type)
{
	return gTypeInfos[(int)type].isSigned;
}

FNumericHelper::FNumericHelper()
{
	gTypeInfos.resize(EBaseType::eCount);


	AddTypeInfo(eChar, sizeof(char8), true);
	AddTypeInfo(eWChar, sizeof(char16), true);
	AddTypeInfo(eUChar, sizeof(uchar8), false);
	AddTypeInfo(eShort, sizeof(int16), true);
	AddTypeInfo(eInt, sizeof(int32), true);
	AddTypeInfo(eLong, sizeof(int64), true);
	AddTypeInfo(eUShort, sizeof(uint16), false);
	AddTypeInfo(eUInt, sizeof(uint32), false);
	AddTypeInfo(eULong, sizeof(uint64), false);

	AddTypeInfo(eFloat, sizeof(float32), true);
	AddTypeInfo(eDouble, sizeof(float64), true);

	AddTypeInfo(ePointer, sizeof(pointer_t), false);

}
