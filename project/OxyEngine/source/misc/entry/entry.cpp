#include <misc/entry/entry.h>

int main_thread()
{
    console->setup(XorStr("oxy scripting utility"));
    
    std::printf(XorStr("version: %s\n", version.c_str()));
    std::printf(XorStr("oxy scripting engine - debug tool\n"));

    while (true)
    {
        std::string source;
        std::getline(std::cin, source);

        std::string bytecode = engine->compiler(source);
        engine->runner(bytecode);

        std::this_thread::sleep_for(std::chrono::seconds(2));
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