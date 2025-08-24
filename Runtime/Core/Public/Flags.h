#pragma once
#ifndef FLAGS_H
#include<xtr1common>
#include<type_traits>
template<typename BitType>
class Flags
{
public:


	using MaskType = typename std::underlying_type<BitType>::type;
	using SelfType = Flags<BitType>;
	using ConstRef = const SelfType&;

	Flags() :mask_(0) {}
	explicit Flags(MaskType mask) : mask_(mask) {}
	Flags(BitType bittype) : mask_(static_cast<MaskType>(bittype)) {}


	constexpr bool operator==(ConstRef  rhs)const
	{
		return mask_ == rhs.mask_;
	}
	constexpr bool operator>=(ConstRef rhs)const
	{
		return mask_ >= rhs.mask_;
	}
	constexpr bool operator>(ConstRef rhs)const
	{
		return mask_ > rhs.mask_;
	}
	constexpr bool operator<=(ConstRef rhs)const
	{
		return mask_ <= rhs.mask_;
	}
	constexpr bool operator<(ConstRef rhs)const
	{
		return mask_ < rhs.mask_;
	}
	constexpr bool operator!=(ConstRef rhs)const
	{
		return mask_ != rhs.mask_;
	}

	constexpr bool operator!()const
	{
		return !mask_;
	}


	constexpr Flags<BitType> operator&(ConstRef mask)
	{
		return Flags<BitType>(mask_ & mask.mask_);
	}

	constexpr Flags<BitType> operator|(ConstRef mask)
	{
		return Flags<BitType>(mask_ | mask.mask_);
	}


	constexpr Flags<BitType> operator^(ConstRef mask)
	{
		return Flags<BitType>(mask_ ^ mask.mask_);
	}

	/*
		目前不支持取反
	*/
	constexpr Flags<BitType> operator~()
	{
		return Flags<BitType>(~mask_);
	}

	constexpr SelfType& operator=(ConstRef rhs)
	{
		mask_ = rhs.mask_;
		return *this;
	}

	constexpr SelfType& operator|=(ConstRef rhs)
	{
		mask_ |= rhs.mask_;
		return *this;
	}

	constexpr SelfType& operator&=(ConstRef rhs)
	{
		mask_ &= rhs.mask_;
		return*this;
	}

	constexpr SelfType& operator^=(ConstRef rhs)
	{
		mask_ ^= rhs.mask_;
		return*this;
	}

	explicit operator bool()const
	{
		return !!mask_;
	}

	explicit operator MaskType()const
	{
		return mask_;
	}


	//private:
	MaskType mask_ = 0;
};

template<typename BitType>
struct FlagTraits;


template<typename BitType>
struct FlagTraits
{
	constexpr static bool isBitMask = false;
};

template<typename BitType>
bool operator == (BitType bit, Flags<BitType> flag)
{
	return flag.operator==(bit);
}


template<typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitMask, bool>::type = true>
constexpr Flags<BitType> operator |(BitType bit1, BitType bit2)
{
	return Flags<BitType>(bit1) | bit2;
}

template<typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitMask, bool>::type = true>
constexpr Flags<BitType> operator &(BitType bit1, BitType bit2)
{
	return Flags<BitType>(bit1) & bit2;
}

template<typename BitType, typename std::enable_if<FlagTraits<BitType>::isBitMask, bool>::type = true>
constexpr Flags<BitType> operator ^(BitType bit1, BitType bit2)
{
	return Flags<BitType>(bit1) ^ bit2;
}

//template<typename BitType>
//constexpr Flags<BitType> operator&(BitType bit1, BitType bit2)
//{
//	return Flags<BitType>(bit1) & bit2;
//}
//
//template<typename BitType>
//constexpr Flags<BitType> operator^(BitType bit1, BitType bit2)
//{
//	return Flags<BitType>(bit1) ^ bit2;
//}

template<typename BitType>
Flags<BitType> operator |(BitType bit, Flags<BitType> const& flag)
{
	return flag.operator|(bit);
}

template<typename BitType>
Flags<BitType> operator &(BitType bit, Flags<BitType> const& flag)
{
	return flag.operator&(bit);
}

template<typename BitType>
Flags<BitType> operator ^(BitType bit, Flags<BitType> const& flag)
{
	return flag.operator^(bit);
}

//template<typename BitType>
//Flags<BitType> operator <(BitType bit, Flags<BitType> const& flag)
//{
//	return flag.operator<(bit);
//}

#define FLAG_BITS_ENUM(enum_type)  using enum_type##Flag = Flags<enum_type>;\
using enum_type##FlagBits = enum_type;\
template<>\
struct FlagTraits<enum_type>\
{\
	constexpr static bool isBitMask = true;\
	/*constexpr static F##enum_type##Flag allFlags = 0;*/ \
};\


#endif // !FLAGS_H
