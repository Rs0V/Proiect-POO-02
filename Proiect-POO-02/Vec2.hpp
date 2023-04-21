#pragma once
#ifndef VEC2
#define VEC2

#include <iostream>
#include "Macros.hpp"

class Vec2
{
protected:
	double x, y;

public:
	double readonly x_ = x;
	double readonly y_ = y;

	Vec2(const double nr = 0.0);
	Vec2(const double _x, const double _y);
	Vec2(const Vec2& other);
	Vec2(Vec2&& other) noexcept;
	virtual ~Vec2();

	Vec2& operator=(const Vec2& other);
	Vec2& operator=(Vec2&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Vec2& me);
	friend std::ostream& operator<<(std::ostream& os, const Vec2& me);

	Vec2 operator+(const Vec2& other) const;
	Vec2 operator-(const Vec2& other) const;
	Vec2 operator*(const double factor) const;

	Vec2& operator+=(const Vec2& other);
	Vec2& operator-=(const Vec2& other);
	Vec2& operator*=(const double factor);

	bool operator==(const Vec2& other) const;
	bool operator!=(const Vec2& other) const;
	bool operator!() const;

	bool operator>(const Vec2& other) const;
	bool operator<(const Vec2& other) const;
	bool operator<=(const Vec2& other) const;
	bool operator>=(const Vec2& other) const;

	operator bool() const;

	void set_x(const double _x);
	void set_y(const double _y);

	virtual double length() const;
	virtual void normalize();
	virtual Vec2* normalized() const;
	static double dot_prod(const Vec2& v0, const Vec2& v1);
};

#endif // !VEC2