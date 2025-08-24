#pragma once

#ifndef MEMORY_H

#define MEMORY_H


template<typename T>
static void DeleteVoidPtr(void* ptr)
{
	if (ptr)
	{
		T* temp = static_cast<T*>(ptr);
		delete temp;
		temp = nullptr;
		ptr = nullptr;
	}
}
template<typename T>
static void DeleteVoidPtrArray(void* ptr)
{
	if (ptr)
	{
		T* temp = static_cast<T*>(ptr);
		delete[] temp;
		temp = nullptr;
		ptr = nullptr;
	}
}

#endif // 
