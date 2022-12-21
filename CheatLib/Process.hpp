#include <string>
#include <Windows.h>
namespace Process {
	std::string GetModuleFile(HMODULE Module);
	DWORD GetProcessIdByName(std::string Name);
	WCHAR GetProcessNameById(DWORD ProcessId);
	DWORD GetModuleLen(HMODULE hModule);
}