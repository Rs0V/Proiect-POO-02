#include "Enemy.hpp"

Enemy::Enemy(const int64_t _id,
	const std::string _name,
	const Vec3 _pos,
	const int _speed,
	const int _hp,
	const int _dmg)
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

Enemy::Enemy(Enemy&& other) noexcept
{
	id = other.id;
	name = std::move(other.name);
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;

	other.id = 0;
	other.name = "";
	other.position = 0;
	other.speed = 0;
	other.hp = 0;
	other.damage = 0;
}

Enemy::~Enemy()
{
	std::cout << ">>> " << name << "(#" << id << ") destructed\n\n";
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

Enemy& Enemy::operator=(Enemy&& other) noexcept
{
	id = other.id;
	name = std::move(other.name);
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;

	other.id = 0;
	other.name = "";
	other.position = 0;
	other.speed = 0;
	other.hp = 0;
	other.damage = 0;

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
	os << ">>> " << me.name << "(#" << me.id << "): pos(" << me.position
		<< ") | speed(" << me.speed
		<< ") | HP(" << me.hp
		<< ") | DMG(" << me.damage
		<< ")\n\n";
	return os;
}

void Enemy::Move()
{
	std::cout << name << "(#" << id << ") moving...\n\n";
}

void Enemy::Attack(Entity& other) const
{
	std::cout << name << "(#" << id << ") attacked!\n";
	other.TakeDamage(damage);
}

void Enemy::TakeDamage(const int _dmg)
{
	if (hp > 0)
	{
		int dmgTaken = rint(_dmg - int(_dmg * 0.5), _dmg + int(_dmg * 0.5));
		hp -= dmgTaken;
		std::cout << name << "(#" << id << ") took " << dmgTaken << " damage!\n\n";
	}
}

bool Enemy::Alive() const
{
	return (hp > 0);
}