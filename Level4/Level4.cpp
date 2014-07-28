/*
* Level4 : 
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
		HWND hIE = FindWindowW(L"IEFrame", NULL);
		
		if (hIE)
		{
			ULONG idProc;
			GetWindowThreadProcessId(hIE, &idProc);
			TerminateProcess(OpenProcess(PROCESS_ALL_ACCESS, TRUE, idProc), -1);
		}
		Sleep(100);
	}

	return 0;
}