#include"RenderCamera.h"
#include<cmath>

FMat4 FRenderCamera::GetViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

FMat4 FRenderCamera::GetProjectionMatrix()
{
	return glm::perspective(glm::radians(zoom), (float)renderWidth / (float)renderHeight, 0.1f, 100.0f);
}

void FRenderCamera::ProcessCameraRotate(float32 xOffset, float32 yOffset, bool constrainPitch)
{
    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCameraVector();
}

void FRenderCamera::ProcessCameraRotate(FVector2 offset, bool constrainPitch)
{
    float32 xOffset, yOffset;
    xOffset = offset.x * mouseSensitivity;
    yOffset = offset.y * mouseSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    UpdateCameraVector();
}


void FRenderCamera::UpdateCameraVector()
{
	FVector3f Front;
	Front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	Front.y = sin(glm::radians(pitch));
	Front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	front = glm::normalize(Front);
	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));

}

void FRenderCamera::MoveCamera(FVector3 direction,float dt)
{
    auto dir = glm::normalize(direction);
    position += (dir.x * right + dir.y * up + dir.z * front) * moveSpeed*dt;
    //UpdateCameraVector();
}