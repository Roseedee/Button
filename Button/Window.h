#pragma once
#include <Windows.h>

class BaseWindow
{
public:
	HWND hwnd;
public:
	bool Register(HINSTANCE hInst);
	HWND Create(const wchar_t* title, int Style, int width, int height);
private:

	void CenterWindow(RECT& rc);

};

