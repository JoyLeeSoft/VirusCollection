/*
* Level6 : Shutdown PC
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>
*/

#include <windows.h>

int main()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);

	system("shutdown /s /t 0");

	return 0;
}