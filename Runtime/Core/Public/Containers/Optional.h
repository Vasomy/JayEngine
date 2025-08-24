#pragma once

#include"AlignedStorage.h"
#ifndef CONTAINERS_OPTIONAL_H
#define CONTAINERS_OPTIONAL_H

template<typename T>
class TOptional
{
	// 数据类型，为对应大小的char[]
	using data_t = typename TAlignedType<sizeof(T)>::type;
	// 模板类型
	using t_type = TOptional;
	// 元素类型
	using element_t = T;
	// 模板含参类型
	using t_t_type = TOptional<T>;
public:

	~TOptional()
	{

	}

	TOptional()
		:have_val(false)
	{
		memset(&data, 0, sizeof(data_t));
	}
	TOptional(const T& rhs)
		:have_val(true)
	{
		Create(rhs);
	}

	TOptional(T&& rhs)
		:have_val(true)
	{
		Create(rhs);
	}

	TOptional(const TOptional<T>& rhs)
		:have_val(true)
	{
		Create(*(T*)&rhs.data);
	}

	TOptional(TOptional<T>&& rhs)
		:have_val(true)
	{
		Swap(std::forward<data_t>(rhs.data));
	}

	TOptional<T>& operator=(const TOptional<T>& rhs)
	{
		return TOptional<T>(rhs.data);
	}

	TOptional<T>& operator=(TOptional<T>&& rhs)
	{
		return TOptional<T>(rhs.data);
	}

	const T& Get() const
	{
		if (!have_val)
		{
			std::cout << "User try to get a null value!\n";
			abort();
		}
		return *(T*)&data;
	}


	void Set(const T& inData)
	{
		Create(inData);
	}

	void Set(T&& inData)
	{
		Create(std::forward<T>(inData));
	}

	operator bool()
	{
		return have_val;
	}

	bool HaveValue()const
	{
		return have_val;
	}

#ifdef __cplusplus
#endif // __cplusplus


private:

	template<typename... Args>
	void Create(Args&&...args)
	{
		new (&data) T(std::forward<Args>(args)...);
		have_val = true;
	}

	T& GetNonValidate()
	{
		return *(T*)&data;
	}

	void Swap(data_t& rhs)
	{
		::std::swap(data, rhs);
	}

	void Swap(data_t&& rhs)
	{
		::std::swap(data, rhs);
	}

	bool have_val = false;
	data_t data;
};



#endif // !CONTAINERS_OPTIONAL_H
