#pragma once

#ifndef DYNAMIC_INPUT_SYSTEM_H

#define DYNAMIC_INPUT_SYSTEM_H

#include"InputDefinition.h"
#include"Containers\JArray\JArray.h"

#include"Math\Math.h"

namespace dynamicInputSystem
{
	

	class FKayState
	{
	public:
		FKayState()
		{

		}
	};

	class FOpenGLInputSystem
	{
	public:
		static EInputState InputStateCast(unsigned int state);
		static EMouseButton MouseButtonCast(unsigned int button);
		static EKeyButton KeyButtonCast(unsigned int button);
		static unsigned int InputStateCast(EInputState state);
		static unsigned int MouseButtonCast(EMouseButton button);
		static unsigned int KeyButtonCast(EKeyButton button);

		static EInputState GetKey(EKeyButton button);
		static EInputState GetMouseButton(EMouseButton button);
		static FVector2   GetMousePos();

		static void RegisterCallbackFuncs();

	};
}

#endif // !DYNAMIC_INPUT_SYSTEM_H
