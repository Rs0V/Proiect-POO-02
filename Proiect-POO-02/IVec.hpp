#pragma once
#ifndef IVEC
#define IVEC

#include <iostream>
#include "Macros.hpp"

interface IVec
{
public:
	virtual ~IVec() = 0;

	virtual double length() const = 0;
	virtual void normalize() = 0;
	virtual IVec* normalized() const = 0;
};

IVec::~IVec()
{
}

#endif // !IVEC