#pragma once

#include"Render.h"
#include"Input.h"


class API Engine
{
	friend Engine* GetEngine();
public:
	/// <summary>
	/// call before func : "Start()"
	/// </summary>
	void Init();
	/// <summary>
	/// call before func : "Run()"
	/// </summary>
	void Start();
	/// <summary>
	/// clear and release engine holds resource
	/// </summary>
	void ShutDown();
	/// <summary>
	/// basic loop func
	/// </summary>
	void Run();
private:

	FRenderSystemRef    gRenderSystemRef;
	FInputSystem		gInputSystem;

	inline static Engine* gInstance = nullptr;
};

