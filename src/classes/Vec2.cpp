#include "Vec2.hpp"

Vec2::Vec2() : x(0), y(0)
{}

Vec2::Vec2(float _x, float _y) : x(_x), y(_y)
{}

Vec2::Vec2(const Vec2 &original)
{
	*this = original;
}

Vec2::~Vec2()
{}

Vec2	&Vec2::operator=(const Vec2 &original)
{
	if (this != &original)
	{
		x = original.x;
		y = original.y;
	}
	return (*this);
}

Vec2	&Vec2::operator+=(const Vec2 &other)
{
	*this = *this + other;
	return (*this);
}

Vec2	&Vec2::operator-=(const Vec2 &other)
{
	*this = *this - other;
	return (*this);
}

Vec2	&Vec2::operator*=(float	scalar)
{
	*this = *this * scalar;
	return (*this);
}

Vec2	&Vec2::operator/=(float	scalar)
{
	*this = *this / scalar;
	return (*this);
}

Vec2	Vec2::operator+(const Vec2 &other) const
{
	return (Vec2(x + other.x, y + other.y));
}

Vec2	Vec2::operator-(const Vec2 &other) const
{
	return (Vec2(x - other.x, y - other.y));
}

Vec2	Vec2::operator*(float scalar) const
{
	return (Vec2(x * scalar, y * scalar));
}

Vec2	Vec2::operator/(float scalar) const
{
	return (Vec2(x / scalar, y / scalar));
}

Vec2	Vec2::operator-() const
{
	return (Vec2(-x, -y));
}

bool	Vec2::operator==(const Vec2 &other) const
{
	return (x == other.x && y == other.y);
}

bool	Vec2::operator!=(const Vec2 &other) const
{
	return (x != other.x && y != other.y);
}

Vec2::operator bool() const
{
	return (x != 0.0f || y != 0.0f);
}

Vec2	Vec2::right() const
{
	return (Vec2(y, -x));
};

Vec2	Vec2::left() const
{
	return (Vec2(-y, x));
};

float	Vec2::dot(const Vec2 &other) const
{
	return (x * other.x + y *other.y);
}

float	Vec2::length() const
{
	return (std::sqrt(x * x + y * y));
}

Vec2	Vec2::normalised() const
{
	return (*this / length());
}

Vec2	&Vec2::normalise()
{
	*this /= length();
	return (*this);
}
