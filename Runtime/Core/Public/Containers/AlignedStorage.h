#pragma once

#ifndef CONTAINERS_ALIGNED_STORAGE_H
#define CONTAINERS_ALIGNED_STORAGE_H

#ifdef _WIN64
using _max_aligned_t = double; // 4 bytes
#else
using _max_aligned_t = int;
#endif // WIN32


template<size_t len>
struct TAligned
{
	alignas(4) char val[len];
};

template<size_t len>
struct TAlignedType
{
	using type = TAligned<len>;
};


#endif // !CONTAINERS_ALIGNED_STORAGE_H
