/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <进程.hpp>
#include <filesystem>
#include <控制台.h>
#include <TlHelp32.h>
#include <文本.hpp>
namespace 进程 {
	std::string 取模块路径(HMODULE 模块句柄)
	{
		char pathOut[MAX_PATH] = {};
		GetModuleFileNameA(模块句柄, pathOut, MAX_PATH);
		std::string 目录 = std::filesystem::path(pathOut).parent_path().string();
		return 目录;
	}
	DWORD 进程名取ID(std::string 进程名称)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return NULL;
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (strcmp(pe.szExeFile, 进程名称.c_str()) == 0) {
				CloseHandle(hSnapshot);
				return pe.th32ProcessID;
			}
		}
		CloseHandle(hSnapshot);
		return 0;
	}
	std::string 进程ID取名(DWORD 进程ID)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return "";
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (pe.th32ProcessID == 进程ID)
			{
				return (const char*)(pe.szExeFile[MAX_PATH]);
			}
		}
		CloseHandle(hSnapshot);
		return "";
	}
	PVOID 模块取函数地址(LPCSTR 模块名称, LPCSTR 函数名称)
	{
		auto hModule = GetModuleHandleA(模块名称);
		if (hModule == NULL)
			return nullptr;
		return GetProcAddress(hModule, 函数名称);
	}
	HANDLE 打开进程(DWORD 进程ID)
	{
		return OpenProcess(PROCESS_ALL_ACCESS, false, 进程ID);
	}
	LPDWORD 创建线程(void(*p))
	{
		LPDWORD ID = nullptr;
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)p, 0, 0, ID);
		return ID;
	}
	bool 进程提权()
	{
		HANDLE hToken = nullptr;
		if (FALSE == OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken))
		{
			return false;
		}
		LUID luid;
		if (FALSE == LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid))
		{
			CloseHandle(hToken);
			return false;
		}
		TOKEN_PRIVILEGES Tok;
		Tok.PrivilegeCount = 1;
		Tok.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		Tok.Privileges[0].Luid = luid;
		if (FALSE == AdjustTokenPrivileges(hToken, FALSE, &Tok, sizeof(Tok), nullptr, nullptr))
		{
			CloseHandle(hToken);
			return false;
		}

		if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
		{
			CloseHandle(hToken);
			return false;
		}

		CloseHandle(hToken);
		return true;
	}
}