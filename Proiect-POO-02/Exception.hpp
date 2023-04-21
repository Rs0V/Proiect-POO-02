
#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>
#include <sstream>

class my_exception : public std::exception
{
public:
	const char* what() const noexcept override {
		return "Just my exception";
	}
};

class out_of_bounds : public my_exception
{
	std::string info;

public:
	out_of_bounds(const std::string& _info)
		:
		info(_info)
	{
		std::ostringstream oss;
		oss << "Entity out of bounds!  :  " << info;
		info = oss.str();
	}
	const char* what() const noexcept override {
		return info.c_str();
	}
};

class negative_dimensions : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Dimensions of an object/world can't be negative!";
	}
};

class division_by_zero : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Encountered division by zero!";
	}
};

class normalize_by_zero : public division_by_zero
{
public:
	const char* what() const noexcept override {
		return "Encountered division by zero while normalizing vector!";
	}
};

class repeating_id_err : public my_exception
{
public:
	const char* what() const noexcept override {
		return "Entity ID is not unique!";
	}
};

#endif // !EXCEPTION
