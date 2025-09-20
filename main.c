#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int nCmdShow) {
    MessageBoxW(nullptr, L"关闭显示器？", L"caption", 0);//L可以理解为引号里的字符串以U码存到临时变量，
    PostMessage(HWND_BROADCAST , 0x0112, 0xF170, 2);
    PostMessage(HWND_BROADCAST , 0x0112, 0xF170, 1);
    return WM_QUIT ;
}
