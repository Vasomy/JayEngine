#pragma once
#ifndef GAMEWORLD_H


#define GAMEWORLD_H

#include"Serialization.h"

#include"Scene.h"

#include"ECS.h"

/// <FGameWorld>
/// FGameWorld 管理游戏场景的加载，切换和一些Scene的全局属性
/// 
/// </FGameWorld>

SerializeField(WhiteList)
class FGameWorld
{
public:

	FGameWorld()
	{
		activeScene.reset(new FScene);
		scenes.push_back(activeScene);
	}
	~FGameWorld()
	{
		activeScene.reset();
	}

	void Update()
	{
		activeScene->TUpdate();
	}

	TSmartPtr<FScene> MakeAndSwitchAnEmptyScene(const FString&scene_name = "EmptyScene")
	{
		scenes.push_back(MakeRef<FScene>(scene_name));
		activeScene = scenes.back();
		return activeScene;
	}

	TSmartPtr<FScene> GetActiveSceneRef() { return activeScene; }

	TSmartPtr<FScene> activeScene;// active Scene
	TArray<TSmartPtr<FScene>> scenes;
};

#endif