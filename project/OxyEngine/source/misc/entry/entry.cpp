#include <misc/entry/entry.h>

int main_thread()
{
    HANDLE hPipe;
    char buffer[1024];
    DWORD dwRead;

    hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\oxyengine"),
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1,
        16384,
        16384,
        NMPWAIT_USE_DEFAULT_WAIT,
        NULL);
    while (hPipe != INVALID_HANDLE_VALUE)
    {
        if (ConnectNamedPipe(hPipe, NULL) != FALSE)
        {
            while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
            {
                buffer[dwRead] = '\0';
                std::string bytecode = engine->compiler(buffer);
                engine->runner(bytecode);
            }
        }

        DisconnectNamedPipe(hPipe);
    }

    return 0;
}

auto WINAPI DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    DisableThreadLibraryCalls(module);

    if (reason == DLL_PROCESS_ATTACH)
        std::thread(main_thread).detach();

    if (reason == DLL_PROCESS_DETACH)
        FreeLibrary(module);

    return TRUE;
}