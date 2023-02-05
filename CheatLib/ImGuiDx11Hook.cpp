/*
	--------------------------------------------------------
	2022-12-7 None!
	--------------------------------------------------------
*/
#include <ImGuiDx11Hook.hpp>
#include <iostream>
#include <fmt/format.h>
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace DX11Hook {
	ID3D11Device* D3D11Device = nullptr;
	ID3D11DeviceContext* D3D11DeviceContext;
	ID3D11RenderTargetView* D3D11RenderTargetView;
	typedef HRESULT(__stdcall* IDXGISwapChainPresent)(IDXGISwapChain* SwapChain, UINT SyncInterval, UINT Flags);
	static IDXGISwapChainPresent fnIDXGISwapChainPresent;
	struct ImGuiInfo {
		unsigned char* Font;
		float FontSize;
		HMODULE Module;
		void (*Drawing)();
		std::string ImGuiInIFile;
		bool CanReturn = false;
		IDXGISwapChain* SwapChain;
	}Info;
	static WNDPROC OriginalWndProcHandler;
	static BOOL g_bInitialised = false;
	static LRESULT CALLBACK hWndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		ImGuiIO& io = ImGui::GetIO();
		POINT mPos;
		GetCursorPos(&mPos);
		ScreenToClient(hwnd, &mPos);
		ImGui::GetIO().MousePos.x = static_cast<float>(mPos.x);
		ImGui::GetIO().MousePos.y = static_cast<float>(mPos.y);

		ImGui_ImplWin32_WndProcHandler(hwnd, Msg, wParam, lParam);

		short key;
		bool keyUpEvent = true;
		switch (Msg)
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
			key = GET_XBUTTON_WPARAM(wParam) == XBUTTON1 ? VK_XBUTTON1 : VK_XBUTTON2;
			break;
		case WM_KEYUP:
			key = static_cast<short>(wParam);
			break;
		default:
			keyUpEvent = false;
			break;
		}

		if (ImGui::GetInPutLock())
			return true;

		return CallWindowProc(OriginalWndProcHandler, hwnd, Msg, wParam, lParam);
	}
	static HRESULT __stdcall Present_Hook(IDXGISwapChain* pChain, const UINT SyncInterval, const UINT Flags)
	{
		if (!g_bInitialised)
		{
			auto result = (HRESULT)pChain->GetDevice(__uuidof(D3D11Device), reinterpret_cast<void**>(&D3D11Device));
			if (SUCCEEDED(result))
			{
				Info.SwapChain = pChain;
				D3D11Device->GetImmediateContext(&D3D11DeviceContext);
				DXGI_SWAP_CHAIN_DESC sd;
				pChain->GetDesc(&sd);
				ImGui::CreateContext();
				ImPlot::CreateContext();
				ImNodes::CreateContext();
				ImGuiIO& io = ImGui::GetIO(); (void)io;
				io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
				if (Info.Font != nullptr)
				{
					io.Fonts->AddFontFromMemoryTTF(Info.Font, sizeof(Info.Font), Info.FontSize, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				else
				{
					io.Fonts->AddFontFromMemoryTTF(Font::getallfont(), sizeof(Font::getallfont()), Info.FontSize, NULL, io.Fonts->GetGlyphRangesChineseFull());
				}
				if (Info.ImGuiInIFile == "")
				{
					static const std::string imguiPath = std::string(Process::GetModuleFile(Info.Module) + "\\imgui.ini");
					io.IniFilename = imguiPath.c_str();
				}
				else
				{
					static const std::string imguiPath = Info.ImGuiInIFile;
					io.IniFilename = imguiPath.c_str();
				}
				io.SetPlatformImeDataFn = nullptr; // F**king bug take 4 hours of my life
				ImGui::StyleColorsDark();
				//Set OriginalWndProcHandler to the Address of the Original WndProc function
				OriginalWndProcHandler = reinterpret_cast<WNDPROC>(SetWindowLongPtr(sd.OutputWindow, GWLP_WNDPROC,
					reinterpret_cast<LONG_PTR>(hWndProc)));
				ImGui_ImplWin32_Init(sd.OutputWindow);
				ImGui_ImplDX11_Init(D3D11Device, D3D11DeviceContext);
				ID3D11Texture2D* pBackBuffer;
				pChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer));
				D3D11Device->CreateRenderTargetView(pBackBuffer, nullptr, &D3D11RenderTargetView);
				pBackBuffer->Release();
				io.SetPlatformImeDataFn = nullptr;
				g_bInitialised = true;
				Info.CanReturn = g_bInitialised;
			}
		}
		if (g_bInitialised) {
			ImGui_ImplDX11_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGuiIO& io = ImGui::GetIO(); (void)io;
			ImGui::NewFrame();
			Info.Drawing();
			ImGui::EndFrame();
			ImGui::Render();
			D3D11DeviceContext->OMSetRenderTargets(1, &D3D11RenderTargetView, nullptr);
			ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
		}
		return fnIDXGISwapChainPresent(pChain, SyncInterval, Flags);
	}
	static IDXGISwapChainPresent findDirect11Present()
	{
		WNDCLASSEX wc{ 0 };
		wc.cbSize = sizeof(wc);
		wc.lpfnWndProc = DefWindowProc;
		wc.lpszClassName = TEXT("Class");

		if (!RegisterClassEx(&wc))
		{
			return nullptr;
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

			return nullptr;
		}
		const DWORD_PTR* pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChain);
		pSwapChainVtable = reinterpret_cast<DWORD_PTR*>(pSwapChainVtable[0]);

		auto swapChainPresent = reinterpret_cast<IDXGISwapChainPresent>(pSwapChainVtable[8]);

		pDevice->Release();
		pContext->Release();
		pSwapChain->Release();
		DestroyWindow(swapChainDesc.OutputWindow);
		UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));

		return swapChainPresent;
	}
	bool installDX11Hook(void(*Drawing)(), HMODULE Module, std::string ImGuiInIFile, float FontSize, unsigned char* Font, ID3D11Device** DX11D3D11Device, ID3D11DeviceContext** DX11D3D11DeviceContext, ID3D11RenderTargetView** DX11D3D11RenderTargetView, IDXGISwapChain** DX11SwapChain) {
		Info.Font = Font;Info.FontSize = FontSize;Info.Drawing = Drawing;Info.Module = Module;Info.ImGuiInIFile = ImGuiInIFile;
		fnIDXGISwapChainPresent = findDirect11Present();
		if (fnIDXGISwapChainPresent == nullptr)
		{
			return false;
		}
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)fnIDXGISwapChainPresent, Present_Hook);
		DetourTransactionCommit();
		while (!g_bInitialised)
		{ 
			Sleep(1);
		}
		try
		{
			*DX11D3D11Device = D3D11Device;
			*DX11D3D11DeviceContext = D3D11DeviceContext;
			*DX11D3D11RenderTargetView = D3D11RenderTargetView;
			*DX11SwapChain = Info.SwapChain;
		}
		catch (...)
		{
			LOGERROR("Point Address is NULL\n");
		}
		LOGDEBUG(fmt::format("D3D11Device:{}\n", (INT64)D3D11Device));
		LOGDEBUG(fmt::format("D3D11DeviceContext:{}\n", (INT64)D3D11DeviceContext));
		LOGDEBUG(fmt::format("D3D11RenderTargetView:{}\n", (INT64)D3D11RenderTargetView));
		LOGDEBUG(fmt::format("SwapChain:{}\n", (INT64)Info.SwapChain));
		return true;
	}
	bool uninstallDX11Hook() {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)fnIDXGISwapChainPresent, Present_Hook);
		DetourTransactionCommit();
		return true;
	}
}