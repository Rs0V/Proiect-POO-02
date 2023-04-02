#pragma once
#ifndef PLAYER
#define PLAYER

#include "Entity.hpp"
#include <vector>

class Player : public Entity
{
	int luck;
	int inventory_size;
	u_ptr(std::string[]) inventory;

	char input;
public:
	struct Stats
	{
		int speed;
		int hp;
		int dmg;
		int luck;
		int inv_size;

		Stats(const int _speed = 1,
			const int _hp = 100,
			const int _dmg = 1,
			const int _luck = 1,
			const int _inv_size = 8)
			:
			speed(_speed),
			hp(_hp),
			dmg(_dmg),
			luck(_luck),
			inv_size(_inv_size)
		{
		}
	};

	Player(const int64_t _id, const std::string _name = "Player", const Vec3 _pos = Vec3(), const Stats stats = Stats());
	Player(const Player& other);
	Player(Player&& other) noexcept;
	~Player() override;

	Player& operator=(const Player& other);
	Player& operator=(Player&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Player& me);
	friend std::ostream& operator<<(std::ostream& os, const Player& me);

	bool operator==(const Player& other) const;
	bool operator!=(const Player& other) const;
	bool operator!() const;

	void Move() override;
	void Attack(Entity& other) const override;
	void TakeDamage(const int _dmg) override;
	bool Alive() const override;

	bool Dodge() const;
	void IncreaseStat(const std::string stat_name, const int incr);

	void Input(const std::vector<s_ptr(Entity)>& others);
};

#endif // !PLAYER