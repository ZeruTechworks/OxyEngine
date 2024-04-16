#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

int main()
{
    std::printf("obscure shitty client for oxyengine v1\n\n");

    HANDLE pipe = CreateFile(TEXT("\\\\.\\pipe\\oxyengine"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (pipe == INVALID_HANDLE_VALUE)
    {
        std::printf("invalid pipe handle");
        std::this_thread::sleep_for(std::chrono::seconds(5));
        return 1;
    }

    while (true)
    {
        std::string source;
        std::printf("exec > ");
        std::getline(std::cin, source);

        DWORD bytesWritten = 0;
        if (!WriteFile(pipe, source.c_str(), source.size(), &bytesWritten, NULL))
        {
            std::printf("couldn't write to pipe...\n");
            CloseHandle(pipe);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            return 1;
        }
    }

    return 0;
}