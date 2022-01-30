#pragma once
#include <Windows.h>
#include <CommCtrl.h>
#include "resource.h"


//function declaration
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

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
