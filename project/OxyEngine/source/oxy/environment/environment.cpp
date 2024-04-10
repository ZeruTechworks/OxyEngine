#include <oxy/environment/environment.h>

int getgenv(lua_State* state)
{
    lua_pushglobaltable(state);
    return 1;
}

void t_environment::setup(lua_State* state)
{
    lua_pushcfunction(state, getgenv);
    lua_setglobal(state, "getgenv");
}