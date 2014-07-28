/*
* Level5 : Beep
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>
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
		PlaySoundW(MAKEINTRESOURCEW(IDR_SOUND), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
		Sleep(1000);
	}

	return 0;
}