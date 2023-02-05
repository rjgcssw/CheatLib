#pragma once
#include <Windows.h>
#include <string>
#include <vector>

namespace Memory
{
	class SearchMemory
	{
	public:
		int Search(std::string Tzm, unsigned __int64 StartAddress, unsigned __int64 EndAddress, int InitSize, std::vector<unsigned __int64>& ResultArray);
	private:
		BYTE* MemoryData;
		short Next[260];

		void SearchMemoryBlock(WORD* Tzm, WORD TzmLength, unsigned __int64 StartAddress, unsigned long size, std::vector<unsigned __int64>& ResultArray);
	};
}