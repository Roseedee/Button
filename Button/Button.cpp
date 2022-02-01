#include "Button.h"

HWND Button::BtnInit(HWND hDlg, int Style, const wchar_t *value, int x, int y, int w, int h, int ID)
{
    style = style | Style;
    hButton = CreateWindow(WC_BUTTON, value, style, x, y, w, h, hDlg, (HMENU)ID, 0, 0);
    SendMessage(hButton, WM_SETFONT, (WPARAM)Button::SetNewFont(16, L"Arial"), 0);
    return hButton;
}

HFONT Button::SetNewFont(int fs, const wchar_t* font)
{
    return CreateFont(fs, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, font);
}


