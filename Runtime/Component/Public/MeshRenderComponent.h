#pragma once

#include"RenderCommon.h"
#include"Serialization.h"

#include"BaseComponent.h"
//#include"Default3DRenderPipeline.h"

class FDefault3DRenderPipeline;
struct FMeshRenderer
{
	FMeshRenderer();
	FVector4 color;
	FRawMesh rawMesh;

	FDefault3DRenderPipeline* pipeline;
};