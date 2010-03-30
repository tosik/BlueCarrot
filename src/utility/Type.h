
#pragma once

namespace BlueCarrot
{
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

			Size<T> operator+(const Size<T> & pos)
			{
				return Position<T>(width + pos.width, top + pos.height);
			}

			Size<T> operator-(const Size<T> & pos)
			{
				return Position<T>(width - pos.width, top - pos.height);
			}

			Size<T> & operator+=(const Size<T> & pos)
			{
				width += pos.width;
				height += pos.height;
				return (*this);
			}

			Size<T> & operator-=(const Size<T> & pos)
			{
				width -= pos.width;
				height -= pos.height;
				return (*this);
			}

			void SetSize(const utility::Size<T> & rect)
			{
				width = rect.width;
				height = rect.height;
			}
		};

		template<typename T>
		struct Position
		{
			Position(T l, T t) : left(l), top(t) {}
			Position() {}

			T left;
			T top;

			Position<T> operator+(const Position<T> & pos)
			{
				return Position<T>(left + pos.left, top + pos.top);
			}

			Position<T> operator-(const Position<T> & pos)
			{
				return Position<T>(left - pos.left, top - pos.top);
			}

			Position<T> & operator+=(const Position<T> & pos)
			{
				left += pos.left;
				top += pos.top;
				return (*this);
			}

			Position<T> & operator-=(const Position<T> & pos)
			{
				left -= pos.left;
				top -= pos.top;
				return (*this);
			}

			void SetPosition(const utility::Position<T> & rect)
			{
				left = rect.left;
				top = rect.top;
			}

			void Move(Position<T> move)
			{
				(*this) += move;
			}
		};

		template<typename T>
		struct Rect
			: public Position<T>
			, public Size<T>
		{
			Rect(T l, T t, T w, T h)
				: Position(l, t), Size(w, h) {}
			Rect() {}

			void SetPosition(Position<T> position)
			{
				left = position.left;
				top = position.top;
			}

			void SetSize(Size<T> size)
			{
				width = size.width;
				height = size.height;
			}

			void SetRect(const utility::Rect<T> & rect)
			{
				SetPosition(rect);
				SetSize(rect);
			}
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
}
