#pragma once
#ifndef PLAYER
#define PLAYER

#include "Entity.hpp"
#include <conio.h>

class Player : public Entity
{
	std::string* inventory;
public:
	Player(int64_t _id, std::string _name = "Player", Vec3 _pos = Vec3(), double _speed = 1, int _hp = 100, int _dmg = 1);
	Player(const Player& other);
	Player(const Player&& other) noexcept;
	~Player() override;

	Player& operator=(const Player& other);
	Player& operator=(const Player&& other) noexcept;

	friend std::istream& operator>>(std::istream& is, Player& me);
	friend std::ostream& operator<<(std::ostream& os, const Player& me);

	bool operator==(const Player& other) const;
	bool operator!=(const Player& other) const;
	bool operator!() const;

	void Move() override;
	void Attack() override;
};

#endif // !PLAYER