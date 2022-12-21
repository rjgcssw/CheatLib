#pragma once
#include <Windows.h>
#include <string>
#define LOGDEBUG(text,...) Console::OutConsole(Console::debug,text,__FILE__,__LINE__)
#define LOGINFO(text,...) Console::OutConsole(Console::info,text,__FILE__,__LINE__)
#define LOGWARNING(text,...) Console::OutConsole(Console::warning,text,__FILE__,__LINE__)
#define LOGERROR(text,...) Console::OutConsole(Console::error,text,__FILE__,__LINE__)
namespace Console {
	enum OutType : short int {
		info,
		debug,
		warning,
		error
	};
	enum Color : short int {
		black,
		blue,
		green,
		Lightgreen,
		red,
		purple,
		yellow,
		white,
		grey,
		Lightblue,
		thingreen,
		Lightlightgreen,
		Lightred,
		lavender,
		canaryyellow,
		Brightwhite
	};
	void OutConsole(OutType type, std::string text, std::string file, int line);
	HWND StartConsole(const char* title, bool close);
	void EndConsole();
}