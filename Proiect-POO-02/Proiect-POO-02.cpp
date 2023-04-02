#include "Player.hpp"
#include "Enemy.hpp"

/*
double f(const Vec2* v)
{
	return v->length();
}

void attack(Entity* entity)
{
	entity->Attack();
}
*/

int main()
{
	/*
	Vec2 v0(2,4);
	u_ptr(Vec2) v1(v0.normalized());
	Vec3 v2(*v1, 3);
	double a = f(&v2);
	double b = f(&v0);
	std::cout << "a = " << a << '\n' << "b = " << b << "\n\n";

	Player Gigi(0);
	std::cout << Gigi << '\n';
	Enemy Dani(1);
	std::cout << Dani << '\n';

	attack(&Gigi);
	attack(&Dani);
	std::cout << '\n';
	*/

	Player::Stats ps(1, 100, 10, 3, 8);

	u_ptr(Player) player = u_make(Player)(0, "Player", Vec3(), ps);
	u_ptr(Enemy) enemy = u_make(Enemy)(1, "Enemy", Vec3(), 1, 100, 8);

	std::vector<s_ptr(Enemy)> enemies;
	enemies.push_back(std::move(enemy));

	std::vector<s_ptr(Entity)> enemies_proxy;
	for (int i = 0; i < enemies.size(); ++i)
		enemies_proxy.push_back(std::static_pointer_cast<Entity>(enemies[i]));

	bool run = true;
	time_point t0 = time_now;
	while (run)
	{
		if (player != nullptr)
			if (player->Alive())
				player->Input(enemies_proxy);
			else
				player.reset();
		
		for (int i = 0; i < enemies.size(); ++i)
			if (enemies[i] != nullptr)
				if (enemies[i]->Alive())
					enemies[i]->Attack(*player);
				else
				{
					enemies[i].reset();
					enemies.erase(enemies.begin() + i);
					enemies_proxy[i].reset();
					enemies_proxy.erase(enemies_proxy.begin() + i);
				}

		if (player == nullptr or enemies_proxy.size() == 0)
			run = false;
	}
	time_point t1 = time_now;
	player.reset();
	enemy.reset();

	time_delta delta = t1 - t0;
	std::cout << "\n>>> Game ran for " << delta.count() << "s\n\n";

	return 0;
}