#pragma once

#include"RHIOpenGL3Dynamic.h"
#include"WindowClient.h"

#include"Default3DRenderPipeline.h"
class API FRenderSystem
{
	friend class FEditorMainCameraViewport;
	friend class FRenderTaskDispatcher;
	friend class FMeshRenderer;
public:
	static void Create() { renderSystem.reset(new FRenderSystem()); }
	static TSmartPtr<FRenderSystem>& Get() { return renderSystem; }
	inline static TSmartPtr<FRenderSystem> renderSystem{};
	FRenderSystem();  
	~FRenderSystem();
	// call before Init
	void SetCurrentWindow(FRHIWindowRef window);
	void InitRHI(ERHIType type);
	void Init();

	void Tick();

	FRenderSwapDataContext& GetRenderSwapDataContext() { return swapContext[curFlightNum]; }

	TSmartPtr<FDefault3DRenderPipeline> default3DRenderPipeline;
private:
	FRHIWindowRef curWindowRef;

	int flightNums = 2;
	int curFlightNum = 0;
	TArray<FRenderSwapDataContext> swapContext;
};
REF_CLASS(FRenderSystem)
static TSmartPtr<FRenderSystem>& GetRenderSystem() { return FRenderSystem::renderSystem; }