#pragma once
#ifndef ENEMY
#define ENEMY

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	Enemy(const int64_t _id,
		const s_ptr(World) _world,
		const std::string _name = "Enemy",
		const Vec3 _pos = Vec3(),
		const int _speed = 1,
		const int _hp = 100,
		const int _dmg = 1);
	Enemy(const Enemy& other);
	Enemy(Enemy&& other) noexcept;
	~Enemy() override;

	Enemy& operator=(const Enemy& other);
	Enemy& operator=(Enemy&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Enemy& me);
	friend std::ostream& operator<<(std::ostream& os, const Enemy& me);

	bool operator==(const Enemy& other) const;
	bool operator!=(const Enemy& other) const;
	bool operator!() const;

	operator bool() const;

	Vec3 GetPos() override;
	void Move(const double delta_time) override;
	void Attack(Entity& other) const override;
	void TakeDamage(const int _dmg) override;
	bool Alive() const override;
};

#endif // !ENEMY