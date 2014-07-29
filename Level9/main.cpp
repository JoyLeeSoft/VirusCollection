#include <windows.h>

//#define TEST

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
void SetFullScreen(HWND hWnd);

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
	while (1)
	{
		HWND hWnd;
		MSG msg;
		WNDCLASS wc;

		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = NULL;
		wc.hCursor = NULL;
		wc.hIcon = NULL;
		wc.hInstance = hInst;
		wc.lpfnWndProc = WndProc;
		wc.lpszClassName = L"level9";
		wc.lpszMenuName = NULL;
		wc.style = CS_HREDRAW | CS_VREDRAW;
		RegisterClass(&wc);

		hWnd = CreateWindowEx(WS_EX_TOPMOST, L"level9", NULL, WS_POPUP,
			0, 0, 100, 100, NULL, (HMENU)NULL, hInst, NULL);
		ShowWindow(hWnd, SW_MAXIMIZE);

		while (GetMessage(&msg, 0, 0, NULL))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
#ifdef TEST
		return 0;
#endif
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP hBit;

	PAINTSTRUCT ps;
	HGDIOBJ hOld;
	HDC hMemDC;
	RECT rt;

	switch (iMsg)
	{
	case WM_CREATE:
		hBit = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(101));
		ShowCursor(FALSE);
		SetFullScreen(hWnd);
		return 0;
	case WM_PAINT:
		BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rt);
		hMemDC = CreateCompatibleDC(ps.hdc);
		hOld = SelectObject(hMemDC, hBit);
		StretchBlt(ps.hdc, 0, 0, rt.right, rt.bottom, hMemDC, 0, 0, 640, 480, SRCCOPY);
		SelectObject(hMemDC, hOld);
		DeleteDC(hMemDC);
		EndPaint(hWnd, &ps);
		return 0;
#ifdef TEST
	case WM_RBUTTONDOWN:
		DestroyWindow(hWnd);
		return 0;
#endif
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
	case WM_SYSCOMMAND:
		return 0;
	case WM_ACTIVATE:
		if (LOWORD(wParam) == WA_INACTIVE)
			SetActiveWindow(hWnd);
		return 0;
	case WM_DESTROY:
		DeleteObject(hBit);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, iMsg, wParam, lParam);
}

void SetFullScreen(HWND hWnd)
{
	LONG code;
	DEVMODE dm = { 0 };

	RECT rt;
	GetWindowRect(hWnd, &rt);

	dm.dmSize = sizeof(dm);
	dm.dmPelsWidth = rt.right - rt.left;
	dm.dmPelsHeight = rt.bottom - rt.top;
	dm.dmBitsPerPel = 32;
	dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	code = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);
}
