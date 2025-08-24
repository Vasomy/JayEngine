#pragma once
#ifndef RENDER_TASK_DISPATCHER
#define RENDER_TASK_DISPATCHER
#include"Render.h"
class FRenderTaskDispatcher
{
public:
	static void RenderScene(TSmartPtr<FScene>&activeScene);
private:

};
#endif // !RENDER_TASK_DISPATCHER