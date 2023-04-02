#include "Player.hpp"
#include <conio.h>

Player::Player(const int64_t _id, const std::string _name, const Vec3 _pos, const Stats stats)
	:
	luck(stats.luck),
	inventory_size(stats.inv_size),
	inventory(new std::string[stats.inv_size])
{
	id = _id;
	name = _name;
	position = _pos;
	speed = stats.speed;
	hp = stats.hp;
	damage = stats.dmg;
}

Player::Player(const Player& other)
	:
	luck(other.luck),
	inventory_size(other.inventory_size),
	inventory(new std::string[other.inventory_size])
{
	id = other.id;
	name = other.name;
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;

	for (int i = 0; i < inventory_size; ++i)
		inventory[i] = other.inventory[i];
}

Player::Player(Player&& other) noexcept
	:
	luck(0),
	inventory_size(0),
	inventory(nullptr)
{
	id = other.id;
	name = std::move(other.name);
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	luck = other.luck;
	inventory_size = other.inventory_size;
	inventory = std::move(other.inventory);

	other.id = 0;
	other.name = "";
	other.position = 0;
	other.speed = 0;
	other.hp = 0;
	other.damage = 0;
	other.luck = 0;
	other.inventory_size = 0;
	other.inventory.reset();
}

Player::~Player()
{
	std::cout << ">>> " << name << "(#" << id << ") destructed\n\n";
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

Player& Player::operator=(Player&& other) noexcept
{
	id = other.id;
	name = std::move(other.name);
	position = other.position;
	speed = other.speed;
	hp = other.hp;
	damage = other.damage;
	luck = other.luck;
	inventory_size = other.inventory_size;
	inventory = std::move(other.inventory);

	other.id = 0;
	other.name = "";
	other.position = 0;
	other.speed = 0;
	other.hp = 0;
	other.damage = 0;
	other.luck = 0;
	other.inventory_size = 0;
	other.inventory.reset();

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
	os << ">>> " << me.name << "(#" << me.id << "): pos(" << me.position
		<< ") | speed(" << me.speed
		<< ") | HP(" << me.hp
		<< ") | DMG(" << me.damage
		<< ")\n\n";
	return os;
}

void Player::Move()
{
	switch (input)
	{
	case 'w':
		position += Vec3(0, 1, 0);
		std::cout << name << "(#" << id << ") moving forward...\n\n";
		break;
	case 's':
		position += Vec3(0, -1, 0);
		std::cout << name << "(#" << id << ") moving backward...\n\n";
		break;
	case 'a':
		position += Vec3(-1, 0, 0);
		std::cout << name << "(#" << id << ") moving left...\n\n";
		break;
	case 'd':
		position += Vec3(1, 0, 0);
		std::cout << name << "(#" << id << ") moving right...\n\n";
		break;
	}
}

void Player::Attack(Entity& other) const
{
	std::cout << name << "(#" << id << ") attacked!\n";
	other.TakeDamage(damage);
}

void Player::TakeDamage(const int _dmg)
{
	if (hp > 0 and !Dodge())
	{
		int dmgTaken = rint(_dmg - int(_dmg * 0.5), _dmg + int(_dmg * 0.5));
		hp -= dmgTaken;
		std::cout << name << "(#" << id << ") took " << dmgTaken << " damage!\n\n";
	}
}

bool Player::Alive() const
{
	return (hp > 0);
}

bool Player::Dodge() const
{
	// Min luck -> 1      Max luck -> 8
	int chance = lerp<int>(20, 50, double(luck - 1) * 0.125);
	int roulette = rint(0, 100);
	if (roulette <= chance)
	{
		std::cout << name << "(#" << id << ") dodged!\n\n";
		return true;
	}
	return false;
}

void Player::IncreaseStat(const std::string stat_name, const int incr)
{
	match(stat_name)
	{
		ioccur("speed")
			speed += incr,
			std::cout << ">>> " << name << "(#" << id << ")'s speed increased\n\n";
		occur("hp")
			hp += incr,
			std::cout << ">>> " << name << "(#" << id << ")'s hp increased\n\n";
		occur("damage")
			damage += incr,
			std::cout << ">>> " << name << "(#" << id << ")'s damage increased\n\n";
		occur("luck")
			luck += incr,
			std::cout << ">>> " << name << "(#" << id << ")'s luck increased\n\n";
		occur("inventory")
			inventory_size += incr,
			std::cout << ">>> " << name << "(#" << id << ")'s inventory increased\n\n";
		then
			std::cout << ">>> " << name << "(#" << id << ") doesn't possess the specified stat\n\n";
	}}
}

void Player::Input(const std::vector<s_ptr(Entity)>& others)
{
	input = _getch();
	switch (input)
	{
	case 'w':
	case 's':
	case 'a':
	case 'd':
		Move();
		break;
	case ' ':
		for(int i = 0; i < others.size(); ++i)
			Attack(*others[i]);
		break;
	}
}