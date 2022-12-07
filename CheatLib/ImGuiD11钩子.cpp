/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <Windows.h>
#include <string>
#include <detours.h>
#include <dwmapi.h>
#include <ImGuiD11钩子.hpp>
#include <imgui_impl_win32.h>
#include <imgui_impl_dx11.h>
#include <控制台.h>
#include <imgui.h>
#include <implot.h>
#include <imnodes.h>
#include <ImGui扩展.hpp>
#include <进程.hpp>
#include <Font.h>
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "User32.lib")
#pragma comment (lib, "Gdi32.lib")
#pragma comment (lib, "shlwapi.lib")
#if _WIN32
#pragma comment (lib,"detours-x86.lib")
#else
#pragma comment (lib,"detours-x64.lib")
#endif
namespace DX11钩子 {
	ID3D11Device* 设备指针 = nullptr;
	ID3D11DeviceContext* 设备描述;
	ID3D11RenderTargetView* 主渲染目标视图;
	typedef HRESULT(__stdcall* IDXGISwapChainPresent)(IDXGISwapChain* 交换链, UINT 同步间隔, UINT 属性);
	static IDXGISwapChainPresent fnIDXGISwapChainPresent;
	struct ImGui属性 {
		unsigned char* 字体;
		float 字体大小;
		HMODULE 模块句柄;
		void (*绘制循环)();
		std::string ImGui配置目录;
		bool 可以返回 = false;
		IDXGISwapChain* 交换链;
	}属性;
	extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static WNDPROC OriginalWndProcHandler;
	static LRESULT CALLBACK hWndProc(HWND 窗口句柄, UINT 消息, WPARAM 状态, LPARAM 客户区)
	{
		ImGuiIO& io = ImGui::GetIO();
		POINT mPos;
		GetCursorPos(&mPos);
		ScreenToClient(窗口句柄, &mPos);
		ImGui::GetIO().MousePos.x = static_cast<float>(mPos.x);
		ImGui::GetIO().MousePos.y = static_cast<float>(mPos.y);

		ImGui_ImplWin32_WndProcHandler(窗口句柄, 消息, 状态, 客户区);

		short key;
		bool keyUpEvent = true;
		switch (消息)
		{
		case WM_LBUTTONUP:
			key = VK_LBUTTON;
			break;
		case WM_RBUTTONUP:
			key = VK_RBUTTON;
			break;
		case WM_MBUTTONUP:
			key = VK_MBUTTON;
			break;
		case WM_XBUTTONUP:
			key = GET_XBUTTON_WPARAM(状态) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
			break;
		case WM_KEYUP:
			key = static_cast<short>(状态);
			break;
		default:
			keyUpEvent = false;
			break;
		}

		if (ImGui::输入锁状态())
			return true;

		return CallWindowProc(OriginalWndProcHandler, 窗口句柄, 消息, 状态, 客户区);
	}
	static HRESULT __stdcall Present_Hook(IDXGISwapChain* pChain, const UINT SyncInterval, const UINT Flags)
	{
		static BOOL g_bInitialised = false;
		if (!g_bInitialised)
		{
			auto result = (HRESULT)pChain->GetDevice(__uuidof(设备指针), reinterpret_cast<void**>(&设备指针));
			if (SUCCEEDED(result))
			{
				属性.交换链 = pChain;
				设备指针->GetImmediateContext(&设备描述);
				输出调试("GetImmediateContext\n");
				DXGI_SWAP_CHAIN_DESC sd;
				pChain->GetDesc(&sd);
				输出调试("GetDesc\n");
				ImGui::CreateContext();
				输出调试("ImGui::CreateContext\n");
				ImPlot::CreateContext();
				输出调试("ImGui::CreateContext\n");
				ImNodes::CreateContext();
				输出调试("ImNodes::CreateContext\n");
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
				if (属性.字体 != nullptr)
				{
					io.Fonts->AddFontFromMemoryTTF(属性.字体, sizeof(属性.字体), 属性.字体大小, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				else
				{
					io.Fonts->AddFontFromMemoryTTF(Font::getallfont(), sizeof(Font::getallfont()), 属性.字体大小, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				if (属性.ImGui配置目录 == "")
				{
					io.IniFilename = std::string(进程::取模块路径(属性.模块句柄) + "\\imgui.ini").c_str();
				}
				else
				{
					io.IniFilename = 属性.ImGui配置目录.c_str();
				}
				ImGui::默认主题();
				//Set OriginalWndProcHandler to the Address of the Original WndProc function
				OriginalWndProcHandler = reinterpret_cast<WNDPROC>(SetWindowLongPtr(sd.OutputWindow, GWLP_WNDPROC,
					reinterpret_cast<LONG_PTR>(hWndProc)));
				ImGui_ImplWin32_Init(sd.OutputWindow);
				ImGui_ImplDX11_Init(设备指针, 设备描述);
				ID3D11Texture2D* pBackBuffer;
				pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer));
				设备指针->CreateRenderTargetView(pBackBuffer, nullptr, &主渲染目标视图);
				pBackBuffer->Release();
				io.SetPlatformImeDataFn = nullptr;
				g_bInitialised = true;
				属性.可以返回 = g_bInitialised;
			}
		}
		if (g_bInitialised)
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::NewFrame();
			属性.绘制循环();
			ImGui::EndFrame();
			ImGui::Render();
			设备描述->OMSetRenderTargets(1, &主渲染目标视图, nullptr);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		return fnIDXGISwapChainPresent(pChain, SyncInterval, Flags);
	}
	bool 安装DX11钩子(void (*绘制循环)(), HMODULE 模块句柄, std::string ImGui配置目录, float 字体大小, unsigned char* 字体, ID3D11Device* DX11设备指针, ID3D11DeviceContext* DX11设备描述, ID3D11RenderTargetView* DX11主渲染目标视图, IDXGISwapChain* DX11交换链) {
		属性.字体 = 字体;属性.字体大小 = 字体大小;属性.绘制循环 = 绘制循环;属性.模块句柄 = 模块句柄;属性.ImGui配置目录 = ImGui配置目录;
		WNDCLASSEX wc{ 0 };
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = DefWindowProc;
		wc.lpszClassName = TEXT("Class");
		if (!RegisterClassEx(&wc))
		{
			输出错误("RegisterClassEx 错误\n");
			return false;
		}
		HWND hWnd = CreateWindow(wc.lpszClassName, TEXT(""), WS_DISABLED, 0, 0, 0, 0, NULL, NULL, NULL, nullptr);
		IDXGISwapChain* pSwapChain;
		D3D_FEATURE_LEVEL featureLevel;
		DXGI_SWAP_CHAIN_DESC swapChainDesc;
		ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
		swapChainDesc.BufferCount = 1;
		swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.OutputWindow = hWnd;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.Windowed = TRUE;  //((GetWindowLong(hWnd, GWL_STYLE) & WS_POPUP) != 0) ? FALSE : TRUE;
		swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		// Main D3D11 Objects
		ID3D11DeviceContext* pContext = nullptr;
		ID3D11Device* pDevice = nullptr;
		if (FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, 0, nullptr, 1, D3D11_SDK_VERSION,
			&swapChainDesc, &pSwapChain, &pDevice, &featureLevel, &pContext)) &&
			FAILED(D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION,
				&swapChainDesc, &pSwapChain, &pDevice, &featureLevel, &pContext)))
		{
			DestroyWindow(swapChainDesc.OutputWindow);
			UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
			输出错误("D3D11CreateDeviceAndSwapChain 错误\n");
			return false;
		}
		const DWORD_PTR* pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChain);
		pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChainVtable[0]);
		auto swapChainPresent = reinterpret_cast<IDXGISwapChainPresent>(pSwapChainVtable[8]);
		pDevice->Release();
		pContext->Release();
		pSwapChain->Release();
		DestroyWindow(swapChainDesc.OutputWindow);
		UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
		if (swapChainPresent == nullptr)
		{
			输出错误("未发现DX11Present!\n");
			return false;
		}
		DetourTransactionBegin();
		输出调试("DetourTransactionBegin\n");
		DetourUpdateThread(GetCurrentThread());
		输出调试("DetourUpdateThread\n");
		DetourAttach(&(PVOID&)swapChainPresent, Present_Hook);
		输出调试("DetourAttach\n");
		DetourTransactionCommit();
		输出调试("DetourUpdateThread\n");
		while (!属性.可以返回){DX11设备指针 = 设备指针; DX11设备描述 = 设备描述; DX11主渲染目标视图 = 主渲染目标视图; DX11交换链 = 属性.交换链;}
	}
}