#pragma once
#include "Header.h"

class Button
{
	HWND hButton;
	int style = WS_VISIBLE | WS_CHILD;
public:
	Button() : hButton(NULL) {}
	HWND BtnInit(HWND hDlg, int Style, const wchar_t *value, int x, int y, int w, int h, int ID);
private:
	HFONT SetNewFont(int fs, const wchar_t * font);


};

