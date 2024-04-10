#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

#include <lua/lua.hpp>

class t_environment
{
public:
	void setup(lua_State* state);
public:
	t_environment() = default;
	t_environment(const t_environment&) = delete;
};

inline auto environment = std::make_unique<t_environment>();