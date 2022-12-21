/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <Process.hpp>
#include <filesystem>
#include <TlHelp32.h>
#include <Text.hpp>
namespace Process {
	std::string GetModuleFile(HMODULE Module)
	{
		char pathOut[MAX_PATH] = {};
		GetModuleFileNameA(Module, pathOut, MAX_PATH);
		std::string File = std::filesystem::path(pathOut).parent_path().string();
		return File;
	}
	DWORD GetProcessIdByName(std::string Name)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return NULL;
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (strcmp(pe.szExeFile, Name.c_str()) == 0) {
				CloseHandle(hSnapshot);
				return pe.th32ProcessID;
			}
		}
		CloseHandle(hSnapshot);
		return 0;
	}
	WCHAR GetProcessNameById(DWORD ProcessId)
	{
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (INVALID_HANDLE_VALUE == hSnapshot) {
			return 0;
		}
		PROCESSENTRY32 pe = { sizeof(pe) };
		for (BOOL ret = Process32First(hSnapshot, &pe); ret; ret = Process32Next(hSnapshot, &pe)) {
			if (pe.th32ProcessID == ProcessId)
			{
				return pe.szExeFile[MAX_PATH];
			}
		}
		CloseHandle(hSnapshot);
		return 0;
	}
	DWORD GetModuleLen(HMODULE hModule)
	{
		PBYTE pImage = (PBYTE)hModule;
		PIMAGE_DOS_HEADER pImageDosHeader;
		PIMAGE_NT_HEADERS pImageNtHeader;
		pImageDosHeader = (PIMAGE_DOS_HEADER)pImage;
		if (pImageDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		{
			return 0;
		}
		pImageNtHeader = (PIMAGE_NT_HEADERS)&pImage[pImageDosHeader->e_lfanew];
		if (pImageNtHeader->Signature != IMAGE_NT_SIGNATURE)
		{
			return 0;
		}
		return pImageNtHeader->OptionalHeader.SizeOfImage;
	}
}