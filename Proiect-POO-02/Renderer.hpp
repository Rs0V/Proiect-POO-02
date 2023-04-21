
#pragma once
#ifndef RENDERER
#define RENDERER

#include "Macros.hpp"
#include "World.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

_system Renderer
{
	static std::vector<std::vector<char>> buffer;
public:
	virtual ~Renderer() = 0;

	static void ClearBuffer();
	static void Render(const s_ptr(World)& world, const u_ptr(Player)& player, const std::vector<s_ptr(Entity)>& entities);
};

inline Renderer::~Renderer() = default;

#endif // !RENDERER
