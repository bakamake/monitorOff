#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int nCmdShow) {
    FreeConsole();
    MessageBoxW(nullptr, L"关闭显示器？", L"caption", MB_SETFOREGROUND );
    //v0.1 L可以理解为引号里的字符串以U码存到临时变量
    //v0.2 add uType 0 -> MB_SETFOREGROUND 在这个程序内部置顶MessageBoxWexp,失败
    PostMessage(HWND_BROADCAST , 0x0112, 0xF170, 2);
    //v0.1 好像window的monitor power系统软件机制，没有硬件那么即时，所以最好等4到10秒（视电脑性能和厂商硬件优化）等供电状态转换好再键鼠活动，不然会屏闪，需要长按电源键重置供电状态（弹出一个强制关机提示界面，取消他）
    PostMessage(HWND_BROADCAST , 0x0112, 0xF170, 1);
    return WM_QUIT ;
}
//v0.2 在运行->编辑配置中修改cmake应用程序下的本项目配置，取消勾选“激活工具窗口”，就不会跳出控制台
