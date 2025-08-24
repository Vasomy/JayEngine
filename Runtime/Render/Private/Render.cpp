#include "Render.h"
#include"Render.h"
#include"UI\UIContext.h"
#include"Log.h"

FRenderSystem::FRenderSystem()
{
	
}

FRenderSystem::~FRenderSystem()
{

}

void FRenderSystem::SetCurrentWindow(FRHIWindowRef window)
{
	curWindowRef = window;
}

void FRenderSystem::InitRHI(ERHIType type)
{
	auto& rhi = GetRHI();
	switch (type)
	{
	case Undefined:
		break;
	case D3D12:
		break;
	case OpenGL3:
		rhi.reset(new FRHIOpenGL3Dynamic());
		break;
	default:
		break;
	}
	rhi->Init();
}

void FRenderSystem::Tick()
{
	default3DRenderPipeline->DrawCall();
}

void FRenderSystem::Init()
{
	auto rhi = GetRHI();
	rhi->PostInit();
	std::cout << "DOWN\n";

	default3DRenderPipeline.reset(new FDefault3DRenderPipeline());
	default3DRenderPipeline->InitRenderState(1600,900);
	
	swapContext.resize(flightNums);

	CORE_ASSERT_ERROR(flightNums != 0, "FRenderSystem : flightNums should strict greater than 0 !");
}