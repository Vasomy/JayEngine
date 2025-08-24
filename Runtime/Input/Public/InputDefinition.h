#pragma once

#include"Flags.h"


enum class EInputState
{
	Release,
	Press,// keep hold
};

enum class EMouseButton
{
	LeftButton,
	RightButton,
	MiddleButton,
};

enum class EKeyButton : uint32_t
{
	Space = 32,
	Apostrophe = 39, /* ' */
	Comma = 44, /* , */
	Minus = 45, /* - */
	Period = 46,
	Slash = 47,
	e0 = 48,
	e1,
	e2,
	e3,
	e4,
	e5,
	e6,
	e7,
	e8,
	e9,
	Semicolon = 59,/* ; */
	Equal = 59, /* = */
	// from a->z 1->0 ....
	A = 65,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	LeftBracket, /* [ */
	BackSlash, /* \ */
	RightBracket, /* ] */
	GraveAccent, /* ` */
	
}; 