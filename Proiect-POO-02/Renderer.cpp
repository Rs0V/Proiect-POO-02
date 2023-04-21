
#include "Renderer.hpp"
#include <iostream>

std::vector<std::vector<char>> Renderer::buffer;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	for (T elem : v) {
		os << elem;
	}
	return os;
}

void Renderer::ClearBuffer()
{
	for (int i = 0; i < buffer.size(); ++i) {
		for (int j = 0; j < buffer[i].size(); ++j)
			buffer[i][j] = ' ';
	}
}

void Renderer::Render(const s_ptr(World)& world, const u_ptr(Player)& player, const std::vector<s_ptr(Entity)>& entities)
{
	static bool once = [&]() {
		buffer.resize(world->GetDim().y_, std::vector<char>(world->GetDim().x_, ' '));
		return true;
	}();
	ClearBuffer();
	buffer[player->GetPos().y_][player->GetPos().x_] = '@';
	for (auto& entity : entities) {
		buffer[entity->GetPos().y_][entity->GetPos().x_] = '$';
	}
	std::cout << buffer;
}
