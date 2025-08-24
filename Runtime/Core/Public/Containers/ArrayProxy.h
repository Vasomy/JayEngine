#pragma once

#ifndef ARRAY_PROXY_H
#define ARRAY_PROXY_H
#include<assert.h>
#include"JArray\JArray.h"
/// <summary>
/// ArrayProxy��Ϊһ������Ĵ����࣬��Ӧ�ù�������ӵ�е�ָ���Ƿ�Ϸ������⣬
/// ��˲��ؿ��������������ӵ���κ�new����delete����Ϊ��ֻ�ǵ�������Ϊָ��Ĵ���
/// ����ģ���ຬ��shared����unique������ָ��
/// 
/// ע��ArrayProxy��ӵ�е�ָ����пճ�Ϊ����ָ�룬������Ҫʹ��ArrayProxy��Ϊ��ĳ�Ա������
/// ��Ӧ�����䱻�������ʱ������ֵ��������һ������Ҫ����ĵط�
/// ���´�����һ��ArrayProxy��ָ���Ϊ����ָ�������
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
///		b arr[10]; // һ����ջ�ϵ�����
///		ta.SetPtr(arr);
///
///		for (int i = 0; i < ta.count; ++i)
///		{
///			std::cout << *ta.ptr[i].a << '\n';
///		}
///		// cout info : 5 5 5 5 5 5 5 5 5 5
///		// ������ǰ������arr�����ͷţ�ptr��Ϊ����ָ��
///	}
///	for (int i = 0; i < ta.count; ++i)
///	{
///		std::cout << *ta.ptr[i].a << '\n';
///	}
///	// cout info : ...some strange number
///	return 0;
///
/// }
/// �û���Ӧ���ڳ־��Եĵ��ô����ָ�룬���Ǿ��ڵ�һ�δ���ʱ����������
/// 
/// ���鴫��ԭ�����飬vector��array�������������Կռ�������Ϊ����
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
