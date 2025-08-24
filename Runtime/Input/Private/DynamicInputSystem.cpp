#include"DynamicInputSystem.h"

using namespace dynamicInputSystem;

#include"glad\glad.h"
#include"GLFW\glfw3.h"

EInputState FOpenGLInputSystem::InputStateCast(unsigned int state)
{
	switch (state)
	{
	case GLFW_PRESS:
		return EInputState::Press;
	case GLFW_RELEASE:
		return EInputState::Release;
	default:
		break;
	}
	
}
EMouseButton FOpenGLInputSystem::MouseButtonCast(unsigned int button)
{
	switch (button)
	{
	case GLFW_MOUSE_BUTTON_LEFT:
		return EMouseButton::LeftButton;
	case GLFW_MOUSE_BUTTON_RIGHT:
		return EMouseButton::RightButton;
	default:
		break;
	}
}
EKeyButton FOpenGLInputSystem::KeyButtonCast(unsigned int button)
{
	return static_cast<EKeyButton>(button);
}


unsigned int FOpenGLInputSystem::InputStateCast(EInputState state)
{
	switch (state)
	{
	case EInputState::Release:
		return GLFW_RELEASE;
		break;
	case EInputState::Press:
		return GLFW_PRESS;
		break;
	default:
		break;
	}
}
unsigned int FOpenGLInputSystem::MouseButtonCast(EMouseButton button)
{
	switch (button)
	{
	case EMouseButton::LeftButton:
		return GLFW_MOUSE_BUTTON_LEFT;
		break;
	case EMouseButton::RightButton:
		return GLFW_MOUSE_BUTTON_RIGHT;
		break;
	case EMouseButton::MiddleButton:
		return GLFW_MOUSE_BUTTON_MIDDLE;
		break;
	default:
		break;
	}
}
unsigned int FOpenGLInputSystem::KeyButtonCast(EKeyButton button)
{
	return static_cast<unsigned int>(button);
}

EInputState FOpenGLInputSystem::GetKey(EKeyButton button)
{
	GLenum btn = glfwGetKey(glfwGetCurrentContext(), KeyButtonCast(button));
	return InputStateCast(btn);
}
EInputState FOpenGLInputSystem::GetMouseButton(EMouseButton button)
{
	GLenum btn = glfwGetMouseButton(glfwGetCurrentContext(), MouseButtonCast(button));
	return InputStateCast(btn);
}
FVector2 FOpenGLInputSystem::GetMousePos()
{
	double x,y;
	glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);
	return FVector2(x, y);
}


#include"Input.h"
void CallMouseCallbackFuncs(GLFWwindow* window, int button, int action, int mods)
{
	auto mButton = FOpenGLInputSystem::MouseButtonCast(button);
	auto state = FOpenGLInputSystem::InputStateCast(action);

	for (auto& func : FInputSystem::mouseCallbackFuncs)
	{
		func(mButton, state);
	}
	
}

void FOpenGLInputSystem::RegisterCallbackFuncs()
{
	glfwSetMouseButtonCallback(glfwGetCurrentContext(), CallMouseCallbackFuncs);
}

