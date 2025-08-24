#pragma once
#include<iostream>

#include"RHIDynamic.h"

class API FWindowClient
{
public:
	FWindowClient();
	~FWindowClient();
	void Init(int width, int height, bool isFullScreen);
	void HandleWindow();

	// 如果是在有交换链的图形API下，该函数用来初始化窗口的交换链
	// 在OpenGL下仅有 SetSwapInterval（1）
	void InitWindowGraphics();

	bool ShouldWindowClose();
	void SwapBuffers();
	void PollEvents();
	FRHIWindowRef GetRHIWindow() { return rhiWindow; }
	float GetDeltaTime();

private:
	FRHIWindowRef rhiWindow;

	float64 runningTime;
	float64 deltaTime;
};

REF_CLASS(FWindowClient)
