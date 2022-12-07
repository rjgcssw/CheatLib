#include <Windows.h>
#include <string>
#include <imgui.h>
namespace ImGui {
	void 默认主题();
	ImVec4 十六进制转颜色(std::string 十六进制);
	bool 输入锁状态();
	void 设置输入锁(void* 类指针, bool 锁状态);
}