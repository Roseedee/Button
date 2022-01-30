#include "Window.h"

//function declaration

void Button(HWND hwnd);

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
	case WM_CREATE:
		Button(hwnd);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON1:
			MessageBoxA(0, "Your Click button1", "Click", 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void Button(HWND hwnd) {
	int defstyle = WS_VISIBLE | WS_CHILD;
	CreateWindow(WC_BUTTON, L"Button 1", defstyle | BS_DEFPUSHBUTTON, 10, 10, 100, 20, hwnd, (HMENU) IDC_BUTTON1, 0, 0);
}