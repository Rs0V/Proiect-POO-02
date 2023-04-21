#pragma once
#ifndef VEC3
#define VEC3

#include "Vec2.hpp"

class Vec3 : public Vec2
{
protected:
	double z;

public:
	double readonly z_ = z;

	Vec3(const double nr = 0.0);
	Vec3(const double _x, const double _y, const double _z);
	Vec3(const Vec2& other, const double _z = 0.0);
	Vec3(const Vec3& other);
	Vec3(Vec3&& other) noexcept;
	~Vec3() override;

	Vec3& operator=(const Vec3& other);
	Vec3& operator=(Vec3&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Vec3& me);
	friend std::ostream& operator<<(std::ostream& os, const Vec3& me);

	Vec3 operator+(const Vec3& other) const;
	Vec3 operator-(const Vec3& other) const;
	Vec3 operator*(const double factor) const;

	Vec3& operator+=(const Vec3& other);
	Vec3& operator-=(const Vec3& other);
	Vec3& operator*=(const double factor);

	bool operator==(const Vec3& other) const;
	bool operator!=(const Vec3& other) const;
	bool operator!() const;

	bool operator>(const Vec3& other) const;
	bool operator<(const Vec3& other) const;
	bool operator<=(const Vec3& other) const;
	bool operator>=(const Vec3& other) const;

	operator bool() const;

	void set_x(const double _x);
	void set_y(const double _y);
	void set_z(const double _z);

	double length() const override;
	void normalize() override;
	Vec3* normalized() const override;
	static double dot_prod(const Vec3& v0, const Vec3& v1);
	static Vec3 cross_prod(const Vec3& v0, const Vec3& v1);
};

#endif // !VEC3