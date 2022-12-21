/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <ImGuiEX.hpp>
#include <unordered_set>
static std::unordered_set<void*> InPutLock;
const char* Theme = "";
struct Vector3 {
	float x;
	float y;
	float z;
};
namespace ImGui {
	ImU32 GetTeamColor(unsigned long Team, unsigned long A)
	{
		if (Team > 100)
		{
			for (int i = 0; Team < 100; i++) {
				Team -= 100;
			}
		}
		switch (Team)
		{
		case 0: return ImColor(0, 0, 0, A); break;
		case 1: return ImColor(133, 151, 21, A); break;
		case 2: return ImColor(173, 29, 210, A); break;
		case 3: return ImColor(148, 221, 196, A); break;
		case 4: return ImColor(118, 25, 57, A); break;
		case 5: return ImColor(49, 241, 173, A); break;
		case 6: return ImColor(181, 88, 240, A); break;
		case 7: return ImColor(147, 151, 50, A); break;
		case 8: return ImColor(25, 43, 209, A); break;
		case 9: return ImColor(192, 253, 22, A); break;
		case 10: return ImColor(142, 78, 72, A); break;
		case 11: return ImColor(155, 11, 245, A); break;
		case 12: return ImColor(59, 73, 168, A); break;
		case 13: return ImColor(99, 93, 222, A); break;
		case 14: return ImColor(63, 223, 109, A); break;
		case 15: return ImColor(104, 180, 135, A); break;
		case 16: return ImColor(154, 170, 205, A); break;
		case 17: return ImColor(220, 247, 193, A); break;
		case 18: return ImColor(68, 129, 41, A); break;
		case 19: return ImColor(8, 27, 64, A); break;
		case 20: return ImColor(98, 56, 48, A); break;
		case 21: return ImColor(78, 148, 212, A); break;
		case 22: return ImColor(17, 208, 222, A); break;
		case 23: return ImColor(196, 17, 157, A); break;
		case 24: return ImColor(75, 63, 156, A); break;
		case 25: return ImColor(70, 187, 239, A); break;
		case 26: return ImColor(199, 84, 33, A); break;
		case 27: return ImColor(80, 43, 208, A); break;
		case 28: return ImColor(239, 90, 244, A); break;
		case 29: return ImColor(9, 207, 95, A); break;
		case 30: return ImColor(53, 145, 148, A); break;
		case 31: return ImColor(54, 127, 137, A); break;
		case 32: return ImColor(112, 153, 177, A); break;
		case 33: return ImColor(30, 103, 204, A); break;
		case 34: return ImColor(17, 84, 3, A); break;
		case 35: return ImColor(127, 156, 3, A); break;
		case 36: return ImColor(74, 246, 155, A); break;
		case 37: return ImColor(30, 237, 103, A); break;
		case 38: return ImColor(119, 59, 194, A); break;
		case 39: return ImColor(164, 206, 80, A); break;
		case 40: return ImColor(116, 249, 198, A); break;
		case 41: return ImColor(187, 122, 88, A); break;
		case 42: return ImColor(162, 134, 69, A); break;
		case 43: return ImColor(179, 147, 232, A); break;
		case 44: return ImColor(190, 170, 208, A); break;
		case 45: return ImColor(15, 239, 102, A); break;
		case 46: return ImColor(232, 28, 0, A); break;
		case 47: return ImColor(197, 87, 112, A); break;
		case 48: return ImColor(102, 183, 88, A); break;
		case 49: return ImColor(38, 87, 232, A); break;
		case 50: return ImColor(251, 224, 129, A); break;
		case 51: return ImColor(159, 119, 199, A); break;
		case 52: return ImColor(251, 230, 193, A); break;
		case 53: return ImColor(205, 124, 235, A); break;
		case 54: return ImColor(94, 54, 203, A); break;
		case 55: return ImColor(166, 117, 86, A); break;
		case 56: return ImColor(118, 188, 40, A); break;
		case 57: return ImColor(156, 199, 163, A); break;
		case 58: return ImColor(36, 207, 244, A); break;
		case 59: return ImColor(7, 119, 152, A); break;
		case 60: return ImColor(150, 109, 163, A); break;
		case 61: return ImColor(65, 92, 23, A); break;
		case 62: return ImColor(240, 188, 1, A); break;
		case 63: return ImColor(39, 6, 231, A); break;
		case 64: return ImColor(123, 7, 186, A); break;
		case 65: return ImColor(14, 118, 7, A); break;
		case 66: return ImColor(41, 177, 0, A); break;
		case 67: return ImColor(72, 3, 136, A); break;
		case 68: return ImColor(134, 218, 42, A); break;
		case 69: return ImColor(197, 255, 33, A); break;
		case 70: return ImColor(124, 153, 103, A); break;
		case 71: return ImColor(125, 236, 249, A); break;
		case 72: return ImColor(111, 41, 216, A); break;
		case 73: return ImColor(162, 115, 100, A); break;
		case 74: return ImColor(151, 91, 172, A); break;
		case 75: return ImColor(207, 81, 122, A); break;
		case 76: return ImColor(167, 23, 19, A); break;
		case 77: return ImColor(169, 245, 211, A); break;
		case 78: return ImColor(34, 234, 37, A); break;
		case 79: return ImColor(176, 144, 217, A); break;
		case 80: return ImColor(239, 203, 14, A); break;
		case 81: return ImColor(49, 178, 94, A); break;
		case 82: return ImColor(1, 146, 33, A); break;
		case 83: return ImColor(159, 216, 130, A); break;
		case 84: return ImColor(56, 229, 156, A); break;
		case 85: return ImColor(177, 118, 13, A); break;
		case 86: return ImColor(200, 129, 70, A); break;
		case 87: return ImColor(28, 92, 197, A); break;
		case 88: return ImColor(190, 37, 45, A); break;
		case 89: return ImColor(201, 139, 110, A); break;
		case 90: return ImColor(127, 148, 44, A); break;
		case 91: return ImColor(206, 213, 105, A); break;
		case 92: return ImColor(95, 89, 8, A); break;
		case 93: return ImColor(148, 217, 64, A); break;
		case 94: return ImColor(151, 99, 58, A); break;
		case 95: return ImColor(242, 62, 114, A); break;
		case 96: return ImColor(64, 135, 202, A); break;
		case 97: return ImColor(43, 59, 95, A); break;
		case 98: return ImColor(43, 142, 193, A); break;
		case 99: return ImColor(6, 203, 46, A); break;
		case 100: return ImColor(162, 91, 30, A); break;
		default:return 0; break;
		}return 0;
	}
	void DrawOffscreenArrows(float x, float y, float z, const ImColor& color, float OutlineThickness, float TracerSize, float ArrowRadius)
	{
		ImRect screen_rect = { 0.0f, 0.0f, ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y };
		Vector3 entity_pos = { x,y,z };
		if (entity_pos.z > 0 && screen_rect.Contains({ entity_pos.x, entity_pos.y }))
			return;

		auto screen_center = screen_rect.GetCenter();
		auto angle = atan2(screen_center.y - entity_pos.y, screen_center.x - entity_pos.x);
		angle += entity_pos.z > 0 ? PI : 0.0f;

		ImVec2 arrow_center{
			screen_center.x + ArrowRadius * cosf(angle),
			screen_center.y + ArrowRadius * sinf(angle)
		};

		// Triangle
		std::array<ImVec2, 4> points{
			ImVec2(-22.0f, -8.6f),
			ImVec2(0.0f, 0.0f),
			ImVec2(-22.0f, 8.6f),
			ImVec2(-18.0f, 0.0f)
		};

		for (auto& point : points)
		{
			auto x = point.x * TracerSize;
			auto y = point.y * TracerSize;

			point.x = arrow_center.x + x * cosf(angle) - y * sinf(angle);
			point.y = arrow_center.y + x * sinf(angle) + y * cosf(angle);
		}

		auto draw = ImGui::GetBackgroundDrawList();

		float alpha = 1.0f;
		if (entity_pos.z > 0)
		{
			constexpr float nearThreshold = 200.0f * 200.0f;
			ImVec2 screen_outer_diff = {
				entity_pos.x < 0 ? abs(entity_pos.x) : (entity_pos.x > screen_rect.Max.x ? entity_pos.x - screen_rect.Max.x : 0.0f),
				entity_pos.y < 0 ? abs(entity_pos.y) : (entity_pos.y > screen_rect.Max.y ? entity_pos.y - screen_rect.Max.y : 0.0f),
			};
			float distance = static_cast<float>(std::pow(screen_outer_diff.x, 2) + std::pow(screen_outer_diff.y, 2));
			alpha = entity_pos.z < 0 ? 1.0f : (distance / nearThreshold);
		}
		auto arrowColor = color; // Copy
		arrowColor.Value.w = min(alpha, 1.0f);

		// Draw the arrow
		draw->AddTriangleFilled(points[0], points[1], points[3], arrowColor);
		draw->AddTriangleFilled(points[2], points[1], points[3], arrowColor);
		// draw->AddQuad(points[0], points[1], points[2], points[3], ImColor(0.0f, 0.0f, 0.0f, alpha), 0.6f);
		draw->AddQuad(points[0], points[1], points[2], points[3], ImColor(0.0f, 0.0f, 0.0f, alpha), OutlineThickness);
	}
	void SetInPutLock(void* This, bool value)
	{
		if (value)
			if(InPutLock.count(This) == 0)
				InPutLock.insert(This);
		else
			if (InPutLock.count(This) > 0)
				InPutLock.erase(This);
	}
	bool GetInPutLock()
	{
		return InPutLock.size() > 0;
	}
	ImVec4 HexToRGBA(std::string Hex)
	{
		int r, g, b, a;
		sscanf_s(Hex.c_str(), "%02x%02x%02x%02x", &r, &g, &b, &a);
		ImVec4 color{ (float(r) / 255), (float(g) / 255), (float(b) / 255), (float(a) / 255) };
		return color;
	}
	std::string RGBAToHex(ImVec4& color)
	{
		char hex[16];
		snprintf(hex, sizeof(hex), "%02x%02x%02x%02x",
			static_cast<int>(ceil(color.x * 255)),
			static_cast<int>(ceil(color.y * 255)),
			static_cast<int>(ceil(color.z * 255)),
			static_cast<int>(ceil(color.w * 255))
		);
		for (int i = 0; i < 16; i++)
			hex[i] = toupper(hex[i]);
		return hex;
	}
	bool operator&(OutlineSide lhs, OutlineSide rhs) {
		return
			static_cast<std::underlying_type<OutlineSide>::type>(lhs) &
			static_cast<std::underlying_type<OutlineSide>::type>(rhs);
	}
	void DrawTextWithOutline(ImDrawList* drawList, const ImVec2& screenPos, const char* text, const ImColor& textColor, float outlineThickness, OutlineSide sides, const ImColor& outlineColor)
	{
		DrawTextWithOutline(drawList, nullptr, 0.0f, screenPos, text, textColor, outlineThickness, sides, outlineColor);
	}
	void DrawTextWithOutline(ImDrawList* drawList, ImFont* font, float fontSize, const ImVec2& screenPos, const char* text, const ImColor& textColor, float outlineThickness, OutlineSide sides, const ImColor& outlineColor)
	{
		if (outlineThickness == 0.0f)
		{
			drawList->AddText(font, fontSize, screenPos, outlineColor, text);
		}
		else
		{
			if (sides & OutlineSide::Left)
				drawList->AddText(font, fontSize,
					{ screenPos.x - outlineThickness, screenPos.y }, outlineColor, text);

			if (sides & OutlineSide::Right)
				drawList->AddText(font, fontSize,
					{ screenPos.x + outlineThickness, screenPos.y }, outlineColor, text);

			if (sides & OutlineSide::Bottom)
				drawList->AddText(font, fontSize,
					{ screenPos.x, screenPos.y - outlineThickness }, outlineColor, text);

			if (sides & OutlineSide::Top)
				drawList->AddText(font, fontSize,
					{ screenPos.x, screenPos.y + outlineThickness }, outlineColor, text);
		}

		drawList->AddText(font, fontSize, screenPos, textColor, text);
	}
	float CalcWidth(const std::string_view& view)
	{
		ImGuiContext& g = *GImGui;
		return ImGui::CalcTextSize(view.data()).x + g.Style.FramePadding.x * 2.0f + 25.0f;
	}
	ImGuiStyle ShowThemeSetting()
	{
		ImGuiStyle Style;
		ImGui::Begin("Color");
		ImGui::BeginGroupPanel("OtherStyles", false, ImVec2(0, 0));
		if (ImGui::BeginCombo("Styles", Theme))
		{
			if (ImGui::Selectable("Default")) { DefaultTheme(); Theme = "Default"; }
			if (ImGui::Selectable("Anemo")) { AnemoTheme(); Theme = "Anemo"; }
			ImGui::EndCombo();
		}
		ImGui::EndGroupPanel();
		ImGui::BeginGroupPanel("DomeStyles", false, ImVec2(0, 0));
		ImGui::ShowStyleEditor(&Style);
		ImGui::EndGroupPanel();
		ImGui::End();
		return Style;
	}
	void AnemoTheme()
	{
		auto& styles = ImGui::GetStyle();

		// Colors
		auto colors = styles.Colors;
		colors[ImGuiCol_Border] = HexToRGBA("0C846ED5");
		colors[ImGuiCol_BorderShadow] = HexToRGBA("00000000");
		colors[ImGuiCol_Button] = HexToRGBA("0D9F9D9F");
		colors[ImGuiCol_ButtonActive] = HexToRGBA("076B3A94");
		colors[ImGuiCol_ButtonHovered] = HexToRGBA("0CAD4FCA");
		colors[ImGuiCol_CheckMark] = HexToRGBA("E6E6E680");
		colors[ImGuiCol_ChildBg] = HexToRGBA("00000045");
		colors[ImGuiCol_DragDropTarget] = HexToRGBA("333333FF");
		colors[ImGuiCol_FrameBg] = HexToRGBA("00000066");
		colors[ImGuiCol_FrameBgActive] = HexToRGBA("0D7F33B0");
		colors[ImGuiCol_FrameBgHovered] = HexToRGBA("09818B66");
		colors[ImGuiCol_Header] = HexToRGBA("0297959F");
		colors[ImGuiCol_HeaderActive] = HexToRGBA("07834ACC");
		colors[ImGuiCol_HeaderHovered] = HexToRGBA("00B8588A");
		colors[ImGuiCol_MenuBarBg] = HexToRGBA("069981CC");
		colors[ImGuiCol_ModalWindowDimBg] = HexToRGBA("3333335A");
		colors[ImGuiCol_NavHighlight] = HexToRGBA("7373E6CC");
		colors[ImGuiCol_NavWindowingDimBg] = HexToRGBA("CCCCCC33");
		colors[ImGuiCol_NavWindowingHighlight] = HexToRGBA("FFFFFFB3");
		colors[ImGuiCol_PlotHistogram] = HexToRGBA("E6B300FF");
		colors[ImGuiCol_PlotHistogramHovered] = HexToRGBA("FF9900FF");
		colors[ImGuiCol_PlotLines] = HexToRGBA("FFFFFFFF");
		colors[ImGuiCol_PlotLinesHovered] = HexToRGBA("E6B300FF");
		colors[ImGuiCol_PopupBg] = HexToRGBA("1D1D24EB");
		colors[ImGuiCol_ResizeGrip] = HexToRGBA("FFFFFF1A");
		colors[ImGuiCol_ResizeGripActive] = HexToRGBA("C7D2FFE6");
		colors[ImGuiCol_ResizeGripHovered] = HexToRGBA("C7D2FF99");
		colors[ImGuiCol_ScrollbarBg] = HexToRGBA("33404D99");
		colors[ImGuiCol_ScrollbarGrab] = HexToRGBA("0C864E65");
		colors[ImGuiCol_ScrollbarGrabActive] = HexToRGBA("02B3916F");
		colors[ImGuiCol_ScrollbarGrabHovered] = HexToRGBA("05925966");
		colors[ImGuiCol_Separator] = HexToRGBA("1CA09A7E");
		colors[ImGuiCol_SeparatorActive] = HexToRGBA("0099B1FF");
		colors[ImGuiCol_SeparatorHovered] = HexToRGBA("048897FF");
		colors[ImGuiCol_SliderGrab] = HexToRGBA("FFFFFF4D");
		colors[ImGuiCol_SliderGrabActive] = HexToRGBA("04882F99");
		colors[ImGuiCol_Tab] = HexToRGBA("18999F60");
		colors[ImGuiCol_TabActive] = HexToRGBA("038B4CD7");
		colors[ImGuiCol_TabHovered] = HexToRGBA("1E784BCC");
		colors[ImGuiCol_TabUnfocused] = HexToRGBA("FFFFFF00");
		colors[ImGuiCol_TabUnfocusedActive] = HexToRGBA("5A5AA700");
		colors[ImGuiCol_TableBorderLight] = HexToRGBA("FFFFFF00");
		colors[ImGuiCol_TableBorderStrong] = HexToRGBA("00014000");
		colors[ImGuiCol_TableHeaderBg] = HexToRGBA("2E8D89FF");
		colors[ImGuiCol_TableRowBg] = HexToRGBA("3E72769A");
		colors[ImGuiCol_TableRowBgAlt] = HexToRGBA("154D3E9B");
		colors[ImGuiCol_Text] = HexToRGBA("E6E6E6FF");
		colors[ImGuiCol_TextDisabled] = HexToRGBA("999999FF");
		colors[ImGuiCol_TextSelectedBg] = HexToRGBA("00A87E5A");
		colors[ImGuiCol_TitleBg] = HexToRGBA("00998D8A");
		colors[ImGuiCol_TitleBgActive] = HexToRGBA("008D556B");
		colors[ImGuiCol_TitleBgCollapsed] = HexToRGBA("27B6C14A");
		colors[ImGuiCol_WindowBg] = HexToRGBA("00000096");

		//Styles
		styles.Alpha = 1.0;
		styles.AntiAliasedFill = true;
		styles.AntiAliasedLines = true;
		styles.AntiAliasedLinesUseTex = true;
		styles.ButtonTextAlign = ImVec2(0.5, 0.5);
		styles.CellPadding = ImVec2(4.0, 2.0);
		styles.ChildBorderSize = 1.0;
		styles.ChildRounding = 0.0;
		styles.CircleTessellationMaxError = 0.30000001192092896;
		styles.ColorButtonPosition = 1;
		styles.ColumnsMinSpacing = 6.0;
		styles.CurveTessellationTol = 1.25;
		styles.DisabledAlpha = 0.6000000238418579;
		styles.DisplaySafeAreaPadding = ImVec2(3.0, 3.0);
		styles.DisplayWindowPadding = ImVec2(19.0, 19.0);
		styles.FrameBorderSize = 0.0;
		styles.FramePadding = ImVec2(4.0, 3.0);
		styles.FrameRounding = 0.0;
		styles.GrabMinSize = 10.0;
		styles.GrabRounding = 0.0;
		styles.IndentSpacing = 21.0;
		styles.ItemInnerSpacing = ImVec2(4.0, 4.0);
		styles.ItemSpacing = ImVec2(8.0, 4.0);
		styles.LogSliderDeadzone = 4.0;
		styles.MouseCursorScale = 1.0;
		styles.PopupBorderSize = 0.0;
		styles.PopupRounding = 0.0;
		styles.ScrollbarRounding = 0.0;
		styles.ScrollbarSize = 14.0;
		styles.SelectableTextAlign = ImVec2(0.0, 0.0);
		styles.TabBorderSize = 0.0;
		styles.TabMinWidthForCloseButton = 0.0;
		styles.TabRounding = 0.0;
		styles.TouchExtraPadding = ImVec2(0.0, 0.0);
		styles.WindowBorderSize = 0.0;
		styles.WindowMenuButtonPosition = 0;
		styles.WindowMinSize = ImVec2(32.0, 32.0);
		styles.WindowPadding = ImVec2(8.0, 8.0);
		styles.WindowRounding = 0.0;
		styles.WindowTitleAlign = ImVec2(0.0, 0.5);
	}
	void DefaultTheme()
	{
		auto& styles = ImGui::GetStyle();

		// Colors
		auto colors = styles.Colors;
		colors[ImGuiCol_Border] = HexToRGBA("26383FFF");
		colors[ImGuiCol_BorderShadow] = HexToRGBA("33333300");
		colors[ImGuiCol_Button] = HexToRGBA("23303DFF");
		colors[ImGuiCol_ButtonActive] = HexToRGBA("474968FF");
		colors[ImGuiCol_ButtonHovered] = HexToRGBA("444C70FF");
		colors[ImGuiCol_CheckMark] = HexToRGBA("A5BCDBFF");
		colors[ImGuiCol_ChildBg] = HexToRGBA("1E262BFF");
		colors[ImGuiCol_DragDropTarget] = HexToRGBA("FFFF00E5");
		colors[ImGuiCol_FrameBg] = HexToRGBA("2D3F44FF");
		colors[ImGuiCol_FrameBgActive] = HexToRGBA("30383DFF");
		colors[ImGuiCol_FrameBgHovered] = HexToRGBA("26303DFF");
		colors[ImGuiCol_Header] = HexToRGBA("0000003D");
		colors[ImGuiCol_HeaderActive] = HexToRGBA("0070EAFF");
		colors[ImGuiCol_HeaderHovered] = HexToRGBA("1E2833CC");
		colors[ImGuiCol_MenuBarBg] = HexToRGBA("1E232DFF");
		colors[ImGuiCol_ModalWindowDimBg] = HexToRGBA("CCCCCC59");
		colors[ImGuiCol_NavHighlight] = HexToRGBA("4296F9FF");
		colors[ImGuiCol_NavWindowingDimBg] = HexToRGBA("CCCCCC33");
		colors[ImGuiCol_NavWindowingHighlight] = HexToRGBA("FFFFFFB2");
		colors[ImGuiCol_PlotHistogram] = HexToRGBA("E5B200FF");
		colors[ImGuiCol_PlotHistogramHovered] = HexToRGBA("FF9900FF");
		colors[ImGuiCol_PlotLines] = HexToRGBA("9B9B9BFF");
		colors[ImGuiCol_PlotLinesHovered] = HexToRGBA("FF6D59FF");
		colors[ImGuiCol_PopupBg] = HexToRGBA("14161CEF");
		colors[ImGuiCol_ResizeGrip] = HexToRGBA("A3C9F93F");
		colors[ImGuiCol_ResizeGripActive] = HexToRGBA("6D8CB2F2");
		colors[ImGuiCol_ResizeGripHovered] = HexToRGBA("A5BFDDAA");
		colors[ImGuiCol_ScrollbarBg] = HexToRGBA("1C1C1C63");
		colors[ImGuiCol_ScrollbarGrab] = HexToRGBA("875E5EFF");
		colors[ImGuiCol_ScrollbarGrabActive] = HexToRGBA("8E1919FF");
		colors[ImGuiCol_ScrollbarGrabHovered] = HexToRGBA("7C3A3AFF");
		colors[ImGuiCol_Separator] = HexToRGBA("333F49FF");
		colors[ImGuiCol_SeparatorActive] = HexToRGBA("6B91BFFF");
		colors[ImGuiCol_SeparatorHovered] = HexToRGBA("4F7299C6");
		colors[ImGuiCol_SliderGrab] = HexToRGBA("5977ADFF");
		colors[ImGuiCol_SliderGrabActive] = HexToRGBA("ADCCFFFF");
		colors[ImGuiCol_Tab] = HexToRGBA("1C262BFF");
		colors[ImGuiCol_TabActive] = HexToRGBA("333F49FF");
		colors[ImGuiCol_TabHovered] = HexToRGBA("969696CC");
		colors[ImGuiCol_TabUnfocused] = HexToRGBA("1C262BFF");
		colors[ImGuiCol_TabUnfocusedActive] = HexToRGBA("1C262BFF");
		colors[ImGuiCol_TableBorderLight] = HexToRGBA("3A3A3FFF");
		colors[ImGuiCol_TableBorderStrong] = HexToRGBA("4F4F59FF");
		colors[ImGuiCol_TableHeaderBg] = HexToRGBA("303033FF");
		colors[ImGuiCol_TableRowBg] = HexToRGBA("333F49FF");
		colors[ImGuiCol_TableRowBgAlt] = HexToRGBA("1C262BFF");
		colors[ImGuiCol_Text] = HexToRGBA("F2F4F9FF");
		colors[ImGuiCol_TextDisabled] = HexToRGBA("2B353DFF");
		colors[ImGuiCol_TextSelectedBg] = HexToRGBA("4296F959");
		colors[ImGuiCol_TitleBg] = HexToRGBA("232D38A5");
		colors[ImGuiCol_TitleBgActive] = HexToRGBA("212830FF");
		colors[ImGuiCol_TitleBgCollapsed] = HexToRGBA("26262682");
		colors[ImGuiCol_WindowBg] = HexToRGBA("1E2623FF");

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
	ImGuiStyle OutCurrentStyles(nlohmann::json stylesData)
	{
		ImGuiStyle style;
		style.Colors[ImGuiCol_Border] = HexToRGBA(stylesData["ImGuiCol_Border"]);
		style.Colors[ImGuiCol_BorderShadow] = HexToRGBA(stylesData["ImGuiCol_BorderShadow"]);
		style.Colors[ImGuiCol_Button] = HexToRGBA(stylesData["ImGuiCol_Button"]);
		style.Colors[ImGuiCol_ButtonActive] = HexToRGBA(stylesData["ImGuiCol_ButtonActive"]);
		style.Colors[ImGuiCol_ButtonHovered] = HexToRGBA(stylesData["ImGuiCol_ButtonHovered"]);
		style.Colors[ImGuiCol_CheckMark] = HexToRGBA(stylesData["ImGuiCol_CheckMark"]);
		style.Colors[ImGuiCol_ChildBg] = HexToRGBA(stylesData["ImGuiCol_ChildBg"]);
		style.Colors[ImGuiCol_DragDropTarget] = HexToRGBA(stylesData["ImGuiCol_DragDropTarget"]);
		style.Colors[ImGuiCol_FrameBg] = HexToRGBA(stylesData["ImGuiCol_FrameBg"]);
		style.Colors[ImGuiCol_FrameBgActive] = HexToRGBA(stylesData["ImGuiCol_FrameBgActive"]);
		style.Colors[ImGuiCol_FrameBgHovered] = HexToRGBA(stylesData["ImGuiCol_FrameBgHovered"]);
		style.Colors[ImGuiCol_Header] = HexToRGBA(stylesData["ImGuiCol_Header"]);
		style.Colors[ImGuiCol_HeaderActive] = HexToRGBA(stylesData["ImGuiCol_HeaderActive"]);
		style.Colors[ImGuiCol_HeaderHovered] = HexToRGBA(stylesData["ImGuiCol_HeaderHovered"]);
		style.Colors[ImGuiCol_MenuBarBg] = HexToRGBA(stylesData["ImGuiCol_MenuBarBg"]);
		style.Colors[ImGuiCol_ModalWindowDimBg] = HexToRGBA(stylesData["ImGuiCol_ModalWindowDimBg"]);
		style.Colors[ImGuiCol_NavHighlight] = HexToRGBA(stylesData["ImGuiCol_NavHighlight"]);
		style.Colors[ImGuiCol_NavWindowingDimBg] = HexToRGBA(stylesData["ImGuiCol_NavWindowingDimBg"]);
		style.Colors[ImGuiCol_NavWindowingHighlight] = HexToRGBA(stylesData["ImGuiCol_NavWindowingHighlight"]);
		style.Colors[ImGuiCol_PlotHistogram] = HexToRGBA(stylesData["ImGuiCol_PlotHistogram"]);
		style.Colors[ImGuiCol_PlotHistogramHovered] = HexToRGBA(stylesData["ImGuiCol_PlotHistogramHovered"]);
		style.Colors[ImGuiCol_PlotLines] = HexToRGBA(stylesData["ImGuiCol_PlotLines"]);
		style.Colors[ImGuiCol_PlotLinesHovered] = HexToRGBA(stylesData["ImGuiCol_PlotLinesHovered"]);
		style.Colors[ImGuiCol_PopupBg] = HexToRGBA(stylesData["ImGuiCol_PopupBg"]);
		style.Colors[ImGuiCol_ResizeGrip] = HexToRGBA(stylesData["ImGuiCol_ResizeGrip"]);
		style.Colors[ImGuiCol_ResizeGripActive] = HexToRGBA(stylesData["ImGuiCol_ResizeGripActive"]);
		style.Colors[ImGuiCol_ResizeGripHovered] = HexToRGBA(stylesData["ImGuiCol_ResizeGripHovered"]);
		style.Colors[ImGuiCol_ScrollbarBg] = HexToRGBA(stylesData["ImGuiCol_ScrollbarBg"]);
		style.Colors[ImGuiCol_ScrollbarGrab] = HexToRGBA(stylesData["ImGuiCol_ScrollbarGrab"]);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = HexToRGBA(stylesData["ImGuiCol_ScrollbarGrabActive"]);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = HexToRGBA(stylesData["ImGuiCol_ScrollbarGrabHovered"]);
		style.Colors[ImGuiCol_Separator] = HexToRGBA(stylesData["ImGuiCol_Separator"]);
		style.Colors[ImGuiCol_SeparatorActive] = HexToRGBA(stylesData["ImGuiCol_SeparatorActive"]);
		style.Colors[ImGuiCol_SeparatorHovered] = HexToRGBA(stylesData["ImGuiCol_SeparatorHovered"]);
		style.Colors[ImGuiCol_SliderGrab] = HexToRGBA(stylesData["ImGuiCol_SliderGrab"]);
		style.Colors[ImGuiCol_SliderGrabActive] = HexToRGBA(stylesData["ImGuiCol_SliderGrabActive"]);
		style.Colors[ImGuiCol_Tab] = HexToRGBA(stylesData["ImGuiCol_Tab"]);
		style.Colors[ImGuiCol_TabActive] = HexToRGBA(stylesData["ImGuiCol_TabActive"]);
		style.Colors[ImGuiCol_TabHovered] = HexToRGBA(stylesData["ImGuiCol_TabHovered"]);
		style.Colors[ImGuiCol_TabUnfocused] = HexToRGBA(stylesData["ImGuiCol_TabUnfocused"]);
		style.Colors[ImGuiCol_TabUnfocusedActive] = HexToRGBA(stylesData["ImGuiCol_TabUnfocusedActive"]);
		style.Colors[ImGuiCol_TableBorderLight] = HexToRGBA(stylesData["ImGuiCol_TableBorderLight"]);
		style.Colors[ImGuiCol_TableBorderStrong] = HexToRGBA(stylesData["ImGuiCol_TableBorderStrong"]);
		style.Colors[ImGuiCol_TableHeaderBg] = HexToRGBA(stylesData["ImGuiCol_TableHeaderBg"]);
		style.Colors[ImGuiCol_TableRowBg] = HexToRGBA(stylesData["ImGuiCol_TableRowBg"]);
		style.Colors[ImGuiCol_TableRowBgAlt] = HexToRGBA(stylesData["ImGuiCol_TableRowBgAlt"]);
		style.Colors[ImGuiCol_Text] = HexToRGBA(stylesData["ImGuiCol_Text"]);
		style.Colors[ImGuiCol_TextDisabled] = HexToRGBA(stylesData["ImGuiCol_TextDisabled"]);
		style.Colors[ImGuiCol_TextSelectedBg] = HexToRGBA(stylesData["ImGuiCol_TextSelectedBg"]);
		style.Colors[ImGuiCol_TitleBg] = HexToRGBA(stylesData["ImGuiCol_TitleBg"]);
		style.Colors[ImGuiCol_TitleBgActive] = HexToRGBA(stylesData["ImGuiCol_TitleBgActive"]);
		style.Colors[ImGuiCol_TitleBgCollapsed] = HexToRGBA(stylesData["ImGuiCol_TitleBgCollapsed"]);
		style.Colors[ImGuiCol_WindowBg] = HexToRGBA(stylesData["ImGuiCol_WindowBg"]);

		style.Alpha = stylesData["Alpha"];
		style.DisabledAlpha = stylesData["DisabledAlpha"];
		style.WindowPadding.x = stylesData["WindowPaddingx"];
		style.WindowPadding.y = stylesData["WindowPaddingy"];
		style.WindowRounding = stylesData["WindowRounding"];
		style.WindowBorderSize = stylesData["WindowBorderSize"];
		style.WindowMinSize.x = stylesData["WindowMinSizex"];
		style.WindowMinSize.y = stylesData["WindowMinSizey"];
		style.WindowTitleAlign.x = stylesData["WindowTitleAlignx"];
		style.WindowTitleAlign.y = stylesData["WindowTitleAligny"];
		style.WindowMenuButtonPosition = stylesData["WindowMenuButtonPosition"];
		style.ChildRounding = stylesData["ChildRounding"];
		style.ChildBorderSize = stylesData["ChildBorderSize"];
		style.PopupRounding = stylesData["PopupRounding"];
		style.PopupBorderSize = stylesData["PopupBorderSize"];
		style.FramePadding.x = stylesData["FramePaddingx"];
		style.FramePadding.y = stylesData["FramePaddingy"];
		style.FrameRounding = stylesData["FrameRounding"];
		style.FrameBorderSize = stylesData["FrameBorderSize"];
		style.ItemSpacing.x = stylesData["ItemSpacingx"];
		style.ItemSpacing.y = stylesData["ItemSpacingy"];
		style.ItemInnerSpacing.x = stylesData["ItemInnerSpacingx"];
		style.ItemInnerSpacing.y = stylesData["ItemInnerSpacingy"];
		style.CellPadding.x = stylesData["CellPaddingx"];
		style.CellPadding.y = stylesData["CellPaddingy"];
		style.TouchExtraPadding.x = stylesData["TouchExtraPaddingx"];
		style.TouchExtraPadding.y = stylesData["TouchExtraPaddingy"];
		style.IndentSpacing = stylesData["IndentSpacing"];
		style.ColumnsMinSpacing = stylesData["ColumnsMinSpacing"];
		style.ScrollbarSize = stylesData["ScrollbarSize"];
		style.ScrollbarRounding = stylesData["ScrollbarRounding"];
		style.GrabMinSize = stylesData["GrabMinSize"];
		style.GrabRounding = stylesData["GrabRounding"];
		style.LogSliderDeadzone = stylesData["LogSliderDeadzone"];
		style.TabRounding = stylesData["TabRounding"];
		style.TabBorderSize = stylesData["TabBorderSize"];
		style.TabMinWidthForCloseButton = stylesData["TabMinWidthForCloseButton"];
		style.ColorButtonPosition = stylesData["ColorButtonPosition"];
		style.ButtonTextAlign.x = stylesData["ButtonTextAlignx"];
		style.ButtonTextAlign.y = stylesData["ButtonTextAligny"];
		style.SelectableTextAlign.x = stylesData["SelectableTextAlignx"];
		style.SelectableTextAlign.y = stylesData["SelectableTextAligny"];
		style.DisplayWindowPadding.x = stylesData["DisplayWindowPaddingx"];
		style.DisplayWindowPadding.y = stylesData["DisplayWindowPaddingy"];
		style.DisplaySafeAreaPadding.x = stylesData["DisplaySafeAreaPaddingx"];
		style.DisplaySafeAreaPadding.y = stylesData["DisplaySafeAreaPaddingy"];
		style.MouseCursorScale = stylesData["MouseCursorScale"];
		style.AntiAliasedLines = stylesData["AntiAliasedLines"];
		style.AntiAliasedLinesUseTex = stylesData["AntiAliasedLinesUseTex"];
		style.AntiAliasedFill = stylesData["AntiAliasedFill"];
		style.CurveTessellationTol = stylesData["CurveTessellationTol"];
		style.CircleTessellationMaxError = stylesData["CircleTessellationMaxError"];
		return style;
	}
	nlohmann::json GetCurrentStyles(ImGuiStyle style)
	{
		nlohmann::json stylesData;
		stylesData["ImGuiCol_Border"] = RGBAToHex(style.Colors[ImGuiCol_Border]);
		stylesData["ImGuiCol_BorderShadow"] = RGBAToHex(style.Colors[ImGuiCol_BorderShadow]);
		stylesData["ImGuiCol_Button"] = RGBAToHex(style.Colors[ImGuiCol_Button]);
		stylesData["ImGuiCol_ButtonActive"] = RGBAToHex(style.Colors[ImGuiCol_ButtonActive]);
		stylesData["ImGuiCol_ButtonHovered"] = RGBAToHex(style.Colors[ImGuiCol_ButtonHovered]);
		stylesData["ImGuiCol_CheckMark"] = RGBAToHex(style.Colors[ImGuiCol_CheckMark]);
		stylesData["ImGuiCol_ChildBg"] = RGBAToHex(style.Colors[ImGuiCol_ChildBg]);
		stylesData["ImGuiCol_DragDropTarget"] = RGBAToHex(style.Colors[ImGuiCol_DragDropTarget]);
		stylesData["ImGuiCol_FrameBg"] = RGBAToHex(style.Colors[ImGuiCol_FrameBg]);
		stylesData["ImGuiCol_FrameBgActive"] = RGBAToHex(style.Colors[ImGuiCol_FrameBgActive]);
		stylesData["ImGuiCol_FrameBgHovered"] = RGBAToHex(style.Colors[ImGuiCol_FrameBgHovered]);
		stylesData["ImGuiCol_Header"] = RGBAToHex(style.Colors[ImGuiCol_Header]);
		stylesData["ImGuiCol_HeaderActive"] = RGBAToHex(style.Colors[ImGuiCol_HeaderActive]);
		stylesData["ImGuiCol_HeaderHovered"] = RGBAToHex(style.Colors[ImGuiCol_HeaderHovered]);
		stylesData["ImGuiCol_MenuBarBg"] = RGBAToHex(style.Colors[ImGuiCol_MenuBarBg]);
		stylesData["ImGuiCol_ModalWindowDimBg"] = RGBAToHex(style.Colors[ImGuiCol_ModalWindowDimBg]);
		stylesData["ImGuiCol_NavHighlight"] = RGBAToHex(style.Colors[ImGuiCol_NavHighlight]);
		stylesData["ImGuiCol_NavWindowingDimBg"] = RGBAToHex(style.Colors[ImGuiCol_NavWindowingDimBg]);
		stylesData["ImGuiCol_NavWindowingHighlight"] = RGBAToHex(style.Colors[ImGuiCol_NavWindowingHighlight]);
		stylesData["ImGuiCol_PlotHistogram"] = RGBAToHex(style.Colors[ImGuiCol_PlotHistogram]);
		stylesData["ImGuiCol_PlotHistogramHovered"] = RGBAToHex(style.Colors[ImGuiCol_PlotHistogramHovered]);
		stylesData["ImGuiCol_PlotLines"] = RGBAToHex(style.Colors[ImGuiCol_PlotLines]);
		stylesData["ImGuiCol_PlotLinesHovered"] = RGBAToHex(style.Colors[ImGuiCol_PlotLinesHovered]);
		stylesData["ImGuiCol_PopupBg"] = RGBAToHex(style.Colors[ImGuiCol_PopupBg]);
		stylesData["ImGuiCol_ResizeGrip"] = RGBAToHex(style.Colors[ImGuiCol_ResizeGrip]);
		stylesData["ImGuiCol_ResizeGripActive"] = RGBAToHex(style.Colors[ImGuiCol_ResizeGripActive]);
		stylesData["ImGuiCol_ResizeGripHovered"] = RGBAToHex(style.Colors[ImGuiCol_ResizeGripHovered]);
		stylesData["ImGuiCol_ScrollbarBg"] = RGBAToHex(style.Colors[ImGuiCol_ScrollbarBg]);
		stylesData["ImGuiCol_ScrollbarGrab"] = RGBAToHex(style.Colors[ImGuiCol_ScrollbarGrab]);
		stylesData["ImGuiCol_ScrollbarGrabActive"] = RGBAToHex(style.Colors[ImGuiCol_ScrollbarGrabActive]);
		stylesData["ImGuiCol_ScrollbarGrabHovered"] = RGBAToHex(style.Colors[ImGuiCol_ScrollbarGrabHovered]);
		stylesData["ImGuiCol_Separator"] = RGBAToHex(style.Colors[ImGuiCol_Separator]);
		stylesData["ImGuiCol_SeparatorActive"] = RGBAToHex(style.Colors[ImGuiCol_SeparatorActive]);
		stylesData["ImGuiCol_SeparatorHovered"] = RGBAToHex(style.Colors[ImGuiCol_SeparatorHovered]);
		stylesData["ImGuiCol_SliderGrab"] = RGBAToHex(style.Colors[ImGuiCol_SliderGrab]);
		stylesData["ImGuiCol_SliderGrabActive"] = RGBAToHex(style.Colors[ImGuiCol_SliderGrabActive]);
		stylesData["ImGuiCol_Tab"] = RGBAToHex(style.Colors[ImGuiCol_Tab]);
		stylesData["ImGuiCol_TabActive"] = RGBAToHex(style.Colors[ImGuiCol_TabActive]);
		stylesData["ImGuiCol_TabHovered"] = RGBAToHex(style.Colors[ImGuiCol_TabHovered]);
		stylesData["ImGuiCol_TabUnfocused"] = RGBAToHex(style.Colors[ImGuiCol_TabUnfocused]);
		stylesData["ImGuiCol_TabUnfocusedActive"] = RGBAToHex(style.Colors[ImGuiCol_TabUnfocusedActive]);
		stylesData["ImGuiCol_TableBorderLight"] = RGBAToHex(style.Colors[ImGuiCol_TableBorderLight]);
		stylesData["ImGuiCol_TableBorderStrong"] = RGBAToHex(style.Colors[ImGuiCol_TableBorderStrong]);
		stylesData["ImGuiCol_TableHeaderBg"] = RGBAToHex(style.Colors[ImGuiCol_TableHeaderBg]);
		stylesData["ImGuiCol_TableRowBg"] = RGBAToHex(style.Colors[ImGuiCol_TableRowBg]);
		stylesData["ImGuiCol_TableRowBgAlt"] = RGBAToHex(style.Colors[ImGuiCol_TableRowBgAlt]);
		stylesData["ImGuiCol_Text"] = RGBAToHex(style.Colors[ImGuiCol_Text]);
		stylesData["ImGuiCol_TextDisabled"] = RGBAToHex(style.Colors[ImGuiCol_TextDisabled]);
		stylesData["ImGuiCol_TextSelectedBg"] = RGBAToHex(style.Colors[ImGuiCol_TextSelectedBg]);
		stylesData["ImGuiCol_TitleBg"] = RGBAToHex(style.Colors[ImGuiCol_TitleBg]);
		stylesData["ImGuiCol_TitleBgActive"] = RGBAToHex(style.Colors[ImGuiCol_TitleBgActive]);
		stylesData["ImGuiCol_TitleBgCollapsed"] = RGBAToHex(style.Colors[ImGuiCol_TitleBgCollapsed]);
		stylesData["ImGuiCol_WindowBg"] = RGBAToHex(style.Colors[ImGuiCol_WindowBg]);

		stylesData["Alpha"] = style.Alpha;
		stylesData["DisabledAlpha"] = style.DisabledAlpha;
		stylesData["WindowPaddingx"] = style.WindowPadding.x;
		stylesData["WindowPaddingy"] = style.WindowPadding.y;
		stylesData["WindowRounding"] = style.WindowRounding;
		stylesData["WindowBorderSize"] = style.WindowBorderSize;
		stylesData["WindowMinSizex"] = style.WindowMinSize.x;
		stylesData["WindowMinSizey"] = style.WindowMinSize.y;
		stylesData["WindowTitleAlignx"] = style.WindowTitleAlign.x;
		stylesData["WindowTitleAligny"] = style.WindowTitleAlign.y;
		stylesData["WindowMenuButtonPosition"] = style.WindowMenuButtonPosition;
		stylesData["ChildRounding"] = style.ChildRounding;
		stylesData["ChildBorderSize"] = style.ChildBorderSize;
		stylesData["PopupRounding"] = style.PopupRounding;
		stylesData["PopupBorderSize"] = style.PopupBorderSize;
		stylesData["FramePaddingx"] = style.FramePadding.x;
		stylesData["FramePaddingy"] = style.FramePadding.y;
		stylesData["FrameRounding"] = style.FrameRounding;
		stylesData["FrameBorderSize"] = style.FrameBorderSize;
		stylesData["ItemSpacingx"] = style.ItemSpacing.x;
		stylesData["ItemSpacingy"] = style.ItemSpacing.y;
		stylesData["ItemInnerSpacingx"] = style.ItemInnerSpacing.x;
		stylesData["ItemInnerSpacingy"] = style.ItemInnerSpacing.y;
		stylesData["CellPaddingx"] = style.CellPadding.x;
		stylesData["CellPaddingy"] = style.CellPadding.y;
		stylesData["TouchExtraPaddingx"] = style.TouchExtraPadding.x;
		stylesData["TouchExtraPaddingy"] = style.TouchExtraPadding.y;
		stylesData["IndentSpacing"] = style.IndentSpacing;
		stylesData["ColumnsMinSpacing"] = style.ColumnsMinSpacing;
		stylesData["ScrollbarSize"] = style.ScrollbarSize;
		stylesData["ScrollbarRounding"] = style.ScrollbarRounding;
		stylesData["GrabMinSize"] = style.GrabMinSize;
		stylesData["GrabRounding"] = style.GrabRounding;
		stylesData["LogSliderDeadzone"] = style.LogSliderDeadzone;
		stylesData["TabRounding"] = style.TabRounding;
		stylesData["TabBorderSize"] = style.TabBorderSize;
		stylesData["TabMinWidthForCloseButton"] = style.TabMinWidthForCloseButton;
		stylesData["ColorButtonPosition"] = style.ColorButtonPosition;
		stylesData["ButtonTextAlignx"] = style.ButtonTextAlign.x;
		stylesData["ButtonTextAligny"] = style.ButtonTextAlign.y;
		stylesData["SelectableTextAlignx"] = style.SelectableTextAlign.x;
		stylesData["SelectableTextAligny"] = style.SelectableTextAlign.y;
		stylesData["DisplayWindowPaddingx"] = style.DisplayWindowPadding.x;
		stylesData["DisplayWindowPaddingy"] = style.DisplayWindowPadding.y;
		stylesData["DisplaySafeAreaPaddingx"] = style.DisplaySafeAreaPadding.x;
		stylesData["DisplaySafeAreaPaddingy"] = style.DisplaySafeAreaPadding.y;
		stylesData["MouseCursorScale"] = style.MouseCursorScale;
		stylesData["AntiAliasedLines"] = style.AntiAliasedLines;
		stylesData["AntiAliasedLinesUseTex"] = style.AntiAliasedLinesUseTex;
		stylesData["AntiAliasedFill"] = style.AntiAliasedFill;
		stylesData["CurveTessellationTol"] = style.CurveTessellationTol;
		stylesData["CircleTessellationMaxError"] = style.CircleTessellationMaxError;
		return stylesData;
	}
	static bool GroupPanelIsOpen(ImGuiID id)
	{
		ImGuiContext& g = *GImGui;
		ImGuiWindow* window = g.CurrentWindow;
		ImGuiStorage* storage = window->DC.StateStorage;

		return storage->GetInt(id, 1) != 0;
	}
	static void GroupPanelSetOpen(ImGuiID id, bool open)
	{
		ImGuiContext& g = *GImGui;
		ImGuiWindow* window = g.CurrentWindow;
		ImGuiStorage* storage = window->DC.StateStorage;

		storage->SetInt(id, open ? 1 : 0);
	}
	void AddUnderLine(ImColor col_)
	{
		ImVec2 min = ImGui::GetItemRectMin();
		ImVec2 max = ImGui::GetItemRectMax();
		min.y = max.y;
		ImGui::GetWindowDrawList()->AddLine(min, max, col_, 1.0f);
	}
	void TextURL(const char* name_, const char* URL_, bool SameLineBefore_, bool SameLineAfter_)
	{
		if (SameLineBefore_) { ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x); }
		ImGui::PushStyleColor(ImGuiCol_Text, ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
		ImGui::Text(name_);
		ImGui::PopStyleColor();
		if (ImGui::IsItemHovered())
		{
			if (ImGui::IsMouseClicked(0))
			{
				ShellExecute(0, 0, URL_, 0, 0, SW_SHOW);
			}
			AddUnderLine(ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered]);
			ImGui::SetTooltip("Open in browser: \n%s", URL_);
		}
		else
		{
			AddUnderLine(ImGui::GetStyle().Colors[ImGuiCol_Button]);
		}
		if (SameLineAfter_) { ImGui::SameLine(0.0f, ImGui::GetStyle().ItemInnerSpacing.x); }
	}
	void ShowHelpText(const char* text)
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(text);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
	void HelpMarker(const char* desc)
	{
		ImGui::TextDisabled("(?)");
		if (ImGui::IsItemHovered())
			ShowHelpText(desc);
	}
	bool BeginGroupPanel(const char* label, bool node, const ImVec2& size)
	{
		ImGuiContext& g = *GImGui;
		ImGuiWindow* window = g.CurrentWindow;

		const ImGuiID id = window->GetID(label);
		ImGui::PushID(id);

		auto groupPanelPos = window->DC.CursorPos;
		auto itemSpacing = ImGui::GetStyle().ItemSpacing;

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

		ImGui::BeginGroup(); // Outer group

		ImVec2 effectiveSize = size;
		if (size.x < 0.0f)
			effectiveSize.x = ImGui::GetContentRegionAvail().x;
		else
			effectiveSize.x = size.x;

		ImGui::Dummy(ImVec2(effectiveSize.x, 0.0f)); // Adjusting group x size

		auto frameHeight = ImGui::GetFrameHeight();
		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f)); ImGui::SameLine(0.0f, 0.0f); // Inner group spacing
		ImGui::BeginGroup(); // Inner group

		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f)); ImGui::SameLine(0.0f, 0.0f); // Name text spacing
		ImGui::TextUnformatted(label);

		ImRect leftRect = { ImGui::GetItemRectMin(), ImGui::GetItemRectMax() };
		ImVec2 rightMax = ImVec2(groupPanelPos.x + effectiveSize.x - frameHeight, leftRect.Max.y);
		ImRect rightRect = { { rightMax.x, leftRect.Min.x }, rightMax };
		ImGui::SameLine(0.0f, 0.0f);

		ImGui::Dummy(ImVec2(0.0, frameHeight + itemSpacing.y));

		if (node)
		{
			leftRect.Min.x = groupPanelPos.x;

			const ImVec2 text_size = ImGui::CalcTextSize(label);
			bool isOpen = GroupPanelIsOpen(id);

			bool hovered;
			bool toggled = ImGui::ButtonBehavior(leftRect, id, &hovered, nullptr, ImGuiButtonFlags_PressedOnClick);
			if (toggled)
			{
				isOpen = !isOpen;
				GroupPanelSetOpen(id, isOpen);
			}

			const ImU32 text_col = ImGui::GetColorU32(ImGuiCol_Text);
			ImGui::RenderArrow(window->DrawList, { groupPanelPos.x, groupPanelPos.y + text_size.y * 0.15f }, text_col,
				isOpen ? ImGuiDir_Down : ImGuiDir_Right, 0.7f);

			if (!isOpen)
			{
				ImGui::PopStyleVar(2);
				ImGui::EndGroup();
				ImGui::EndGroup();
				ImGui::PopID();

				_groupPanelStack.push_back({ leftRect, rightRect, true });
				return false;
			}
		}

		ImGui::PopStyleVar(2);

		ImGui::GetCurrentWindow()->ContentRegionRect.Max.x -= frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->WorkRect.Max.x -= frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->InnerRect.Max.x -= frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->Size.x -= frameHeight;

		auto itemWidth = ImGui::CalcItemWidth();
		ImGui::PushItemWidth(ImMax(0.0f, itemWidth - frameHeight));

		_groupPanelStack.push_back({ leftRect, rightRect, false });
		return true;
	}
	void EndGroupPanel()
	{
		IM_ASSERT(_groupPanelStack.Size > 0); // Mismatched BeginGroupPanel()/EndGroupPanel() calls
		auto& info = _groupPanelStack.back();
		_groupPanelStack.pop_back();

		if (info.collapsed)
			return;

		ImGui::PopItemWidth();

		auto itemSpacing = ImGui::GetStyle().ItemSpacing;
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

		ImGui::EndGroup(); // Inner group

		auto frameHeight = ImGui::GetFrameHeight();
		ImGui::SameLine(0.0f, 0.0f);
		ImGui::Dummy(ImVec2(frameHeight * 0.5f, 0.0f));
		ImGui::Dummy(ImVec2(0.0, frameHeight - frameHeight * 0.5f - itemSpacing.y));

		ImGui::EndGroup(); // Outer group

		// Outer group rect
		auto itemMin = ImGui::GetItemRectMin();
		auto itemMax = ImGui::GetItemRectMax();

		ImVec2 halfFrame = ImVec2(frameHeight * 0.25f, frameHeight) * 0.5f;
		ImRect frameRect = ImRect(itemMin + halfFrame, itemMax - ImVec2(halfFrame.x, 0.0f));

		auto& leftRect = info.left;
		leftRect.Min.x -= itemSpacing.x;
		leftRect.Max.x += itemSpacing.x;

		bool hasRightPart = info.right.Min.x != info.right.Max.x;
		auto& rightRect = info.right;

		if (hasRightPart)
		{
			rightRect.Min.x -= itemSpacing.x;
			rightRect.Max.x += itemSpacing.x;
		}

		// Drawing rectangle
		for (int i = 0; i < (hasRightPart ? 5 : 3); ++i)
		{
			switch (i)
			{
				// left half-plane
			case 0: ImGui::PushClipRect(ImVec2(-FLT_MAX, -FLT_MAX), ImVec2(leftRect.Min.x, FLT_MAX), true); break;
				// right half-plane
			case 1: ImGui::PushClipRect(ImVec2(leftRect.Max.x, -FLT_MAX), ImVec2(hasRightPart ? rightRect.Min.x : FLT_MAX, FLT_MAX), true); break;
				// bottom
			case 2: ImGui::PushClipRect(ImVec2(leftRect.Min.x, leftRect.Max.y), ImVec2(leftRect.Max.x, FLT_MAX), true); break;
				// bottom select
			case 3: ImGui::PushClipRect(ImVec2(rightRect.Min.x, rightRect.Max.y), ImVec2(rightRect.Max.x, FLT_MAX), true); break;
				// right hand-plane
			case 4: ImGui::PushClipRect(ImVec2(rightRect.Max.x, -FLT_MAX), ImVec2(FLT_MAX, FLT_MAX), true); break;
			}

			ImGui::GetWindowDrawList()->AddRect(
				frameRect.Min, frameRect.Max,
				ImColor(ImGui::GetStyleColorVec4(ImGuiCol_Border)),
				halfFrame.x);

			ImGui::PopClipRect();
		}

		ImGui::PopStyleVar(2);

		// Restore content region
		ImGui::GetCurrentWindow()->ContentRegionRect.Max.x += frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->WorkRect.Max.x += frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->InnerRect.Max.x += frameHeight * 0.5f;
		ImGui::GetCurrentWindow()->Size.x += frameHeight;

		// Add vertical spacing
		ImGui::Dummy(ImVec2(0.0f, 0.0f));

		ImGui::PopID();
	}
	void NextGroupPanelHeaderItem(const ImVec2& size, bool rightAlign)
	{
		IM_ASSERT(size.x > 0.0f); // Size should be specified
		IM_ASSERT(_groupPanelStack.Size > 0); // Mismatched BeginGroupPanel()/EndGroupPanel() calls
		auto& info = _groupPanelStack.back();

		ImGuiContext& g = *GImGui;
		ImGuiWindow* window = g.CurrentWindow;

		if (rightAlign)
		{
			if (info.right.Min.x != info.right.Max.x)
				info.right.Min.x -= g.Style.ItemSpacing.x;

			info.right.Min.x -= size.x;
		}
		else
			info.left.Max.x += g.Style.ItemSpacing.x;

		window->DC.CursorPos.x = rightAlign ? info.right.Min.x : info.left.Max.x;
		window->DC.CursorPos.y = info.left.Min.y - (size.y - ImGui::GetFrameHeight() + g.Style.FramePadding.y) / 2;

		if (!rightAlign)
			info.left.Max.x += size.x;
	}
	bool BeginSelectableGroupPanel(const char* label, bool& value, bool& changed, bool node, const ImVec2& size, const char* selectLabel)
	{
		bool opened = BeginGroupPanel(label, node, size);

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));

		ImGuiContext& g = *GImGui;
		const ImGuiStyle& style = g.Style;

		const ImVec2 label_size = CalcTextSize(selectLabel, NULL, true);
		const float square_sz = GetFrameHeight();
		const ImVec2 checkbox_size = ImVec2(square_sz + (label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f), label_size.y + style.FramePadding.y * 2.0f);

		NextGroupPanelHeaderItem(checkbox_size, true);
		changed = Checkbox(selectLabel, &value);

		ImGui::PopStyleVar();
		return opened;
	}
	void EndSelectableGroupPanel()
	{
		EndGroupPanel();
	}
	ImVec2 CalcButtonSize(const char* label)
	{
		const ImVec2 label_size = CalcTextSize(label, NULL, true);

		ImGuiContext& g = *GImGui;
		const ImGuiStyle& style = g.Style;
		ImVec2 size = CalcItemSize({}, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
		return size;
	}
}