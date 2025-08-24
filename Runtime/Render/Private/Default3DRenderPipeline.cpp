#include"Default3DRenderPipeline.h"

#include"FileSystem\FileSystem.h"

#include"RHIOpenGL3Dynamic.h"


FRHIVertexArrayBufferRef vao3D;
FRenderItem* ri = new FRenderItem();


void FDefault3DRenderPipeline::InitRenderState(int32 inW,int32 inH)
{

	width = inW;
	height = inH;
	
	auto& rhi = GetRHI();

	FRHIGraphicsPipelineInitializer graphicsInit;

	FShaderInputLayout inputLayout;
	FShaderInputLayoutPart part[3];
	{
		part[0]
			.SetElementSize(sizeof(FVertex))
			.SetInputSlot(0)
			.SetOffset(0)
			.SetParamterCount(3)
			.SetSemanticIndex(0)
			.SetParamterName("position")
			;

		part[1]
			.SetElementSize(sizeof(FVertex))
			.SetInputSlot(1)
			.SetOffset(offsetof(FVertex, normal))
			.SetParamterCount(3)
			.SetSemanticIndex(1)
			.SetParamterName("normal")
			;
		part[2]
			.SetElementSize(sizeof(FVertex))
			.SetInputSlot(2)
			.SetOffset(offsetof(FVertex, texcoords))
			.SetParamterCount(2)
			.SetSemanticIndex(2)
			.SetParamterName("texcoords")
			;
	}
	inputLayout.SetShaderInputs(part);
	graphicsInit.SetFShaderInputLayout(inputLayout);

	FShaderState shaderState;
	TArray<char8> vertexCode,pixelCode;

	{
		FFileStream fs;
		fs.Open(SHADER_DIRECTORY(base3D.vert));
		vertexCode = fs.ReadAllInChar();
		fs.Close();
	}
	{
		FFileStream fs;
		fs.Open(SHADER_DIRECTORY(base3D.frag));
		pixelCode = fs.ReadAllInChar();
		fs.Close();
	}
	
	FRHIVertexShaderRef vertexShader= rhi->CreateVertexShader(vertexCode);
	FRHIPixelShaderRef  pixelShader = rhi->CreatePixelShader(pixelCode);
	
	shaderState.SetFRHIVertexShaderRef(vertexShader)
		.SetFRHIPixelShaderRef(pixelShader);

	shaderState.SetEShaderTypeFlag(EShaderTypeFlagBits::eVertexShader | EShaderTypeFlagBits::ePixelShader);

	graphicsInit
		.SetFShaderState(shaderState)
		;
	
	FRasterizationState rasterizationState;
	rasterizationState
		.SetDiscardEnable(false)
		.SetECullMode(ECullMode::CM_None)
		.SetEFrontFace(EFrontFace::FF_CounterClockwise)
		.SetEPolygonMode(EPolygonMode::PM_Fill)
		.SetLineWidth(1.0f)
		.SetDepthTest(true)
		;
	graphicsInit.rasterizationSate = rasterizationState;

	FRHIUniformState uniformState;
	FRHIUniformAttribution uniformAttributions[3];
	colorUBO = rhi->CreateUniformbuffer(sizeof(FVector4f));
	matrixUBO = rhi->CreateUniformbuffer(sizeof(FConstantBuffer));
	modelUBO = rhi->CreateUniformbuffer(sizeof(FMat4));
	{
		uniformAttributions[0]
			.SetBinding(0)
			.SetName("uColor")
			.SetSize(sizeof(FVector4f))
			.SetUniformType(EUniformUsage::eUniform)
			.SetPUniformbuffer(colorUBO.get())
			;

		uniformAttributions[1]
			.SetBinding(1)
			.SetName("uConstant")
			.SetSize(sizeof(FConstantBuffer))
			.SetUniformType(EUniformUsage::eUniform)
			.SetPUniformbuffer(matrixUBO.get())
			;

		uniformAttributions[2]
			.SetBinding(2)
			.SetName("uModel")
			.SetSize(sizeof(FMat4))
			.SetUniformType(EUniformUsage::eUniform)
			.SetPUniformbuffer(modelUBO.get())
			;

	}
	uniformState
		.SetPAttributions(uniformAttributions)
		;
	graphicsInit.SetUniformState(uniformState);

	colorPipeline = rhi->CreateGraphicsPipelineState(graphicsInit);

	FRHIFramebufferInitializer frameInit;
	frameInit
		.SetAttachmentFlags(EFramebufferAttachmentFlagBits::FA_Color | EFramebufferAttachmentFlagBits::FA_Depth)
		.SetWidth(width)
		.SetHeight(height)
		.SetClearColor({ 0.45f,0.4f,0.4f,1.0f })
		.SetClearDepth(1.0f)
		;
	mainFrame = rhi->CreateRenderpass(frameInit);


	/*colorUBO = rhi->CreateUniformbuffer(sizeof(FVector4f));
	matrixUBO = rhi->CreateUniformbuffer(sizeof(FConstantBuffer));
	modelUBO = rhi->CreateUniformbuffer(sizeof(FMat4));*/

	const static std::vector<FVertex>squre_data = {
		// positions          // normals           // texture coords
		{-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f},
		{0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f},
		{0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f},
		{0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f},
		{-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f},
		{ -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f},

		{-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f },
		{0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f},
		{0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f},
		{0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f },
		{-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f},
		{-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f},

		{-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f},
		{-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f},
		{-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f},
		{-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f},
		{-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f},
		{-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f},

		 {0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f},
		 {0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f},
		 {0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f},
		 {0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f},
		 {0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f},
		 {0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f},

		{-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f},
		 {0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f},
		 {0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f},
		 {0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f},
		{-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f},
		{-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f},

		{-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f},
		 {0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f},
		 {0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f},
		 {0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f},
		{-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f},
		{-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f}
	};

	TArray<uint32>indices;
	indices.resize(36);
	for (int i = 0; i < 36; ++i)indices[i] = i;
	vao3D = rhi->CreateVertexBufferArray(
		squre_data.data(),squre_data.size(),sizeof(FVertex)
		,indices.data(),36,sizeof(uint32));
	return;



}

void FDefault3DRenderPipeline::DrawCall()
{
	auto& rhi = GetRHI();
	if (rhi)
	{
		
		// update uniformbuffer
		

		rhi->SetGraphicsPipelineState(colorPipeline);
		rhi->BeginRenderpass(mainFrame);

		rhi->UpdateUniformbuffer(matrixUBO.get(), &constantBuffer, 0, sizeof(FConstantBuffer));

		for (int32 i = 0; i < renderItems.size(); ++i)
		{
			rhi->UpdateUniformbuffer(colorUBO.get(), &renderItems[i].color, 0, sizeof(FVector4));
			rhi->UpdateUniformbuffer(modelUBO.get(), &renderItems[i].model, 0, sizeof(FMat4));

			rhi->RHIDrawIndexed(renderItems[i].vertexArrayBuffer);

		}

		rhi->EndRenderpass();
	}
}

void FDefault3DRenderPipeline::UpdateCameraData(FRenderCamera* camera_)
{
	camera_->UpdateCameraVector();
	constantBuffer.proj = camera_->GetProjectionMatrix();
	constantBuffer.view = camera_->GetViewMatrix();

	constantBuffer.projView = constantBuffer.proj * constantBuffer.view;
}

FDefault3DRenderPipeline::~FDefault3DRenderPipeline()
{
	vao3D.reset();
	
}


void FDefault3DRenderPipeline::ProcessRenderData(const FScene&scene)
{
	renderItems.clear();
	
	{
		UpdateCameraData(&FCamera::mainCamera->camera);
		//std::cout << "NONNULL!\n";
	}
	for (auto& i : scene.allGameObjects)
	{
		//std::cout << "????\n";
		if (i->HasComponent<FSpriteRenderer>()) {
			FRenderItem r;
			auto& rc = i->GetComponent<FSpriteRenderer>();

			r.entityId = i->GetEntityId();

			r.vertexArrayBuffer = vao3D.get();
			r.model = glm::mat4(1.0f);

			const auto& transform = i->GetTransform();
			r.model = glm::translate(r.model, transform.position);
			r.model = glm::scale(r.model, transform.scale);
			r.model = glm::rotate(r.model, transform.rotation.x, { 1,0,0 });
			r.model = glm::rotate(r.model, transform.rotation.y, { 0,1,0 });
			r.model = glm::rotate(r.model, transform.rotation.z, { 0,0,1 });
			r.color = transform.color;
			renderItems.push_back(r);
		}
		if (i->HasComponent<FMeshRenderer>())
		{
			FRenderItem r;
			auto& mr = i->GetComponent<FMeshRenderer>();
			r.entityId = i->GetEntityId();
			r.model = glm::mat4(1.0f);
			r.vertexArrayBuffer = mr.rawMesh.vao.get();
			const auto& transform = i->GetTransform();
			r.model = glm::translate(r.model, transform.position);
			r.model = glm::scale(r.model, transform.scale);
			r.model = glm::rotate(r.model, transform.rotation.x, { 1,0,0 });
			r.model = glm::rotate(r.model, transform.rotation.y, { 0,1,0 });
			r.model = glm::rotate(r.model, transform.rotation.z, { 0,0,1 });
			r.color = mr.color;
			renderItems.push_back(r);
		}
	}
}