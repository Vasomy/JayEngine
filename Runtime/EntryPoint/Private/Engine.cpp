#include"Engine.h"

Engine* GetEngine()
{
	return Engine::gInstance;
}

void Engine::Init()
{
}

void Engine::Start()
{
	gRenderSystemRef.reset(
		new FRenderSystem()
	);
}

void Engine::ShutDown()
{
}

void Engine::Run()
{
}
