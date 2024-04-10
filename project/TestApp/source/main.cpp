#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

FILE* file_stream;

int main()
{
	// shitty demo app

	AllocConsole();
	freopen_s(&file_stream, "CONIN$", "r", stdin);
	freopen_s(&file_stream, "CONOUT$", "w", stdout);
	freopen_s(&file_stream, "CONOUT$", "w", stderr);

	std::string key = "test_key_123";

	std::printf("enter key: ");
	std::string input;
	std::getline(std::cin, input);

	if (input == key)
	{
		std::printf("correct key!!!!!!!!!!\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 0;
	}
	else
	{
		std::printf("wrong key\n");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 1;
	}

	return 1;
}