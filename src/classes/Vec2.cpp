#include "Vec2.hpp"

Vec2::Vec2()
{}

Vec2::Vec2(float _x, float _y)
	:	x(_x),
		y(_y)
{}

Vec2::Vec2(Vec2 const &original)
	:	x(original.x),
		y(original.y)
{
}

Vec2::~Vec2()
{}

Vec2	&Vec2::operator=(Vec2 const &original)
{
	if (this != &original)
	{
		x = original.x;
		y = original.y;
	}
	return (*this);
}

Vec2	&Vec2::operator+=(Vec2 const &other)
{
	*this = *this + other;
	return (*this);
}

Vec2	&Vec2::operator-=(Vec2 const &other)
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

Vec2	Vec2::operator+(Vec2 const &other) const
{
	return (Vec2(x + other.x, y + other.y));
}

Vec2	Vec2::operator-(Vec2 const &other) const
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

bool	Vec2::operator==(Vec2 const &other) const
{
	return (x == other.x && y == other.y);
}

bool	Vec2::operator!=(Vec2 const &other) const
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

float	Vec2::length() const
{
	return (std::sqrt(x * x + y * y));
}

float	Vec2::dot(Vec2 const &other) const
{
	return (x * other.x + y *other.y);
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

Vec2	Vec2::changedBasis(Vec2 const &basis) const
{
	return (basis * x + basis.left() * y);
}

Vec2	&Vec2::changeBasis(Vec2 const &basis)
{
	*this = changedBasis(basis);
	return (*this);
}

Vec2	Vec2::rotated(float radian) const
{
	float cos = std::cos(radian);
	float sin = std::sin(radian);

	return (Vec2
	{
		x * cos  + y * sin,
		x * -sin + y * cos
	});
}

Vec2	&Vec2::rotate(float radian)
{
	*this = rotated(radian);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, Vec2 const &vec2)
{
	os << "(" << vec2.x << "," << vec2.y << ")";
	return (os);
}
