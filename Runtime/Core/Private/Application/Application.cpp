#include"Application\Application.h"
#include<filesystem>
FApplication::FApplication(const FApplicationSpecification& as)
{
	std::filesystem::current_path(as.workingDirectory);
}

FApplication::~FApplication()
{
}

void FApplication::Start()
{
	Log::FLog::Init();
}

void FApplication::ShutDown()
{
}

void FApplication::Run()
{
}
