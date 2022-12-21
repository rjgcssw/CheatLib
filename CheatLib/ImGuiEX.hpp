#include <Windows.h>
#include <string>
#include <json.hpp>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <implot.h>
#include <implot_internal.h>
#include <imnodes.h>
#include <imnodes_internal.h>

#define PI 3.14159265358979323846f
namespace ImGui {
	struct GroupPanelHeaderBounds
	{
		ImRect left;
		ImRect right;
		bool collapsed;
	};
	enum class OutlineSide : uint32_t
	{
		Left = 1,
		Right = 2,
		Top = 4,
		Bottom = 8,
		All = Left | Right | Top | Bottom
	};
	void DrawOffscreenArrows(float x, float y, float z, const ImColor& color, float OutlineThickness, float TracerSize, float ArrowRadius);
	ImU32 GetTeamColor(unsigned long Team, unsigned long A);
	void DefaultTheme();
	ImVec4 HexToRGBA(std::string Hex);
	std::string RGBAToHex(ImVec4& color);
	bool GetInPutLock();
	void SetInPutLock(void* This, bool value);
	bool operator&(OutlineSide lhs, OutlineSide rhs);
	static ImVector<GroupPanelHeaderBounds> _groupPanelStack;
	static bool GroupPanelIsOpen(ImGuiID id);
	static void GroupPanelSetOpen(ImGuiID id, bool open);
	void AddUnderLine(ImColor col_);
	void TextURL(const char* name_, const char* URL_, bool SameLineBefore_, bool SameLineAfter_);
	void ShowHelpText(const char* text);
	void HelpMarker(const char* desc);
	bool BeginGroupPanel(const char* label, bool node, const ImVec2& size);
	void EndGroupPanel();
	void NextGroupPanelHeaderItem(const ImVec2& size, bool rightAlign);
	bool BeginSelectableGroupPanel(const char* label, bool& value, bool& changed, bool node, const ImVec2& size, const char* selectLabel);
	void EndSelectableGroupPanel();
	ImVec2 CalcButtonSize(const char* label);
	nlohmann::json GetCurrentStyles(ImGuiStyle style);
	void AnemoTheme();
	ImGuiStyle ShowThemeSetting();
	ImGuiStyle OutCurrentStyles(nlohmann::json stylesData);
	float CalcWidth(const std::string_view& view);
	void DrawTextWithOutline(ImDrawList* drawList, ImFont* font, float fontSize, const ImVec2& screenPos, const char* text, const ImColor& textColor, float outlineThickness, OutlineSide sides, const ImColor& outlineColor);
	void DrawTextWithOutline(ImDrawList* drawList, const ImVec2& screenPos, const char* text, const ImColor& textColor, float outlineThickness, OutlineSide sides, const ImColor& outlineColor);
}