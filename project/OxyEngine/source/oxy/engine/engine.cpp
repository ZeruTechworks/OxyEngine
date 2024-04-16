#include <oxy/engine/engine.h>
#include "engine.h"

lua_State* engine_state = luaL_newstate();

static auto bytecode_writer(lua_State* state, const void* p, size_t size, void* ud)
{
	std::string* stream = static_cast<std::string*>(ud);
	stream->append(static_cast<const char*>(p), size);

	return 0;
}

std::string t_engine::compiler(const std::string& source)
{
	lua_State* state = luaL_newstate();
	luaL_openlibs(state);

	if (luaL_loadbuffer(state, source.c_str(), source.size(), "@oxy") == LUA_OK)
	{
		std::string bytecode;
		lua_dump(state, bytecode_writer, &bytecode);
		lua_close(state);

		return bytecode;
	}

	const char* error = lua_tostring(state, -1);
	lua_close(state);

	throw std::runtime_error(error);
}

void t_engine::runner(const std::string& bytecode)
{
	if (luaL_loadbuffer(engine_state, bytecode.c_str(), bytecode.size(), nullptr) == LUA_OK)
	{
		if (lua_pcall(engine_state, 0, LUA_MULTRET, 0) != LUA_OK)
		{
			const char* Error = lua_tostring(engine_state, -1);
			throw std::runtime_error(Error);
		}

		return;
	}

	const char* Error = lua_tostring(engine_state, -1);
	throw std::runtime_error(Error);
}

void t_engine::setup()
{
	luaL_openlibs(engine_state);
	environment->setup(engine_state);
	oxy_environment->setup(engine_state);
}