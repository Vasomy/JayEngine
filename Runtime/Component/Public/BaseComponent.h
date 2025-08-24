#pragma once

#include"Serialization.h"
#include"Containers\JString\JString.h"

#include"ECS.h"

struct FNameComponent
{
	FNameComponent(const char* in)
	{
		name = in;
	}
	FString name = "GameObject";
};


struct FChildrenComponent
{
	TArray<EntityID>children;
	bool HasChildren() { return children.size() != 0; }
};

struct FParentComponent
{
	EntityID parent = g_null_entity_id;
};

using UUID = int64;

struct FIDComponent
{
	UUID uuid;
};


