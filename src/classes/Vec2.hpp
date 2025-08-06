#ifndef VEC2_HPP
# define VEC2_HPP

# include <cmath>

class	Vec2
{
	public:
		float x;
		float y;

		Vec2();
		Vec2(float _x, float _y);
		Vec2(const Vec2 &original);
		~Vec2();

		Vec2	&operator=(const Vec2 &original);
		Vec2	&operator+=(const Vec2 &other);
		Vec2	&operator-=(const Vec2 &other);
		Vec2	&operator*=(float scalar);
		Vec2	&operator/=(float scalar);

		Vec2	operator+(const Vec2 &other) const;
		Vec2	operator-(const Vec2 &other) const;
		Vec2	operator*(float scalar) const;
		Vec2	operator/(float scalar) const;
		Vec2	operator-() const;

		bool	operator==(const Vec2 &other) const;
		bool	operator!=(const Vec2 &other) const;
	explicit	operator bool() const;

		Vec2	right() const;
		Vec2	left() const;
		float	dot(const Vec2 &other) const;
		float	length() const;
		Vec2	normalised() const;

		Vec2	&normalise();

};

#endif
