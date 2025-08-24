#pragma once
#ifndef SCENE_H

#define SCENE_H

#include"Serialization.h"

#include"Numeric\JNumeric.h"
#include"Containers\Containers.h"
#include"SmartPtr\SmartPtr.h"

#include"GameObject.h"
#include"ECS.h"

/// <summary>
/// FScene 的渲染托管给MainCameraRenderScene类完成
/// </summary>

SerializeField(WhiteList)
class FScene
{
public:
	inline static TSmartPtr<FScene> MakeAnEmptyScene();
public:
	FScene(const FString& name)
		:sceneName(name)
	{
		InitScene();
	}
	FScene(const char* scene_name = "Sample Scene")
		:sceneName(scene_name)
	{
		InitScene();
		/*myself.reset(this);
		AddGameObject(std::make_shared<FGameObject>(myself));*/
	}
	FString sceneName;

	friend class FDefault3DRenderPipeline;
	friend class FEditorMainCameraViewport;

	/// <summary>
	/// new a gameobject
	/// </summary>
	/// <param name="gobj"></param>
	FGameObject& AddGameObject();
	
	void RemoveGameObject(EntityID id);

	FGameObject* FindGameObjectById(EntityID id);
	FGameObject* FindGameObjectByName(const FString& name);

	bool ContainGameObject(EntityID id);
	void TUpdate();

	ECSRegistry registry;


private:

	void MakeUUID();

	void InitScene();
	HashMap<UUID, EntityID> entityMap;
	TArray<FGameObject*>allGameObjects;
};



#endif // !SCENE_H
