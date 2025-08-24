#include"UI\UIContext.h"
#include"UI\ImGui.h"

FUIContext FUIContext::instance = FUIContext();

void FUIContext::Init()
{
	FImGuiContextProxy::Init();
}

void FUIContext::Exit()
{
	FImGuiContextProxy::Exit();
}

void FUIContext::Begin()
{
	FImGuiContextProxy::Begin();
}

void FUIContext::Draw()
{
	// submit draw command
	for (auto& dc : instance.drawCommands)
	{
		dc();
	}
	FImGuiContextProxy::Draw();
}

void FUIContext::End()
{
	FImGuiContextProxy::End();
}