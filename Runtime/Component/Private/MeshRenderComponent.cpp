#include"MeshRenderComponent.h"
#include"Render.h"
FMeshRenderer::FMeshRenderer()
{
	pipeline = GetRenderSystem()->default3DRenderPipeline.get();
}