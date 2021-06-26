// ----------------------------------------------------------------------------
// 
// SimulatorPluginLibrary.cpp
// 
// ----------------------------------------------------------------------------

#include <CoronaLua.h>
#include <Windows.h>

CORONA_EXPORT int luaload_plugin_demoMode( lua_State * );

BOOL CALLBACK EnumCallbackFnc(HWND hWnd, LPARAM currentProcID) {
	DWORD d = GetCurrentProcessId();
	DWORD procID;
	GetWindowThreadProcessId(hWnd, &procID);
	if (currentProcID == procID) {
		HMENU menu = GetMenu(hWnd);
		if (!menu) {
			return TRUE;
		}
		TCHAR title[1024];
		GetWindowText(hWnd, title, 1024);
		
		RECT wrect;
		GetWindowRect(hWnd, &wrect);
		RECT crect;
		GetClientRect(hWnd, &crect);
		POINT lefttop = { crect.left, crect.top }; // Practicaly both are 0
		ClientToScreen(hWnd, &lefttop);
		POINT rightbottom = { crect.right, crect.bottom };
		ClientToScreen(hWnd, &rightbottom);


		DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
		DWORD dwRemove = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_BORDER | WS_THICKFRAME;
		DWORD dwNewStyle = dwStyle & ~dwRemove;
		SetWindowLong(hWnd, GWL_STYLE, dwNewStyle);
		InvalidateRect(hWnd, NULL, TRUE);
		SetMenu(hWnd, NULL);
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
		SetLayeredWindowAttributes(hWnd, RGB(255, 255, 255), 255, LWA_COLORKEY);
		SetWindowPos(hWnd, NULL, 0, 0, crect.right-crect.left, crect.bottom-crect.top, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER);

	}
	return TRUE;
}

int init(lua_State* L) {
	EnumWindows(EnumCallbackFnc, GetCurrentProcessId());
	return 0;
}

CORONA_EXPORT
int luaopen_plugin_simDemoMode( lua_State *L )
{
	const luaL_Reg kVTable[] = {
		{ "init", init },
		{ NULL, NULL }
	};
	luaL_openlib(L, "plugin.demoMode", kVTable, 0);
	return 1;

}

// ----------------------------------------------------------------------------
