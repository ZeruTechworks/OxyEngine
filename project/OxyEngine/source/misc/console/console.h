#pragma once

#include <Windows.h>
#include <iostream>

#include <xor/xorstr.h>
#include <lazy_import/lazy_import.hpp>

class t_console
{
private:
	bool console_finished = false;
	FILE* file_stream;
public:
	void setup(std::string console);
	void hide();
	void show();
public:
	t_console() = default;
	t_console(const t_console&) = delete;
};

inline auto console = std::make_unique<t_console>();