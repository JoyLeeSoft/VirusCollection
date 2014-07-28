/*
* Level3 : Strange mouse
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>
*/

#include <windows.h>

int main()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);

	while (true)
	{
		SetCursorPos(0, 0);
		Sleep(10000);
	}

	return 0;
}