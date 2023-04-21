
#pragma once
#ifndef WORLD
#define WORLD

#include "Vec3.hpp"
#include "Exception.hpp"

class World
{
	const Vec3 dim;

public:
	World(const unsigned int x, const unsigned int y, const unsigned int z)
		:
		dim(x, y, z)
	{}
	World(const Vec3& _dim)
		:
		dim(_dim)
	{
		if (dim.x_ < 0 or dim.y_ < 0 or dim.z_ < 0)
			throw negative_dimensions();
	}
	World(Vec3&& _dim)
		:
		dim(std::move(_dim))
	{
		if (dim.x_ < 0 or dim.y_ < 0 or dim.z_ < 0)
			throw negative_dimensions();
	}
	~World() = default;

	World& operator=(const World& other) = delete;
	World& operator=(World&& other) = delete;

	Vec3 GetDim() const {
		return dim;
	}
};

#endif // !WORLD
