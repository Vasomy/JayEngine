#include"WindowClient.h"
#include"Render.h"
#include"Log.h"
#include"Engine.h"
int main() {

	::Log::FLog::Init();
	FFileSystem::Check();
	FRenderSystem rs;
	rs.InitRHI(ERHIType::OpenGL3);
	FWindowClient wc;
	wc.Init(600,400,0);
	rs.Init();

	while (!wc.ShouldWindowClose()) {
		wc.HandleWindow();
	}
}