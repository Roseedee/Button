#include "Window.h"
#include "Button.h"

//function declaration

void ButtonControl(HWND hwnd);

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
	
	/*LPDRAWITEMSTRUCT item = */
	switch (msg) {
	case WM_DRAWITEM: {

		break;
	}
	case WM_CREATE:
		ButtonControl(hwnd);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUTTON1:
			MessageBoxA(0, "Your Click button1", "Click", 0);
			break;
		case IDC_BUTTON2:
			MessageBoxA(0, "Your Click button2", "Click", 0);
			break;
		}
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void ButtonControl(HWND hwnd) {
	Button b;
	b.BtnInit(hwnd, BS_PUSHBUTTON , L"Click", 10, 10, 100, 30, IDC_BUTTON1);
	b.BtnInit(hwnd, BS_PUSHBUTTON, L"Click", 100, 10, 100, 30, IDC_BUTTON1);
	Button b2;
	b2.BtnInit(hwnd, BS_FLAT, L"BUTTON 2", 10, 50, 100, 30, IDC_BUTTON2);
	b2.BtnInit(hwnd, BS_FLAT, L"BUTTON 2", 100, 50, 100, 30, IDC_BUTTON2);
	
}