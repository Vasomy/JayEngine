#include"Scene.h"

#include"CoreDevelopMarco.h"


inline TSmartPtr<FScene> FScene::MakeAnEmptyScene()
{
	return TSmartPtr<FScene>();
}

FGameObject& FScene::AddGameObject()
{
	TSmartPtr<FGameObject>obj;
	obj.reset(new FGameObject(this));

	return*obj;
}




void FScene::RemoveGameObject(EntityID id)
{

}
 
FGameObject* FScene::FindGameObjectById(EntityID id)
{
	return nullptr;
}

FGameObject* FScene::FindGameObjectByName(const FString& name)
{
	return nullptr;
}

bool FScene::ContainGameObject(EntityID id)
{
	return false;
}

void FScene::TUpdate()
{

}

void FScene::MakeUUID()
{
}

void FScene::InitScene()
{
	AddGameObject();

	FCamera* mc = FCamera::mainCamera;
	mc->camera.renderWidth = 1920;
	mc->camera.renderHeight = 1080;
}
