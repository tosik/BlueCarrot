
#pragma once

namespace utility
{
	// ARGB Še8bits Color
	struct Color
	{
		Color(unsigned char _a, unsigned char _r, unsigned char _g, unsigned char _b)
			: a(_a)
			, r(_r)
			, g(_g)
			, b(_b)
		{
		}
		unsigned char a, r, g, b;
	};

	template<typename T>
	struct Size
	{
		Size(T w, T h) : width(w), height(h) {}
		Size() {}

		T width;
		T height;
	};

	template<typename T>
	struct Rect
	{
		Rect(T l, T t, T w, T h) : left(l), top(t), width(w), height(h) {}
		Rect() {}

		T left;
		T top;
		T width;
		T height;
	};

	struct UV
	{
		UV(float _u, float _v, float _um, float _vm) : u(_u), v(_v), um(_um), vm(_vm) {}
		UV() {}

		float u, v, um, vm;
	};

	struct Vector3
	{
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
		Vector3() {}

		float x, y, z;
	};
}
