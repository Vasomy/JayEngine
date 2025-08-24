#pragma once

#include<numbers>
#include<numeric>

using char8 = char;
using char16 = wchar_t;

using uchar8 = unsigned char;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;

using float32 = float_t;
using float64 = double_t;

#if _WIN64
using pointer_t = uint64;
#else
using pointer_t = uint32;
#endif

enum EBaseType
{
	eUnknow,
	eChar,
	eWChar,
	eUChar,
	eShort,
	eInt,
	eLong,
	eUShort,
	eUInt,
	eULong,
	eFloat,
	eDouble,
	ePointer,
	eCount
};

static size_t GetBaseTypeSize(EBaseType);
static bool IsSigned(EBaseType);

template<EBaseType bType>
struct TBaseTypeTraits;

template<>
struct TBaseTypeTraits<eChar>
{
	using type = char8;
};

template<>
struct TBaseTypeTraits<eWChar>
{
	using type = char16;
};

template<>
struct TBaseTypeTraits<eUChar>
{
	using type = uchar8;
};

template<>
struct TBaseTypeTraits<eShort>
{
	using type = uchar8;
};