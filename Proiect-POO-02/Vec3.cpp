#include "Vec3.hpp"

Vec3::Vec3(const double _x, const double _y, const double _z)
	:
	Vec2::Vec2(_x, _y),
	z(_z)
{
}

Vec3::Vec3(const Vec2& other, const double _z)
	:
	Vec2::Vec2(other),
	z(_z)
{
}

Vec3::Vec3(const Vec3& other)
	:
	Vec2::Vec2(other.x, other.y),
	z(other.z)
{
}

Vec3::Vec3(const Vec3&& other) noexcept
	:
	Vec2::Vec2(other.x, other.y),
	z(other.z)
{
}

Vec3::~Vec3()
{
}

Vec3& Vec3::operator=(const Vec3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vec3& Vec3::operator=(const Vec3&& other) noexcept
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vec3 Vec3::operator+(const Vec3& other) const
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(const double factor) const
{
	return Vec3(x * factor, y * factor, z * factor);
}

Vec3& Vec3::operator+=(const Vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vec3& Vec3::operator-=(const Vec3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vec3& Vec3::operator*=(const double factor)
{
	x *= factor;
	y *= factor;
	z *= factor;
	return *this;
}

bool Vec3::operator==(const Vec3& other) const
{
	return (!cross_prod(*this, other) and length() == other.length());
}

bool Vec3::operator!=(const Vec3& other) const
{
	return !(*this == other);
}

bool Vec3::operator!() const
{
	return !(x and y and z);
}

bool Vec3::operator>(const Vec3& other) const
{
	return (length() > other.length());
}

bool Vec3::operator<(const Vec3& other) const
{
	return (length() < other.length());
}

bool Vec3::operator<=(const Vec3& other) const
{
	return (length() <= other.length());
}

bool Vec3::operator>=(const Vec3& other) const
{
	return (length() >= other.length());
}

void Vec3::set_x(const double _x)
{
	x = _x;
}

void Vec3::set_y(const double _y)
{
	y = _y;
}

void Vec3::set_z(const double _z)
{
	z = _z;
}

double Vec3::length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

void Vec3::normalize()
{
	double len = length();
	x /= len;
	y /= len;
	z /= len;
}

Vec3* Vec3::normalized() const
{
	double len = length();
	return new Vec3(x / len, y / len, z / len);
}

double Vec3::dot_prod(const Vec3& v0, const Vec3& v1)
{
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z;
}

Vec3 Vec3::cross_prod(const Vec3& v0, const Vec3& v1)
{
	return Vec3(v0.y * v1.z - v0.z * v1.y, v0.z * v1.x - v0.x * v1.z, v0.x * v1.y - v0.y * v1.x);
}

std::istream& operator>>(std::istream& is, Vec3& me)
{
	is >> me.x >> me.y >> me.z;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Vec3& me)
{
	os << "x: " << me.x << " | y: " << me.y << " | z: " << me.z;
	return os;
}