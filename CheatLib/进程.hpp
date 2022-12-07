#include <string>
#include <Windows.h>
namespace 进程 {
	std::string 取模块路径(HMODULE 模块句柄);
	DWORD 进程名取ID(std::string 进程名称);
	std::string 进程ID取名(DWORD 进程ID);
	PVOID 模块取函数地址(LPCSTR 模块名称, LPCSTR 函数名称);
	HANDLE 打开进程(DWORD 进程ID);
	LPDWORD 创建线程(void(*p));
	bool 进程提权();
}