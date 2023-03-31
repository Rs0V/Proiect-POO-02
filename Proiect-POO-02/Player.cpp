#include "Player.hpp"

Player::Player(int64_t _id, std::string _name, Vec3 _pos, double _speed, int _hp, int _dmg)
	:
	inventory(new std::string[10])
{
	id = _id;
	name = _name;
	position = _pos;
	speed = _speed;
	hp = _hp;
	damage = _dmg;
}

Player::Player(const Player& other)
	:
	inventory(new std::string[10])
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
}

Player::Player(const Player&& other) noexcept
	:
	inventory(new std::string[10])
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
}

Player::~Player()
{
	delete[] inventory;
	std::cout << ">>> " << name << "(#" << id << ") destructed" << '\n';
}

Player& Player::operator=(const Player& other)
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	return *this;
}

Player& Player::operator=(const Player&& other) noexcept
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	return *this;
}

bool Player::operator==(const Player& other) const
{
	return (id == other.id);
}

bool Player::operator!=(const Player& other) const
{
	return (id != other.id);
}

bool Player::operator!() const
{
	return (hp <= 0);
}

std::istream& operator>>(std::istream& is, Player& me)
{
	is >> me.name >> me.position >> me.speed >> me.hp >> me.damage;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Player& me)
{
	os << me.name << "(#" << me.id << "): pos(" << me.position
		<< ") | speed(" << me.speed
		<< ") | HP(" << me.hp
		<< ") | DMG(" << me.damage
		<< ")\n";
	return os;
}

void Player::Move()
{
	char input = _getch();
	switch (input)
	{
	case 'w':
		position += Vec3(0, 1, 0);
		std::cout << name << "(#" << id << ") moving forward..." << '\n';
		break;
	case 's':
		position += Vec3(0, -1, 0);
		std::cout << name << "(#" << id << ") moving backward..." << '\n';
		break;
	case 'a':
		position += Vec3(-1, 0, 0);
		std::cout << name << "(#" << id << ") moving left..." << '\n';
		break;
	case 'd':
		position += Vec3(1, 0, 0);
		std::cout << name << "(#" << id << ") moving right..." << '\n';
		break;
	}
}

void Player::Attack()
{
	char input = _getch();
	if (input == ' ')
		std::cout << name << "(#" << id << ") attacking!" << '\n';
}