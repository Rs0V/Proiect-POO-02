#pragma once
#ifndef ENEMY
#define ENEMY

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy(int64_t _id, std::string _name = "Enemy", Vec3 _pos = Vec3(), double _speed = 1, int _hp = 100, int _dmg = 1);
	Enemy(const Enemy& other);
	Enemy(const Enemy&& other) noexcept;
	~Enemy() override;

	Enemy& operator=(const Enemy& other);
	Enemy& operator=(const Enemy&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Enemy& me);
	friend std::ostream& operator<<(std::ostream& os, const Enemy& me);

	bool operator==(const Enemy& other) const;
	bool operator!=(const Enemy& other) const;
	bool operator!() const;

	void Move() override;
	void Attack() override;
};

#endif // !ENEMY