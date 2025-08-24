#pragma once

#ifndef INPUT_H

#define INPUT_H
#include"InputDefinition.h"
#include"DynamicInputSystem.h"
#include"Math\Math.h"

#include"Containers\Containers.h"
// 如果不是统一的从win32构建窗口，开发者应该自己实现相应的输入检测的逻辑
// 尽可能的实现运行时多态
class FInputSystem
{
public:

	static void Init();

	static EInputState GetMouseButton(EMouseButton mbtn);
	static FVector2 GetMousePos();
	static EInputState GetKey(EKeyButton key);
	//using KeyCallbackFunction = void(*)(EKeyButton button,EInputState state);
	using KeyCallbackFunction = std::function<void(EKeyButton,EInputState)>;
	static void RegisterKeyCallback(KeyCallbackFunction func);
	//using MouseCallbackFunction = void(*)(EMouseButton button,EInputState state);
	using MouseCallbackFunction = std::function<void(EMouseButton,EInputState)>;
	static void RegisterMouseCallback(MouseCallbackFunction func);
private:
	using GetMouseButtonFunc = EInputState(*)(EMouseButton);
	inline static GetMouseButtonFunc getMouseButtonFunc = nullptr;
	using GetMousePosFunc = FVector2(*)(void);
	inline static GetMousePosFunc getMousePosFunc = nullptr;
	using GetKeyFunc = EInputState(*)(EKeyButton);
	inline static GetKeyFunc getKeyFunc = nullptr;
public:
	inline static TArray<KeyCallbackFunction>keyCallbackFuncs;
	inline static TArray<MouseCallbackFunction>mouseCallbackFuncs;

};



#endif // !INPUT_H
