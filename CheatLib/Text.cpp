/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include "Text.hpp"
#include <codecvt>
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <codecvt>
namespace Text {
	std::string UTF16TOUTF8(const std::wstring& UTF16)
	{
		static std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
		return strCnv.to_bytes(UTF16);
	}
	std::string GBKTOUTF8(const std::string& str)
	{
		int nwLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
		wchar_t* pwBuf = new wchar_t[nwLen + 1];
		memset(pwBuf, 0, nwLen * 2 + 2);
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
		int nLen = WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
		char* pBuf = new char[nLen + 1];
		memset(pBuf, 0, nLen + 1);
		WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
		std::string ret = pBuf;
		delete[]pwBuf;
		delete[]pBuf;
		return ret;
	}
	std::string UTF8TOGBK(const std::string& src_str)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, src_str.c_str(), -1, NULL, 0);
		wchar_t* wszGBK = new wchar_t[len + 1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, src_str.c_str(), -1, wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
		char* szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
		std::string strTemp(szGBK);
		if (wszGBK) delete[] wszGBK;
		if (szGBK) delete[] szGBK;
		return strTemp;
	}
}