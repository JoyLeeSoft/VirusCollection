/*
* Level10 : Pixel
* Author : Lee <jhlcooky@gmail.com>, Kim<vsp123@naver.com>, Seo <dev_kr@naver.com>
*/

#include <windows.h>
#include <time.h>

int main()
{
	HDC hDC = GetDC(NULL);
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HWND hWnd = GetConsoleWindow();
	if (hWnd)
		ShowWindow(hWnd, SW_HIDE);
	srand((unsigned)time(NULL));

	while (true)
	{
		SetPixel(hDC, rand() % width, rand() % height, RGB(rand() % 255, rand() % 255, rand() % 255));
		Sleep(10);
	}
	return 0;
}