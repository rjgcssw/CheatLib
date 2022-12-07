/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <codecvt>
namespace 文本 {
	std::string UTF16转UTF8(const std::wstring& UTF16文本)
	{
		static std::wstring_convert<std::codecvt_utf8<wchar_t>> strCnv;
		return strCnv.to_bytes(UTF16文本);
	}
}