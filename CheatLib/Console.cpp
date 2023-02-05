/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <Console.hpp>
#include <stdio.h>
#include <iostream>
#include <printf.h>
namespace Console {
	HWND StartConsole(const char* title, bool close) {
		HANDLE g_hOutput = 0;
		HWND hwnd = NULL;
		HMENU hmenu = NULL;
		AllocConsole();
		g_hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTitle(title);
		while (NULL == hwnd) hwnd = ::FindWindow(NULL, (LPCTSTR)title);
		hmenu = ::GetSystemMenu(hwnd, FALSE);
		if (!close){DeleteMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);}
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_THICKFRAME);
		SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);
		return hwnd;
	}
	void EndConsole() {
		fclose(stdout);
		fclose(stderr);
		FreeConsole();
	}
	void OutConsole(OutType type, std::string text, std::string file, int line) {
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		switch (type)
		{
		case OutType::info:
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | green * 16);
			fmt::print(" ");
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | black);
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
			fmt::print("[");
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | green);
			fmt::print("Info ");
			break;
		case OutType::debug:
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | blue * 16);
			fmt::print(" ");
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | black);
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
			fmt::print("[");
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | blue);
			fmt::print("Debug");
			break;
		case OutType::warning:
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | yellow * 16);
			fmt::print(" ");
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | black);
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
			fmt::print("[");
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | yellow);
			fmt::print("Warn ");
			break;
		case OutType::error:
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | red * 16);
			fmt::print(" ");
			SetConsoleTextAttribute(hwnd, BACKGROUND_INTENSITY | black);
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
			fmt::print("[");
			SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | red);
			fmt::print("Error");
			break;
		}
		SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
		fmt::print("]>[");
		SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | purple);
		fmt::printf("%s:%i", file.substr(file.find_last_of("\\")+1).c_str(), line);
		SetConsoleTextAttribute(hwnd, FOREGROUND_INTENSITY | white);
		fmt::printf("] :%s", text);
	}
}