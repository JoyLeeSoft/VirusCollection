/*
* Level7 : Enter sound
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>, Seo <dev_kr@naver.com>
*/

#include <windows.h>
#include <mmsystem.h>

#include "resource.h"

#pragma comment(lib, "winmm")

int main()
{
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);

	while (true) 
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) 
		{
			PlaySoundW(MAKEINTRESOURCEW(IDR_SOUND), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
			Sleep(100);
		}
	}

	return 0;
}