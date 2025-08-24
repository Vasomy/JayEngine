#include"Input.h"
#include"RHIDynamic.h"
void FInputSystem::Init(
)
{
	auto& rhi = GetRHI();
	switch (rhi->GetRHIType())
	{
	case ERHIType::OpenGL3:
		//getMouseButtonFunc = [](EMouseButton btn) {return dynamicInputSystem::FOpenGLInputSystem::GetMouseButton(btn); };
		getMouseButtonFunc = dynamicInputSystem::FOpenGLInputSystem::GetMouseButton;
		getMousePosFunc = dynamicInputSystem::FOpenGLInputSystem::GetMousePos;
		getKeyFunc = dynamicInputSystem::FOpenGLInputSystem::GetKey;
		dynamicInputSystem::FOpenGLInputSystem::RegisterCallbackFuncs();
		break;
	default:	

		break;
	}

	
}

void FInputSystem::RegisterMouseCallback(MouseCallbackFunction func)
{
	mouseCallbackFuncs.push_back(func);
}

void FInputSystem::RegisterKeyCallback(KeyCallbackFunction func)
{
	keyCallbackFuncs.push_back(func);
}

EInputState FInputSystem::GetMouseButton(EMouseButton btn)
{
	return getMouseButtonFunc(btn);
}

FVector2 FInputSystem::GetMousePos()
{
	return getMousePosFunc();
}

EInputState FInputSystem::GetKey(EKeyButton key)
{
	return getKeyFunc(key);
}