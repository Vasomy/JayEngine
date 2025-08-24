#pragma once;
#include"CoreDevelopMarco.h"
#include<Memory>
#include<iostream>
#ifdef OWN_CONTAINERS_SMART_PTR
template<typename T>
class TSharedCount
{
public:
    using pointer = T*;
    using const_pointer =const T*;
    using reference = T&;
    using const_reference = const T&;

    TSharedCount(pointer inPtr = nullptr)
        :ptr(inPtr)
    {
        
    }

    ~TSharedCount()
    {
        delete ptr;
    }

    void IncrementRef()
    {
        count++;
    }

    void DecrementRef()
    {
        if(--count)
        {

        }
        else
        {
            delete this;
        }
    }
private:
    TSharedCount(const TSharedCount& other) = delete;
    TSharedCount(TSharedCount&&other) = delete;
    int32_t count = 0;
    pointer ptr = nullptr;
};

template<typename T>
class TSmartPtr
{
public:

    using element_type = T;
    using self_type = TSmartPtr<T>;
    using pointer = T*;
    using reference = T&;
    TSmartPtr(pointer ptr = nullptr)
    {
        count = new TSharedCount<T>(ptr);
    }

    ~TSmartPtr()
    {
        count->DecrementRef();
    }

    TSharedCount(const self_type&other)
        :count(other.count)
    {
        
    }

private:
    TSharedCount<T>* count;
};
#else
template<typename T>
using SmartPtr = std::shared_ptr<T>;
template<typename T>
using TSmartPtr = std::shared_ptr<T>;
template<typename T,typename ...Args>
TSmartPtr<T> MakeRef(Args&&... args)
{
    return std::make_shared<T>(args...);
}
#endif

#define REF_CLASS(clazz) using clazz##Ref = TSmartPtr<clazz>;
