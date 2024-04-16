#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>

#include <lua/lua.hpp>
#include <oxy/environment/environment.h>
#include <oxy/environment/oxyfunc/oxyfunc.h>

class t_engine
{
public:
    std::string compiler(const std::string& source);
    void runner(const std::string& bytecode);
    void setup();
public:
    t_engine() = default;
    t_engine(const t_engine&) = delete;
};

inline auto engine = std::make_unique<t_engine>();