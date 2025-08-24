#pragma once

#include"Math/Math.h"

#include"RHICommon.h"
using FIndex = uint32_t;



struct FVertex
{
	FVector3f position;
	FVector3f normal;
	FVector2f texcoords;

	FVertex() {}

	FVertex(
		float32 p1, float32 p2, float32 p3,
		float32 n1, float32 n2, float32 n3,
		float32 t1, float32 t2
	)
	{
		position = { p1,p2,p3 };
		normal = { n1,n2,n3 };
		texcoords = { t1,t2 };
	}


	static TArray<FShaderInputLayoutPart> GetInputLayout()
	{
		static bool done = false;
		static TArray<FShaderInputLayoutPart> parts;
		if (!done) {
			TArrayProxy<FShaderInputLayoutPart> arrayProxy;
			FShaderInputLayoutPart part[3];
			part[0]
				.SetElementSize(sizeof(FVertex))
				.SetInputSlot(0)
				.SetOffset(0)
				.SetParamterCount(3)
				.SetSemanticIndex(0)
				.SetParamterName("position")
				;

			part[1]
				.SetElementSize(sizeof(FVertex))
				.SetInputSlot(1)
				.SetOffset(offsetof(FVertex, normal))
				.SetParamterCount(3)
				.SetSemanticIndex(1)
				.SetParamterName("normal")
				;
			part[2]
				.SetElementSize(sizeof(FVertex))
				.SetInputSlot(2)
				.SetOffset(offsetof(FVertex, texcoords))
				.SetParamterCount(2)
				.SetSemanticIndex(2)
				.SetParamterName("texcoords")
				;
			arrayProxy = part;
			parts = arrayProxy.AsArray();
			done = true;
		}

		return parts;
	}
};



struct FColor
{
	union
	{
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

	FColor()
		:r(1.0f),g(1.0f),b(1.0f),a(1.0f)
	{}

	FColor(float f1, float f2, float f3, float f4 = 1.0f)
	{
		r = f1;
		g = f2;
		b = f3;
		a = f4;
	}

	FColor(const FVector4& vec4)
	{
		r = vec4.x;
		g = vec4.y;
		b = vec4.z;
		a = vec4.w;
	}


	FColor(const FColor& rhs) {
		memcpy(this, &rhs, sizeof(FColor));
	}

	// static function
	static FColor Red()
	{
		return { 1,0,0,1 };
	}
};