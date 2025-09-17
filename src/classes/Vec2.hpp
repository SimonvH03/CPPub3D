#ifndef VEC2_HPP
# define VEC2_HPP

# include <cmath>
# include <iostream>

class	Vec2
{
	public:
		float x = 0;
		float y = 0;

		Vec2();
		Vec2(float _x, float _y);
		Vec2(Vec2 const &original);
		~Vec2();

		Vec2	&operator=(Vec2 const &original);
		Vec2	&operator+=(Vec2 const &other);
		Vec2	&operator-=(Vec2 const &other);
		Vec2	&operator*=(float scalar);
		Vec2	&operator/=(float scalar);

		Vec2	operator+(Vec2 const &other) const;
		Vec2	operator-(Vec2 const &other) const;
		Vec2	operator*(float scalar) const;
		Vec2	operator/(float scalar) const;
		Vec2	operator-() const;

		bool	operator==(Vec2 const &other) const;
		bool	operator!=(Vec2 const &other) const;
	explicit	operator bool() const;

		Vec2	right() const;
		Vec2	left() const;
		float	length() const;
		float	dot(Vec2 const &other) const;

		Vec2	normalised() const;
		Vec2	&normalise();
		Vec2	changedBasis(Vec2 const &basis) const;
		Vec2	&changeBasis(Vec2 const &basis);
		Vec2	rotated(float radian) const;
		Vec2	&rotate(float radian);

};

std::ostream &operator<<(std::ostream &os, Vec2 const &vec2);

#endif
