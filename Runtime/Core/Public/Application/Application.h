#ifndef APPLICATION_H
#define APPLICATION_H
#include"Containers\Containers.h"
#include"Log.h"
struct FApplicationSpecification
{
	FString name = "Hazel Application";
	FString workingDirectory;
};

class FApplication
{
public:
	FApplication(const FApplicationSpecification& as);
	~FApplication();

	virtual void Start();
	virtual void ShutDown();
	virtual void Run();

protected:
	

private:

};


#endif // !APPLICATION_H
