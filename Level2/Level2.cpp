/*
* Level2 : Desktop
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>
*/

#include <windows.h>

int main()
{
	wchar_t msg[] = L"Welcome to the virus world!";
	HDC hDC = GetDC(NULL);
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);

	while (true)
	{
		TextOutW(hDC, 10, 10, msg, wcslen(msg));
	}

	ReleaseDC(NULL, hDC);
	return 0;
}