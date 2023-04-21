
#include "Player.hpp"
#include "Enemy.hpp"

#include "Exception.hpp"
#include "World.hpp"
#include "Renderer.hpp"

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

	try {
		s_ptr(World) myWorld = s_make(World)(Vec3(120, 30, 10000));

		Player::Stats ps(10, 100, 10, 3, 8);

		u_ptr(Player) player = u_make(Player)(0, myWorld, "Player", Vec3(90, 20, 10), ps);
		u_ptr(Enemy) enemy = u_make(Enemy)(1, myWorld, "Enemy", Vec3(40, 10, 10), 1, 100, 8);

		std::vector<s_ptr(Enemy)> enemies;
		enemies.push_back(std::move(enemy));

		std::vector<s_ptr(Entity)> enemies_proxy;
		for (int i = 0; i < enemies.size(); ++i)
			enemies_proxy.push_back(std::static_pointer_cast<Entity>(enemies[i]));

		bool run = true;
		time_point t0 = time_now;
		time_point d0;
		time_point d1 = time_now;
		d0 = d1;
		while (run)
		{
			d1 = time_now;
			time_delta delta = d1 - d0;
			d0 = d1;

			if (player != nullptr) {
				if (player->Alive()) {
					player->Input(delta.count(), enemies_proxy);
				}
				else
					player.reset();
			}
			for (int i = 0; i < enemies.size(); ++i)
				if (enemies[i] != nullptr)
					if (enemies[i]->Alive() and player != nullptr and player->Alive())
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

			if (player != nullptr) {
				if (player->Alive()) {
					Renderer::Render(myWorld, player, enemies_proxy);
				}
			}
		}
		time_point t1 = time_now;
		player.reset();
		enemy.reset();

		time_delta delta = t1 - t0;
		std::cout << "\n>>> Game ran for " << delta.count() << "s\n\n";
	}
	catch (const my_exception& e) {
		std::cout << "Game ran into a problem:\n\t" << e.what() << "\n";
	}
	return 0;
}