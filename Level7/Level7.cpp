/*
* Level6 : Shutdown PC
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
		if (GetAsyncKeyState(VK_RETURN)) 
		{
			MessageBeep(0xFFFFFFFF);
		}
	}

	return 0;
}