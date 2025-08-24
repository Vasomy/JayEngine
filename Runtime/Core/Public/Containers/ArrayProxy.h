#pragma once

#ifndef ARRAY_PROXY_H
#define ARRAY_PROXY_H
#include<assert.h>
#include"JArray\JArray.h"
/// <summary>
/// ArrayProxy作为一个数组的代理类，不应该关心其所拥有的指针是否合法的问题，
/// 因此不必考虑深拷贝，即不会拥有任何new或者delete的行为，只是单纯的作为指针的代理
/// 允许模板类含有shared（非unique）智能指针
/// 
/// 注意ArrayProxy所拥有的指针很有空成为悬空指针，如若想要使用ArrayProxy作为类的成员变量，
/// 你应该在其被传入进来时，将其值拷贝到另一个你想要储存的地方
/// 以下代码是一个ArrayProxy的指针变为悬空指针的例子
///struct b
///{
///	int* a;
///	b()
///	{
///		a = new int(5);
///	}
///	~b()
///	{
///		delete a;
///	}
///};
///
///struct a
///{
///	b* ptr;
///	int count = 0;
///	void SetPtr(const ArrayProxy<b>& arr)
///	{
///		ptr = arr.Data();
///		count = arr.Count();
///	}
///};
///
///int main()
///{
///	a ta;
///	{
///		b arr[10]; // 一个在栈上的数组
///		ta.SetPtr(arr);
///
///		for (int i = 0; i < ta.count; ++i)
///		{
///			std::cout << *ta.ptr[i].a << '\n';
///		}
///		// cout info : 5 5 5 5 5 5 5 5 5 5
///		// 结束当前作用域，arr被是释放，ptr成为悬空指针
///	}
///	for (int i = 0; i < ta.count; ++i)
///	{
///		std::cout << *ta.ptr[i].a << '\n';
///	}
///	// cout info : ...some strange number
///	return 0;
///
/// }
/// 用户不应该在持久性的调用传入的指针，而是尽在第一次传入时保存其数据
/// 
/// 建议传入原生数组，vector，array，或者任意线性空间容器作为参数
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class TArrayProxy
{
public:

	TArrayProxy()
		:data(nullptr), count(0)
	{

	}

	TArrayProxy(const TArrayProxy<T>& rhs)
	{
		this->operator=(rhs);
	}
	TArrayProxy(TArrayProxy<T>&& rhs) = delete;

	TArrayProxy<T>& operator=(const TArrayProxy<T>& rhs)
	{
		this->data = rhs.data;
		this->count = rhs.count;
		return*this;
	}

	TArrayProxy(T* ptr, size_t count)
		:data(ptr), count(count)
	{

	}

	// deep copy
	TArrayProxy(const std::vector<T>& vec)
		:data(const_cast<T*>(vec.data())), count(vec.size())
	{

	}
	template<size_t size>
	TArrayProxy(const std::array<T, size>array)
		: data(const_cast<T*>(array.data())), count(size)
	{

	}

	template<size_t size>
	TArrayProxy(T(&array)[size])
		: count(size), data(array)
	{

	}
	// copy as array
	TArray<T> AsArray() const
	{
		TArray<T> ret;
		ret.resize(count);
		for (int i = 0; i < count; ++i)
		{
			// copy
			ret[i] = (T)(data[i]);
		}
		return ret;
	}

	// get function and operation override
	T& At(size_t index) const
	{
		assert(index < count);
		return data[index];
	}

	T* Data() const
	{
		return data;
	}

	// get pointer length
	size_t Count() const
	{
		return count;
	}

	// get pointer size
	size_t Size()const
	{
		return count * sizeof(T);
	}

	T& operator[](size_t index) const
	{
		return At(index);
	}

	T* begin() const
	{
		return data;
	}

	T* end() const
	{
		return data + count;
	}

private:
	T* data;
	size_t count;
};

#endif // !ARRAR_PROXY_H
