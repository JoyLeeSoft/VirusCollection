/*
 * Level1 : Message box
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
		MessageBoxW(NULL, L"Welcome to the VirusCollection!\nGood luck!", L"Level1", MB_OK);
	}
	return 0;
}