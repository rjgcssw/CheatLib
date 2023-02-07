#include <string>
namespace Text {
	std::string UTF16TOUTF8(const std::wstring& UTF16);
	std::string GBKTOUTF8(const std::string& str);
	std::string UTF8TOGBK(const std::string& src_str);
	std::wstring GBKTOUTF16(const std::string& GBK);
}