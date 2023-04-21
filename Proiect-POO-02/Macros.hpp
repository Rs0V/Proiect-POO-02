#pragma once
#ifndef MACROS
#define MACROS

#include <memory>
#include <random>
#include <chrono>

#define readonly const&
#define interface class
#define _system class

#define u_ptr(type) std::unique_ptr<type>
#define u_make(type) std::make_unique<type>

#define s_ptr(type) std::shared_ptr<type>
#define s_make(type) std::make_shared<type>

extern std::random_device rd;
extern std::mt19937 rng;

#define rint(min, max) std::uniform_int_distribution<int>(min, max)(rng)
#define rdouble(min, max) std::uniform_real_distribution<double>(min, max)(rng)

#define time_point std::chrono::time_point<std::chrono::system_clock>
#define time_now std::chrono::system_clock::now()
#define time_delta std::chrono::duration<double>

template <typename T>
T lerp(T min, T max, double amount)
{
	return T(min + (max - min) * amount);
}

#define elif else if

#define match(var_name) { auto __this = var_name;
#define ioccur(value) if (__this == value)
#define occur(value) elif (__this == value)
#define then else

#endif // !MACROS