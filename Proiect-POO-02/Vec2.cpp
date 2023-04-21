
#include "Vec2.hpp"

#include "Exception.hpp"

Vec2::Vec2(const double nr)
	:
	x(nr),
	y(nr)
{
}

Vec2::Vec2(const double _x, const double _y)
	:
	x(_x),
	y(_y)
{
}

Vec2::Vec2(const Vec2& other)
	:
	x(other.x),
	y(other.y)
{
}

Vec2::Vec2(Vec2&& other) noexcept
	:
	x(0),
	y(0)
{
	x = other.x;
	y = other.y;

	other.x = 0;
	other.y = 0;
}

Vec2::~Vec2()
{
}

Vec2& Vec2::operator=(const Vec2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vec2& Vec2::operator=(Vec2&& other) noexcept
{
	x = other.x;
	y = other.y;

	other.x = 0;
	other.y = 0;
	return *this;
}

Vec2 Vec2::operator+(const Vec2& other) const
{
	return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const
{
	return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(const double factor) const
{
	return Vec2(x * factor, y * factor);
}

Vec2& Vec2::operator+=(const Vec2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vec2& Vec2::operator-=(const Vec2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vec2& Vec2::operator*=(const double factor)
{
	x *= factor;
	y *= factor;
	return *this;
}

bool Vec2::operator==(const Vec2& other) const
{
	return (!(y - other.y) and !(x * other.y - y * other.x) and !(other.x - x) and length() == other.length());
}

bool Vec2::operator!=(const Vec2& other) const
{
	return !(*this == other);
}

bool Vec2::operator!() const
{
	return !(x and y);
}

bool Vec2::operator>(const Vec2& other) const
{
	return (length() > other.length());
}

bool Vec2::operator<(const Vec2& other) const
{
	return (length() < other.length());
}

bool Vec2::operator<=(const Vec2& other) const
{
	return (length() <= other.length());
}

bool Vec2::operator>=(const Vec2& other) const
{
	return (length() >= other.length());
}

Vec2::operator bool() const
{
	return (x != 0 and y != 0);
}

void Vec2::set_x(const double _x)
{
	x = _x;
}

void Vec2::set_y(const double _y)
{
	y = _y;
}

double Vec2::length() const
{
	return std::sqrt(x * x + y * y);
}

void Vec2::normalize()
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	x /= len;
	y /= len;
}

Vec2* Vec2::normalized() const
{
	double len = length();
	if (len == 0)
		throw normalize_by_zero();
	return new Vec2(x / len, y / len);
}

double Vec2::dot_prod(const Vec2& v0, const Vec2& v1)
{
	return v0.x * v1.x + v0.y * v1.y;
}

std::istream& operator>>(std::istream& is, Vec2& me)
{
	is >> me.x >> me.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vec2& me)
{
	os << "x: " << me.x << " | y: " << me.y;
	return os;
}