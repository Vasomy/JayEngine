#pragma once

#ifndef UICONTEXT_H
#define UICONTEXT_H
#include<functional>
#include"Containers\Containers.h"
class FUIContext
{
	friend class IUIDrawCommandDispatcher;
	static FUIContext instance;
public:
	static FUIContext& Instance() { return instance; }
	FUIContext(){}
	~FUIContext(){}

	static void Init();
	static void Begin();
	static void End();
	static void Exit();
	static void Draw();
	
private:
	using UIDrawCommand =TFunction<void()>;
	TArray<UIDrawCommand>drawCommands;
	void SubmitUIDrawCommand(UIDrawCommand cmd)
	{
		drawCommands.push_back(cmd);
	}

private:

};

class FUIUidAllocator
{
public:
	using idType = uint64_t;

	static idType Get()
	{
		return ++curId;
	}
private:
	inline static std::atomic<idType> curId = 0;
};

/// <FUIDrawCommandDispatcher>
/// 如果想要绘制ui，一种方法是直接调用ui库的相关绘制指令在相应的Update方法
/// 还可以对于想要具有ui的类继承下面这个类，并重写其中的方法
/// </FUIDrawCommandDispatcher>

class IUIDrawCommandDispatcher
{	
public:
	
	explicit IUIDrawCommandDispatcher()
	{
		FUIContext::Instance().SubmitUIDrawCommand(
			std::bind(&IUIDrawCommandDispatcher::DrawUI,this)
		);
	}
	virtual void DrawUI() = 0;
};



#endif // !UICONTEXT_H
