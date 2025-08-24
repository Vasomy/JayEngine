#pragma once

#ifndef RENDER_CAMERA_H

#define RENDER_CAMERA_H

#include"Math\Math.h"
#include"Numeric/JNumeric.h"
class FRenderCamera
{
public:

	int32 renderWidth, renderHeight;

	FVector3f position = { 3,3,3 };
	FVector3f front;
	FVector3f up;
	FVector3f right;
	FVector3f worldUp = { 0,1,0 };

	float32 yaw = -135;
	float32 pitch = -45;

	float32 moveSpeed = 25.0f;
	float32 mouseSensitivity = 0.1f;
	float32 zoom = 45.0f;

	FMat4 GetViewMatrix();
	FMat4 GetProjectionMatrix();

	void ProcessCameraRotate(float32 xOffset, float32 yOffset,bool constrainPitch = true);
	void ProcessCameraRotate(FVector2 offset, bool constrainPitch = true);

	// direction 是以摄像机自身为坐标系
	void MoveCamera(FVector3 direction, float dt);

	void UpdateCameraVector();

	float32 GetAspect()
	{
		return (float32)renderWidth / (float32)renderHeight;
	}
private:
};


#endif // !RENDER_CAMERA_H
