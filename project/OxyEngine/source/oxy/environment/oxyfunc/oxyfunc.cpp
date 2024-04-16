#include <oxy/environment/oxyfunc/oxyfunc.h>

int load_module(lua_State* state) {
    int nargs = lua_gettop(state);

    if (nargs != 1)
        return luaL_error(state, "arguments bad: expect 1 argument\n");

    if (!lua_isstring(state, 1))
        return luaL_error(state, "arguments bad: not a string\n");

    const char* module_name = lua_tostring(state, 1);

    printf("module: %s\n", module_name);
    EyeStep::open((LPWSTR)module_name);

    return 0;
}

int read_memory(lua_State* state)
{
    int nargs = lua_gettop(state);

    if (nargs != 1)
        return luaL_error(state, "arguments bad: expect 1 argument\n");

    if (!lua_isnumber(state, 1))
        return luaL_error(state, "arguments bad: not an integer\n");

    std::uintptr_t memory_address = (0x0 + lua_tointeger(state, 1));

    char result_string[512];
    printf("address: 0x%llu\n", memory_address);

    auto address_data = EyeStep::read(memory_address);
    strncpy(result_string, address_data.data, sizeof(result_string) - 1);
    result_string[sizeof(result_string) - 1] = '\0';

    lua_pushstring(state, result_string);
    return 1;
}

int read_string(lua_State* state)
{
    int nargs = lua_gettop(state);

    if (nargs != 1)
        return luaL_error(state, "arguments bad: expect 1 argument\n");

    if (!lua_isstring(state, 1))
        return luaL_error(state, "arguments bad: not an string\n");

    const char* search_string = lua_tostring(state, 1);
    auto scan_address = EyeStep::scanner::scan_xrefs(search_string, 0)[0];

    std::uintptr_t address = EyeStep::util::getCalls(scan_address)[0];
 
    lua_pushstring(state, std::to_string(address).c_str());
    return 1;
}

int write_memory(lua_State* state)
{
    return 0;
}

int test(lua_State* state)
{
    MessageBox(NULL, "Hello, this is OxyEngine!", "Check for OxyEngine", MB_ICONINFORMATION | MB_OK);
    return 0;
}

void t_oxy_environment::setup(lua_State* state)
{
    static const struct luaL_Reg oxy[] = {
        { "load_module", load_module },
        { "read_memory", read_memory },
        { "read_string", read_string },
        { "write_memory", write_memory },
        { "test", test },
        { NULL, NULL },
    };

    luaL_newlib(state, oxy);
    lua_setglobal(state, "oxy");
}