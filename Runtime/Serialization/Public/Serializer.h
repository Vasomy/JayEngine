#pragma once
#include"Containers\Containers.h"
namespace Serialization {
	template<typename T>
	class TSerializer
	{
	public:
		TSerializer(T* ptr = nullptr)
			:target(ptr)
		{

		}
		const T* target{};
		void SetTarget(T&& t)
		{
			target = &t;
		}
		virtual void Serialize(const FString& path)
		{

		}
		virtual void Deserialize(const FString&path){}
	};
}