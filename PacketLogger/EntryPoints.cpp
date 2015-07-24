#include "log_form.h"

#include <Windows.h>


DWORD WINAPI entry_point(LPVOID lpThreadParameter)
{
	log_form::instance().show();
	nana::exec() ;
	return 1;
}

// the entrypoint when running in debug mode
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	return entry_point(hInstance);
}

// the entrypoint when injected into maplestory
BOOLEAN WINAPI DllMain(IN HINSTANCE hDllHandle, IN DWORD nReason, IN LPVOID Reserved)
{
	if (nReason == DLL_PROCESS_ATTACH)
	{
		CreateThread(nullptr, 0, entry_point, hDllHandle, 0, nullptr);
	}
	return true;
}
