#include "Memory.hpp"
#define BLOCKMAXSIZE 409600
namespace Memory
{
	WORD GetTzmArray(char* Tzm, WORD* TzmArray)
	{
		int len = 0;
		WORD TzmLength = strlen(Tzm) / 3 + 1;

		for (int i = 0; i < strlen(Tzm); )
		{
			char num[2];
			num[0] = Tzm[i++];
			num[1] = Tzm[i++];
			i++;
			if (num[0] != '?' && num[1] != '?')
			{
				int sum = 0;
				WORD a[2];
				for (int i = 0; i < 2; i++)
				{
					if (num[i] >= '0' && num[i] <= '9')
					{
						a[i] = num[i] - '0';
					}
					else if (num[i] >= 'a' && num[i] <= 'z')
					{
						a[i] = num[i] - 87;
					}
					else if (num[i] >= 'A' && num[i] <= 'Z')
					{
						a[i] = num[i] - 55;
					}

				}
				sum = a[0] * 16 + a[1];
				TzmArray[len++] = sum;
			}
			else
			{
				TzmArray[len++] = 256;
			}
		}
		return TzmLength;
	}
	void GetNext(short* next, WORD* Tzm, WORD TzmLength)
	{
		for (int i = 0; i < 260; i++)
			next[i] = -1;
		for (int i = 0; i < TzmLength; i++)
			next[Tzm[i]] = i;
	}

	void SearchMemory::SearchMemoryBlock(WORD* Tzm, WORD TzmLength, unsigned __int64 StartAddress, unsigned long size, std::vector<unsigned __int64>& ResultArray)
	{
		memcpy(MemoryData, (LPCVOID)StartAddress, size);
		for (int i = 0, j, k; i < size;)
		{
			j = i; k = 0;
			for (; k < TzmLength && j < size && (Tzm[k] == MemoryData[j] || Tzm[k] == 256); k++, j++);
			if (k == TzmLength)
			{
				ResultArray.push_back(StartAddress + i);
			}
			if ((i + TzmLength) >= size)
			{
				return;
			}
			int num = Next[MemoryData[i + TzmLength]];
			if (num == -1)
				i += (TzmLength - Next[256]);
			else
				i += (TzmLength - num);
		}
	}

	int SearchMemory::Search(std::string Tzm, unsigned __int64 StartAddress, unsigned __int64 EndAddress, int InitSize, std::vector<unsigned __int64>& ResultArray)
	{
		int i = 0;
		unsigned long BlockSize;
		MEMORY_BASIC_INFORMATION mbi;

		WORD TzmLength = strlen(Tzm.c_str()) / 3 + 1;
		WORD* TzmArray = new WORD[TzmLength];

		GetTzmArray((char*)Tzm.c_str(), TzmArray);
		GetNext(Next, TzmArray, TzmLength);

		ResultArray.clear();
		ResultArray.reserve(InitSize); //预分配内存提高执行效率

		while (VirtualQuery((LPCVOID)StartAddress, &mbi, sizeof(mbi)) != 0)
		{
			if (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_EXECUTE_READWRITE)
			{
				i = 0;
				BlockSize = mbi.RegionSize;
				while (BlockSize >= BLOCKMAXSIZE)
				{
					SearchMemoryBlock(TzmArray, TzmLength, StartAddress + (BLOCKMAXSIZE * i), BLOCKMAXSIZE, ResultArray);
					BlockSize -= BLOCKMAXSIZE; i++;
				}
				SearchMemoryBlock(TzmArray, TzmLength, StartAddress + (BLOCKMAXSIZE * i), BlockSize, ResultArray);

			}
			StartAddress += mbi.RegionSize;

			if (EndAddress != 0 && StartAddress > EndAddress)
			{
				return ResultArray.size();
			}
		}
		free(TzmArray);
		return ResultArray.size();
	}

}