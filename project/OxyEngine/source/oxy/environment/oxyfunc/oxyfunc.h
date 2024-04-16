#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#include <lua/lua.hpp>

#include <eyestep/eyestep.h>
#include <eyestep/eyestep_utility.h>

class t_oxy_environment
{
public:
	void setup(lua_State* state);
public:
	t_oxy_environment() = default;
	t_oxy_environment(const t_oxy_environment&) = delete;
};

inline auto oxy_environment = std::make_unique<t_oxy_environment>();