#pragma once
#include"CoreDevelopMarco.h"
#ifndef MATH_H
#define MATH_H

// using glm::
// glm 的矩阵运算是列优先
#if OWN_MATH_VECTOR == J_TRUE

#else
#include"glm/glm.hpp"
#include"glm\gtc\matrix_transform.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include"glm/gtx/quaternion.hpp"


using FVector4 = glm::vec4;
using FVector3 = glm::vec3;
using FVector2 = glm::vec2;

using FVector4f = glm::vec4;
using FVector3f = glm::vec3;
using FVector2f = glm::vec2;

using FMat4 = glm::mat4;

#endif // 


namespace Math
{
	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale);
}


#endif // !MATH_H

