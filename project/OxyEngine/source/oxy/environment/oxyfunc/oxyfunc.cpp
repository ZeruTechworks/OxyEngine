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

int test(lua_State* state) {
    MessageBox(NULL, "Hello, this is OxyEngine!", "Check for OxyEngine", MB_ICONINFORMATION | MB_OK);
    return 0;
}

void t_oxy_environment::setup(lua_State* state)
{
    static const struct luaL_Reg myLib[] = {
        { NULL, NULL },
        { "load_module", load_module },
        { "read_memory", read_memory },
        { "write_memory", write_memory },
        { "test", test },
    };

    luaL_newlib(state, myLib);

    lua_pushcfunction(state, test);
    lua_setglobal(state, "test");
}