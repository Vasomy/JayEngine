#pragma once

#include"Serialization.h"

#ifndef GAMEOBJECT_H

#define GAMEOBJECT_H

#include"ECS.h"

#include"Numeric\JNumeric.h"
#include"Component.h"

template<typename T,typename = std::enable_if<std::is_integral_v<T>>>
class FUIDAllocator
	///
	/// 从1开始分配
	///
{
public:
	static T Get()
	{
		T id = ++curId;
		return id;
	}
private:
	inline static T curId = 0;
};

using GameObjectID = uint32;
constexpr const static GameObjectID g_null_gameobject_id = 0xffffffff;


class FScene;

SerializeField(WhiteList)
class FGameObject
{

private:
	friend class FScene;
public:
	FGameObject();

	FGameObject(FScene* scene);

	FGameObject(EntityID id, FScene* iscene)
	{
		ettId = id;
		scene = iscene;
	}


	EntityID GetEntityId()const { return ettId; }

	//TRenderComponent renderComponent;

	FTransform GetTransform();

	template<typename T>
	bool HasComponent() 
	{
		auto& registry = GetSceneRegistry();
		return registry.all_of<T>(ettId);
	}

	template<typename T>
	T& GetComponent() 
	{
		auto& registry = GetSceneRegistry();
		assert("GameObject dosent have specified component!", HasComponent <T>());

		return registry.get<T>(ettId);
	}
	
	template<typename T,typename... Args>
	void AddComponent(Args &&... args) 
	{
		auto& registry = GetSceneRegistry();
		
		registry.emplace<T>(ettId,std::forward<Args>(args)...);
	}

	template<typename T>
	bool TryGetComponent(T&& out)
	{
		if (HasComponent<T>())
		{
			out = GetComponent<T>();
			return true;
		}
		return false;
	}

	FGameObject Parent()
	{
		return { GetComponent<FParentComponent>().parent ,scene};
	}

private:


	ECSRegistry& GetSceneRegistry();

	void GenEntityBody();

public:
	//readonly
	EntityID ettId;
	FScene* scene;

	bool operator==(const FGameObject& object)
	{
		return ettId == object.ettId && scene == object.scene;
	}
	bool IsNullObject()const { return ettId == g_null_entity_id; }
};

const FGameObject g_null_gameobject{g_null_entity_id,nullptr};

#endif