#pragma once

#ifndef CAMERA_COMPONENT_H
#define CAMERA_COMPONENT_H
#include"RenderCamera.h"
struct FCamera
{
	inline static FCamera* mainCamera = nullptr;
	FCamera()
	{
		mainCamera = this;
		camera.UpdateCameraVector();
	}
	FRenderCamera camera;
};

#endif // !CAMERA_COMPONENT_H
