#include"WindowClient.h"

#define WindowClient_Debug
#ifdef WindowClient_Debug
#include"glad\glad.h"
#include"GLFW\glfw3.h"
#include"RHIOpenGL3Resource\RHIOpenGL3Resource.h"
// for t
#include"FOpenGL.h"

//#define STB_IMAGE_IMPLEMENTATION
#include"stbimage/stb_image.h"

#include"RenderCommon.h"


#endif // WindowClient_Debug

FWindowClient::FWindowClient()
{
}
FWindowClient::~FWindowClient()
{
	
}

void FWindowClient::Init(int32 width,int32 height,bool isFullScreen)
{
	auto rhi = GetRHI();
	rhiWindow = rhi->CreateWindowByRHI(width, height, isFullScreen);

	runningTime = rhiWindow->GetRunningTime();
}

void FWindowClient::InitWindowGraphics()
{

}




void FWindowClient::PollEvents()
{
	rhiWindow->PollEvents();
}

bool FWindowClient::ShouldWindowClose()
{
	return this->rhiWindow->ShouldClose();
}

void FWindowClient::SwapBuffers()
{
	rhiWindow->SwapBuffers();
}

float32 FWindowClient::GetDeltaTime()
{
	return deltaTime;
}

void FWindowClient::HandleWindow()
{
	SwapBuffers();
	PollEvents();
	float64 temp = rhiWindow->GetRunningTime();
	deltaTime = temp - runningTime;
	runningTime = temp;
}