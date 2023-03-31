#pragma once
#ifndef ENTITY
#define ENTITY

#include "Vec3.hpp"
#include <string>

interface Entity
{
protected:
	int64_t id;
	std::string name;

	Vec3 position;
	double speed;

	int hp;
	int damage;

public:
	virtual ~Entity() = 0;

	virtual void Move() = 0;
	virtual void Attack() = 0;
};

inline Entity::~Entity() = default;

#endif // !ENTITY