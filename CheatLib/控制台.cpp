/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <控制台.h>
#include <stdio.h>
#include <iostream>
#include <printf.h>
namespace 控制台输出 {
	HWND 开启控制台(const char* 标题, bool 是否可以关闭) {
		HANDLE g_hOutput = 0;
		HWND hwnd = NULL;
		HMENU hmenu = NULL;
		AllocConsole();
		g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTitle(标题);
		SetConsoleTextAttribute((HANDLE)g_hOutput, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		while (NULL == hwnd) hwnd = ::FindWindow(NULL, (LPCTSTR)标题);
		hmenu = ::GetSystemMenu(hwnd, FALSE);
		if (!是否可以关闭){DeleteMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);}
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
		return hwnd;
	}
	void 关闭控制台() {
		fclose(stdout);
		fclose(stderr);
		FreeConsole();
	}
	void 控制台输出(输出类型 类型, std::string 文本, std::string 文件, int 行号) {
		HANDLE 控制台句柄 = GetStdHandle(STD_OUTPUT_HANDLE);
		switch (类型)
		{
		case 控制台输出::信息:
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 绿色 * 16);
			fmt::printf(" ");
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 黑色);
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
			fmt::printf("[");
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 绿色);
			fmt::printf("信息");
			break;
		case 控制台输出::调试:
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 蓝色 * 16);
			fmt::printf(" ");
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 黑色);
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
			fmt::printf("[");
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 蓝色);
			fmt::printf("调试");
			break;
		case 控制台输出::警告:
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 黄色 * 16);
			fmt::printf(" ");
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 黑色);
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
			fmt::printf("[");
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 黄色);
			fmt::printf("警告");
			break;
		case 控制台输出::错误:
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 红色 * 16);
			fmt::printf(" ");
			SetConsoleTextAttribute(控制台句柄, BACKGROUND_INTENSITY | 黑色);
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
			fmt::printf("[");
			SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 红色);
			fmt::printf("错误");
			break;
		}
		SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
		fmt::printf("]>[");
		SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 紫色);
		fmt::printf("%s:%i", 文件, 行号);
		SetConsoleTextAttribute(控制台句柄, FOREGROUND_INTENSITY | 白色);
		fmt::printf("] :%s",文本);
	}
}