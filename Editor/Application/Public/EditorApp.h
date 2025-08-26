#pragma once
#include"Application/Application.h"
#include"WindowClient.h"



class FEditor : public FApplication
{
public:
	FEditor(FApplicationSpecification& as);
	~FEditor();

	virtual void Start();
	virtual void ShutDown();
	virtual void Run();

private:
};