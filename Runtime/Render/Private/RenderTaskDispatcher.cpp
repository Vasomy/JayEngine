#include"RenderTaskDispatcher.h"

void FRenderTaskDispatcher::RenderScene(TSmartPtr<FScene>& scene)
{
	auto& ecs_registry = scene->registry;

	auto meshRendererView = ecs_registry.view<FMeshRenderer>();

	auto& swapContext = GetRenderSystem()->GetRenderSwapDataContext();
	swapContext.constantBuffer.proj = swapContext.projCamera->GetProjectionMatrix();
	swapContext.constantBuffer.view = swapContext.projCamera->GetViewMatrix();
	swapContext.constantBuffer.projView = swapContext.constantBuffer.proj*swapContext.constantBuffer.view;


	if (!meshRendererView.empty())
	{
		
	}

	for (auto& ett : meshRendererView)
	{
		FGameObject obj{ ett,scene.get() };
		auto& mr = obj.GetComponent<FMeshRenderer>();

		auto* pl = mr.pipeline;
	}
}