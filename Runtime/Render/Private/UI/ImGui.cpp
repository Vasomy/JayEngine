#include"UI\ImGui.h"
#include"RHIDynamic.h"
#include"glad\glad.h"
#include"GLFW\glfw3.h"
void FImGuiContextProxy::Init()
{
	ImGui::CreateContext();
	SetStyle();
	auto rhi = GetRHI();
	auto rhiType = rhi->GetRHIType();
	bool isDone = true;
	switch (rhiType)
	{
	case Undefined:
		COUT_ERROR_INFO(FImGuiContextProxy, "Failed to init imgui,because RHI ERHIType is undefined!");
		break;
	case D3D12:
		break;
	case OpenGL3:
		isDone&=ImGui_ImplOpenGL3_Init("#version 330");
		isDone&=ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true);
		break;
	default:
		break;
	}

	ImGuizmo::Enable(true);

	if (!isDone)
		COUT_ERROR_INFO(FImGuiContextProxy, "Failed to init imgui!");

	auto& iIo = ImGui::GetIO();
	iIo.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

void FImGuiContextProxy::Begin()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGuizmo::BeginFrame();
	
	ImGui::DockSpaceOverViewport();
}

void FImGuiContextProxy::Draw() // äÖÈ¾Ö¸Áî
{

}

void FImGuiContextProxy::End()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void FImGuiContextProxy::Exit()
{

}

void FImGuiContextProxy::SetStyle()
{
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

	auto& colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.1f, 0.1f, 1.0f };

	colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.2f, 0.2f, 1.0f };
	colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.3f, 0.3f, 1.0f };
	colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };

	colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.2f, 0.2f, 1.0f };
	colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.3f, 0.3f, 1.0f };
	colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };

	colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.2f, 0.2f, 1.0f };
	colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.3f, 0.3f, 1.0f };
	colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };

	colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };
	colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.38f, 0.38f, 1.0f };
	colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.28f, 0.28f, 1.0f };
	colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };
	colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.2f, 0.2f, 1.0f };

	colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };
	colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f };

	auto& ItemSpacing = ImGui::GetStyle().ItemSpacing;
	ItemSpacing = ImVec2{ 10,11 };
	auto& WindowPadding = ImGui::GetStyle().WindowPadding;
	WindowPadding = ImVec2{ 8,9 };
	auto& FramePadding = ImGui::GetStyle().FramePadding;
	FramePadding = ImVec2{ 10,10 };
	auto& WindowRounding = ImGui::GetStyle().WindowRounding;
	WindowRounding = 12.0f;
	auto& ChildRounding = ImGui::GetStyle().ChildRounding;
	ChildRounding = 12.0f;
	auto& FrameRounding = ImGui::GetStyle().FrameRounding;
	FrameRounding = 12.0f;
	auto& PopupRounding = ImGui::GetStyle().PopupRounding;
	PopupRounding = 12.0f;
	auto& ScrollbarRounding = ImGui::GetStyle().ScrollbarRounding;
	ScrollbarRounding = 12.0f;
	auto& GrabRounding = ImGui::GetStyle().GrabRounding;
	GrabRounding = 12.0f;
	auto& LogSliderDeadzone = ImGui::GetStyle().LogSliderDeadzone;
	LogSliderDeadzone = 12.0f;
	auto& TabRounding = ImGui::GetStyle().TabRounding;
	TabRounding = 12.0f;

	//auto* font = io.Fonts->AddFontFromFileTTF("asset/fonts/art_font.ttf",18);
	auto* font = io.Fonts->AddFontFromFileTTF("Asset/Fonts/JetBrainsMono-Light.ttf",18);
	auto* bF = io.Fonts->AddFontFromFileTTF("Asset/Fonts/JetBrainsMono-Bold.ttf",18);
	defaultFont = font;
	io.FontDefault = font;
	boldFont = bF;
}