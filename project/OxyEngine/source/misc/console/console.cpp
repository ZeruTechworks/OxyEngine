#include <misc/console/console.h>

void t_console::setup(std::string title)
{
	if (!this->console_finished) {
		LI_FN(AllocConsole)();

		freopen_s(&this->file_stream, XorStr("CONIN$"), "r", stdin);
		freopen_s(&this->file_stream, XorStr("CONOUT$"), "w", stdout);
		freopen_s(&this->file_stream, XorStr("CONOUT$"), "w", stderr);

		const auto window = LI_FN(GetConsoleWindow)();
		SMALL_RECT info = { 0, 0, 80, 20 };

		LI_FN(SetConsoleTitleA)(title.c_str());
		LI_FN(SetWindowPos)(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOSIZE | SWP_NOMOVE | SWP_SHOWWINDOW);
		LI_FN(SetConsoleWindowInfo)(LI_FN(GetStdHandle)(STD_OUTPUT_HANDLE), TRUE, &info);
		ShowScrollBar(window, SB_RIGHT, 0);

		this->console_finished = true;
	} else
		LI_FN(ShowWindow)(LI_FN(GetConsoleWindow)(), SW_SHOW);
}

void t_console::hide()
{
	if (!this->console_finished)
		return;

	LI_FN(ShowWindow)(LI_FN(GetConsoleWindow)(), SW_HIDE);
}

void t_console::show()
{
	if (!this->console_finished)
		return;

	LI_FN(ShowWindow)(LI_FN(GetConsoleWindow)(), SW_SHOW);
}