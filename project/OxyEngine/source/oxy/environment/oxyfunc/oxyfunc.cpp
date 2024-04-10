#include <oxy/environment/oxyfunc/oxyfunc.h>

int load_module(lua_State* state) {
    return 0;
}

int read_memory(lua_State* state) {
    return 0;
}

int write_memory(lua_State* state) {
    return 0;
}

void t_oxy_environment::setup(lua_State* state)
{
    static const struct luaL_Reg myLib[] = {
        { "load_module", load_module },
        { "read_memory", read_memory },
        { "write_memory", write_memory },
        { NULL, NULL }
    };

    luaL_newlib(state, myLib);
}