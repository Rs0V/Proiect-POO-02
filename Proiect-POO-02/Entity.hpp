#pragma once
#ifndef ENTITY
#define ENTITY

#include <string>

#include "Vec3.hpp"
#include "World.hpp"

interface Entity
{
protected:
	int64_t id;
	std::string name;

	s_ptr(World) world;

	Vec3 position;
	int speed;

	int hp;
	int damage;

public:
	virtual ~Entity() = 0;

	virtual Vec3 GetPos() = 0;
	virtual void Move(const double delta_time) = 0;
	virtual void Attack(Entity& other) const = 0;
	virtual void TakeDamage(const int _dmg) = 0;
	virtual bool Alive() const = 0;
};

inline Entity::~Entity() = default;

#endif // !ENTITY