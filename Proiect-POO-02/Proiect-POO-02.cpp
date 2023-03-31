#include "Player.hpp"
#include "Enemy.hpp"

double f(const Vec2* v)
{
	return v->length();
}

void attack(Entity* entity)
{
	entity->Attack();
}

int main()
{
	Vec2 v(2,4);
	std::unique_ptr<Vec2> vv(v.normalized());
	Vec3 vvv(*vv, 3);
	double a = f(&vvv);
	double b = f(&v);
	std::cout << "a = " << a << '\n' << "b = " << b << "\n\n";

	Player Gigi(0);
	std::cout << Gigi << '\n';
	Enemy Dani(1);
	std::cout << Dani << '\n';

	attack(&Gigi);
	attack(&Dani);
	std::cout << '\n';

	return 0;
}