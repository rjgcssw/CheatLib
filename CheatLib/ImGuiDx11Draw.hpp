#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <dwmapi.h>
#include <ImGuiEX.hpp>
#include <Console.hpp>
#include <process.hpp>
#include <Font.h>
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "User32.lib")
#pragma comment (lib, "Gdi32.lib")
#pragma comment (lib, "shlwapi.lib")
#pragma comment (lib, "D3dcompiler.lib")
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "dxgi.lib")
namespace ImGuiDraw {
	HWND CreateImGuiDx11Draw(void(*Drawing)(), HMODULE Module, std::string ImGuiInIFile, float FontSize, unsigned char* Font, ImVec2 WindowsSize, ImVec4 clear_color, bool transparent, bool vsync, ID3D11Device** DX11D3D11Device, ID3D11DeviceContext** DX11D3D11DeviceContext, ID3D11RenderTargetView** DX11D3D11RenderTargetView, IDXGISwapChain** DX11SwapChain);
}