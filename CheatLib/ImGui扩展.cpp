/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <ImGui扩展.hpp>
#include <unordered_set>
static std::unordered_set<void*> 输入锁;
namespace ImGui {
	void 设置输入锁(void* 类指针, bool 锁状态)
	{
		if (锁状态)
			if(输入锁.count(类指针) == 0)
				输入锁.insert(类指针);
		else
			if (输入锁.count(类指针) > 0)
				输入锁.erase(类指针);
	}
	bool 输入锁状态()
	{
		return 输入锁.size() > 0;
	}
	ImVec4 十六进制转颜色(std::string 十六进制)
	{
		int r, g, b, a;
		sscanf_s(十六进制.c_str(), "%02x%02x%02x%02x", &r, &g, &b, &a);
		ImVec4 color{ (float(r) / 255), (float(g) / 255), (float(b) / 255), (float(a) / 255) };
		return color;
	}
	void 默认主题()
	{
		auto& styles = ImGui::GetStyle();

		// Colors
		auto colors = styles.Colors;
		colors[ImGuiCol_Border] = 十六进制转颜色("26383FFF");
		colors[ImGuiCol_BorderShadow] = 十六进制转颜色("33333300");
		colors[ImGuiCol_Button] = 十六进制转颜色("23303DFF");
		colors[ImGuiCol_ButtonActive] = 十六进制转颜色("474968FF");
		colors[ImGuiCol_ButtonHovered] = 十六进制转颜色("444C70FF");
		colors[ImGuiCol_CheckMark] = 十六进制转颜色("A5BCDBFF");
		colors[ImGuiCol_ChildBg] = 十六进制转颜色("1E262BFF");
		colors[ImGuiCol_DragDropTarget] = 十六进制转颜色("FFFF00E5");
		colors[ImGuiCol_FrameBg] = 十六进制转颜色("2D3F44FF");
		colors[ImGuiCol_FrameBgActive] = 十六进制转颜色("30383DFF");
		colors[ImGuiCol_FrameBgHovered] = 十六进制转颜色("26303DFF");
		colors[ImGuiCol_Header] = 十六进制转颜色("0000003D");
		colors[ImGuiCol_HeaderActive] = 十六进制转颜色("0070EAFF");
		colors[ImGuiCol_HeaderHovered] = 十六进制转颜色("1E2833CC");
		colors[ImGuiCol_MenuBarBg] = 十六进制转颜色("1E232DFF");
		colors[ImGuiCol_ModalWindowDimBg] = 十六进制转颜色("CCCCCC59");
		colors[ImGuiCol_NavHighlight] = 十六进制转颜色("4296F9FF");
		colors[ImGuiCol_NavWindowingDimBg] = 十六进制转颜色("CCCCCC33");
		colors[ImGuiCol_NavWindowingHighlight] = 十六进制转颜色("FFFFFFB2");
		colors[ImGuiCol_PlotHistogram] = 十六进制转颜色("E5B200FF");
		colors[ImGuiCol_PlotHistogramHovered] = 十六进制转颜色("FF9900FF");
		colors[ImGuiCol_PlotLines] = 十六进制转颜色("9B9B9BFF");
		colors[ImGuiCol_PlotLinesHovered] = 十六进制转颜色("FF6D59FF");
		colors[ImGuiCol_PopupBg] = 十六进制转颜色("14161CEF");
		colors[ImGuiCol_ResizeGrip] = 十六进制转颜色("A3C9F93F");
		colors[ImGuiCol_ResizeGripActive] = 十六进制转颜色("6D8CB2F2");
		colors[ImGuiCol_ResizeGripHovered] = 十六进制转颜色("A5BFDDAA");
		colors[ImGuiCol_ScrollbarBg] = 十六进制转颜色("1C1C1C63");
		colors[ImGuiCol_ScrollbarGrab] = 十六进制转颜色("875E5EFF");
		colors[ImGuiCol_ScrollbarGrabActive] = 十六进制转颜色("8E1919FF");
		colors[ImGuiCol_ScrollbarGrabHovered] = 十六进制转颜色("7C3A3AFF");
		colors[ImGuiCol_Separator] = 十六进制转颜色("333F49FF");
		colors[ImGuiCol_SeparatorActive] = 十六进制转颜色("6B91BFFF");
		colors[ImGuiCol_SeparatorHovered] = 十六进制转颜色("4F7299C6");
		colors[ImGuiCol_SliderGrab] = 十六进制转颜色("5977ADFF");
		colors[ImGuiCol_SliderGrabActive] = 十六进制转颜色("ADCCFFFF");
		colors[ImGuiCol_Tab] = 十六进制转颜色("1C262BFF");
		colors[ImGuiCol_TabActive] = 十六进制转颜色("333F49FF");
		colors[ImGuiCol_TabHovered] = 十六进制转颜色("969696CC");
		colors[ImGuiCol_TabUnfocused] = 十六进制转颜色("1C262BFF");
		colors[ImGuiCol_TabUnfocusedActive] = 十六进制转颜色("1C262BFF");
		colors[ImGuiCol_TableBorderLight] = 十六进制转颜色("3A3A3FFF");
		colors[ImGuiCol_TableBorderStrong] = 十六进制转颜色("4F4F59FF");
		colors[ImGuiCol_TableHeaderBg] = 十六进制转颜色("303033FF");
		colors[ImGuiCol_TableRowBg] = 十六进制转颜色("333F49FF");
		colors[ImGuiCol_TableRowBgAlt] = 十六进制转颜色("1C262BFF");
		colors[ImGuiCol_Text] = 十六进制转颜色("F2F4F9FF");
		colors[ImGuiCol_TextDisabled] = 十六进制转颜色("2B353DFF");
		colors[ImGuiCol_TextSelectedBg] = 十六进制转颜色("4296F959");
		colors[ImGuiCol_TitleBg] = 十六进制转颜色("232D38A5");
		colors[ImGuiCol_TitleBgActive] = 十六进制转颜色("212830FF");
		colors[ImGuiCol_TitleBgCollapsed] = 十六进制转颜色("26262682");
		colors[ImGuiCol_WindowBg] = 十六进制转颜色("1E2623FF");

		//Styles
		styles.Alpha = 1.0;
		styles.AntiAliasedFill = true;
		styles.AntiAliasedLines = true;
		styles.AntiAliasedLinesUseTex = true;
		styles.ButtonTextAlign = ImVec2(0.5, 0.5);
		styles.CellPadding = ImVec2(4.0, 2.0);
		styles.ChildBorderSize = 1.0;
		styles.ChildRounding = 5.0;
		styles.CircleTessellationMaxError = 0.30000001192092896;
		styles.ColorButtonPosition = 1;
		styles.ColumnsMinSpacing = 6.0;
		styles.CurveTessellationTol = 1.25;
		styles.DisabledAlpha = 0.6000000238418579;
		styles.DisplaySafeAreaPadding = ImVec2(3.0, 3.0);
		styles.DisplayWindowPadding = ImVec2(19.0, 19.0);
		styles.FrameBorderSize = 0.0;
		styles.FramePadding = ImVec2(4.0, 3.0);
		styles.FrameRounding = 4.0;
		styles.GrabMinSize = 10.0;
		styles.GrabRounding = 4.0;
		styles.IndentSpacing = 21.0;
		styles.ItemInnerSpacing = ImVec2(4.0, 4.0);
		styles.ItemSpacing = ImVec2(8.0, 4.0);
		styles.LogSliderDeadzone = 4.0;
		styles.MouseCursorScale = 1.0;
		styles.PopupBorderSize = 1.0;
		styles.PopupRounding = 0.0;
		styles.ScrollbarRounding = 9.0;
		styles.ScrollbarSize = 14.0;
		styles.SelectableTextAlign = ImVec2(0.0, 0.0);
		styles.TabBorderSize = 0.0;
		styles.TabMinWidthForCloseButton = 0.0;
		styles.TabRounding = 4.0;
		styles.TouchExtraPadding = ImVec2(0.0, 0.0);
		styles.WindowBorderSize = 1.0;
		styles.WindowMenuButtonPosition = 0;
		styles.WindowMinSize = ImVec2(32.0, 32.0);
		styles.WindowPadding = ImVec2(8.0, 8.0);
		styles.WindowRounding = 0.0;
		styles.WindowTitleAlign = ImVec2(0.0, 0.5);
	}
}