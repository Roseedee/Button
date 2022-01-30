#include "Window.h"

//function declaration
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool BaseWindow::Register(HINSTANCE hInst)
{
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"Windows";
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hInstance = hInst;
	return RegisterClass(&wc) ? true : false;
}

HWND BaseWindow::Create(const wchar_t* title, int Style, int width, int height)
{
	RECT rc = { 0 };
	rc.right = width;
	rc.bottom = height;
	BaseWindow::CenterWindow(rc);
	hwnd = CreateWindow(L"Windows", title, Style, rc.left, rc.top, rc.right, rc.bottom, 0, 0, 0, 0);
	return hwnd;
}

void BaseWindow::CenterWindow(RECT& rc)
{
	rc.left = (GetSystemMetrics(SM_CXSCREEN) / 2) - (rc.right / 2);
	rc.top = (GetSystemMetrics(SM_CYSCREEN) / 2) - (rc.bottom / 2);
}

BaseWindow Win;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {

	if (!Win.Register(hInstance))
		MessageBoxA(0, "Register class Error", "Regiter", 0);

	if(!Win.Create(L"Button", WS_OVERLAPPEDWINDOW, 1024, 768))
		MessageBoxA(0, "Create Window is fialed ", "Create Window", 0);

	ShowWindow(Win.hwnd, nCmdShow);

	MSG msg = { 0 };
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}