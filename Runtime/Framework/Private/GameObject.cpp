#include"GameObject.h"


#include"Scene.h" 


FGameObject::FGameObject()
{
	GenEntityBody();
}

FGameObject::FGameObject(FScene* iScene)
{
	scene = iScene;
	GenEntityBody();
}


FTransform FGameObject::GetTransform()
{
	auto& registry = GetSceneRegistry();

	auto& tc = registry.get<FTransformComponent>(ettId);
	return tc.transform;
}

void FGameObject::GenEntityBody()
{
	ettId = scene->registry.create();
	scene->registry.emplace<FTransformComponent>(ettId);
	scene->registry.emplace<FNameComponent>(ettId,"GameObject");

	scene->registry.emplace<FChildrenComponent>(ettId);
	scene->registry.emplace<FParentComponent>(ettId);
	//scene->registry.emplace<FIDComponent>();
}

ECSRegistry& FGameObject::GetSceneRegistry()
{
	if (scene)
		return scene->registry;
	assert("Gameobject's scene is null!", false);
}