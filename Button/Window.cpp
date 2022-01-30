#include "Window.h"

//function declaration
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

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