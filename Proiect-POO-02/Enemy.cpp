#include "Enemy.hpp"

Enemy::Enemy(int64_t _id, std::string _name, Vec3 _pos, double _speed, int _hp, int _dmg)
{
	id = _id;
	name = _name;
	position = _pos;
	speed = _speed;
	hp = _hp;
	damage = _dmg;
}

Enemy::Enemy(const Enemy& other)
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
}

Enemy::Enemy(const Enemy&& other) noexcept
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
}

Enemy::~Enemy()
{
	std::cout << ">>> " << name << "(#" << id << ") destructed" << '\n';
}

Enemy& Enemy::operator=(const Enemy& other)
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	return *this;
}

Enemy& Enemy::operator=(const Enemy&& other) noexcept
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	return *this;
}

bool Enemy::operator==(const Enemy& other) const
{
	return (id == other.id);
}

bool Enemy::operator!=(const Enemy& other) const
{
	return (id != other.id);
}

bool Enemy::operator!() const
{
	return (hp <= 0);
}

std::istream& operator>>(std::istream& is, Enemy& me)
{
	is >> me.name >> me.position >> me.speed >> me.hp >> me.damage;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Enemy& me)
{
	os << me.name << "(#" << me.id << "): pos(" << me.position
		<< ") | speed(" << me.speed
		<< ") | HP(" << me.hp
		<< ") | DMG(" << me.damage
		<< ")\n";
	return os;
}

void Enemy::Move()
{
	std::cout << name << "(#" << id << ") moving..." << '\n';
}

void Enemy::Attack()
{
	std::cout << name << "(#" << id << ") attacking!" << '\n';
}